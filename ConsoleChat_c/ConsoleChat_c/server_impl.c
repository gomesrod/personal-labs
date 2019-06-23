#define _CRT_SECURE_NO_DEPRECATE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <winerror.h>

#include "server_impl.h"

#define MAX_CONNECTED_CLIENTS 3
#define MESSAGE_BUFFER_LEN 60
#define MAX_NAME_LEN 15
#define SERVER_HELLO_MESSAGE "[[[HELLO]]]"
#define SERVER_CHATFULL_MESSAGE "[[[CHAT_FULL]]]"

/**
* Information about a client handled by a worker thread
*/
struct client_info {
    int index;
    int cliconn_sock;
    char name[MAX_NAME_LEN + 1];

    int is_running; // Tells if this client is active. Also used to issue a stop command.
};

int listen_sock;
int is_running = TRUE;

struct client_info clients[MAX_CONNECTED_CLIENTS];
HANDLE client_threads_handle[MAX_CONNECTED_CLIENTS];

struct timeval inputsock_poll_timeout;


int start_server(char * port_str) {
    short listenport;

    struct sockaddr_in serv_addr;

    struct sockaddr_in cli_addr;
    int cli_addr_size;
    int tmp_cli_sock;

    char msgbuff[MESSAGE_BUFFER_LEN];

    WSADATA winsock_info;

    int retcode; // return code for common use.
    int i; // a general-purpose index.

	struct client_info* cli_slot;
    //////////////// BEGIN /////////////////////

    // Parsing the PORT parameter
    listenport = atoi(port_str);
    printf("Starting server on port %d\n", listenport);

    // Initializing client info slots
    for (i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
        clients[i].index = i;
        clients[i].is_running = FALSE;
    }

    // Initializing the socket
    retcode = WSAStartup(MAKEWORD(2,0), (LPWSADATA)&winsock_info);
    if (retcode != 0) {
        sprintf(msgbuff, "Cannot initialize Winsock! Error=%d\n", retcode);
        fwrite(msgbuff, strlen(msgbuff), sizeof(char), stderr);
        exit(1);
    }
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        sprintf(msgbuff, "Cannot create socket! Error=%d\n", WSAGetLastError());
        fwrite(msgbuff, strlen(msgbuff), sizeof(char), stderr);
        exit(1);
    }

    // Other initialization stuff
    inputsock_poll_timeout.tv_usec = 1000; //1ms

    // Binding and Listening.
    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(listenport);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        retcode = WSAGetLastError();
        if (retcode == WSAEADDRINUSE) {
            sprintf(msgbuff, "Error: address in use");
        } else {
            sprintf(msgbuff, "Cannot bind to port (%d), error(%d)\n", listenport, retcode);
        }
        fwrite(msgbuff, strlen(msgbuff), sizeof(char), stderr);
        exit(1);
    }

    listen(listen_sock, 10);

    /* Socket setup completed. Now we create the signal handlers and start
       serving clients */
    signal(SIGINT, handle_signal);

    while(is_running) {
        cli_addr_size = sizeof(cli_addr);
        tmp_cli_sock = accept((SOCKET)listen_sock, (struct sockaddr *)&cli_addr, &cli_addr_size);
        if (tmp_cli_sock < 0) {
            retcode = WSAGetLastError();
            if (retcode == WSAEINTR) {
                sprintf(msgbuff, "receive() Interrupted.\n");
            } else {
                sprintf(msgbuff, "Cannot accept client connection! Error=%d\n", WSAGetLastError());
            }
            fwrite(msgbuff, strlen(msgbuff), sizeof(char), stderr);
            exit(1);
        }

        cli_slot = nextFreeClientSlot();
        if (cli_slot == NULL) {
            sprintf(msgbuff, SERVER_CHATFULL_MESSAGE);
            send(tmp_cli_sock, msgbuff, strlen(msgbuff)*sizeof(char), 0);
        } else {
            cli_slot->cliconn_sock = tmp_cli_sock;
            cli_slot->is_running = TRUE;

			client_threads_handle[cli_slot->index] = CreateThread(
												0, 0, 
												client_handler_function, 
												(void *)cli_slot, 0, 
												NULL);
        }
    }

    return 0;
}

/**
* See the declaration.
*/
void handle_signal(int sig) {
	int i;

	switch (sig)
	{
	case SIGINT:
		printf("*** Interrupt signal received.\n");

		//send(cliconn_sock, "*** Server Terminated", 21, 0);
		is_running = FALSE;

		// Free system resources
		for (i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
			clients[i].is_running = FALSE;
		}

		printf("Waiting for threads to finish...\n");
		WaitForMultipleObjects(MAX_CONNECTED_CLIENTS, client_threads_handle, TRUE, 5000);

		closesocket(listen_sock);
		WSACleanup();

	}
}

/**
* See the declaration
*/
struct client_info * nextFreeClientSlot() {
    int i;
    for (i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
        if (clients[i].is_running == FALSE) {
            return &clients[i];
        }
    }
    return NULL;
}

/**
* See the declaration
*/
void sendAMessage(struct client_info *target, struct client_info *sender, char * msgbuff, int includeRecipients) {
    int retcode;
    int i;
	char formattedMsgBuff[MESSAGE_BUFFER_LEN + MAX_NAME_LEN*2 + 3];

    // The actual target. When the "target" parameter is not null, this will point to
    // the same object. When a target is not specified (broadcast message), this
    // will point to the whole client array.
    struct client_info *actual_target;
    int target_len;

    if (target == NULL) {
        actual_target = clients;
        target_len = MAX_CONNECTED_CLIENTS;
    } else {
        actual_target = target;
        target_len = 1;
    }

	if (includeRecipients)
	{
		sprintf(formattedMsgBuff, "%s|%s|%s", 
							sender != NULL ? sender->name : "(SERVER)",
							target != NULL ? target->name : "ALL",
							msgbuff);
	}
	else
	{
		// Raw message - do not include recipients - reserved for protocol-messages
		sprintf(formattedMsgBuff, msgbuff);
	}

    for (i = 0; i < target_len; i++) {
        if (actual_target[i].is_running && &actual_target[i] != sender) {
            retcode = send(actual_target[i].cliconn_sock, formattedMsgBuff, strlen(formattedMsgBuff)*sizeof(char), 0);
            if (retcode == SOCKET_ERROR) {
                printf("Cannot send data! Thread=%d Error=%d\n", actual_target->index, WSAGetLastError());
            }
		}
    }
}

/**
* See the declaration
*/
DWORD WINAPI client_handler_function (void * arg) {
    char msgbuff[MESSAGE_BUFFER_LEN];

    struct client_info *cli_info = (struct client_info *)arg;
	struct client_info *msg_target;
	int msg_offset;

    fd_set readfds;
    int read_count;
	int i;

    // The HELLO Message must be answered with the client name
    sendAMessage(cli_info, NULL, SERVER_HELLO_MESSAGE, FALSE);

    read_count = recv(cli_info->cliconn_sock, msgbuff, sizeof(msgbuff), 0);

    if (read_count == 0) {
        // This client is gone
        cli_info->is_running = FALSE;
    } else if (read_count > MAX_NAME_LEN) {
        sendAMessage(cli_info, NULL, "Please connect with a shorter name", TRUE);
        cli_info->is_running = FALSE;
    } else {
        strncpy(cli_info->name, msgbuff, read_count);
        printf(":: New Client on thread %d identified as [%s]\n", cli_info->index, cli_info->name);

        sprintf(msgbuff, "Hello, %s", cli_info->name);
        sendAMessage(cli_info, NULL, msgbuff, TRUE);

		sprintf(msgbuff, ":: %s has joined\n", cli_info->name);
        sendAMessage(NULL, cli_info, msgbuff, TRUE);
    }

    while(cli_info->is_running) {
        readfds.fd_array[0] = cli_info->cliconn_sock;
        readfds.fd_count = 1;

        if (select(0, &readfds, NULL, NULL, &inputsock_poll_timeout) > 0) {
            read_count = recv(cli_info->cliconn_sock, msgbuff, MESSAGE_BUFFER_LEN-1, 0);
            if (read_count <= 0) {
                printf("Client %s has left.\n", cli_info->name);
                cli_info->is_running = FALSE;
            } else if (read_count == MESSAGE_BUFFER_LEN-1) {
				fprintf(stderr, "[ERROR] Insufficient buffer to hold message from %s!\n", cli_info->name);

			} else {
				msgbuff[read_count] = 0;
				msg_target = NULL;
				msg_offset = 0;

				//If the message is formatted as "@user text" we try to find a specific user
				// and send the message only to this one.
				if(msgbuff[0] == '@') {
					for(i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
						if(strncmp(clients[i].name, msgbuff+1, strlen(clients[0].name)) == 0) {
							msg_target = &clients[i];
							msg_offset = strlen(clients[i].name) + 1;
							break;
						}
					}
				}

				sendAMessage(msg_target,cli_info, msgbuff + msg_offset, TRUE);
            }
        }

        Sleep(10);
    }

    closesocket(cli_info->cliconn_sock);

    return 0;
}


