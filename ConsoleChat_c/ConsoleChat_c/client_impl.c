#define _CRT_SECURE_NO_DEPRECATE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#include "client_impl.h"

#define HOST_BUFFER_LEN  30
#define MESSAGE_BUFFER_LEN 60

#define SERVER_HELLO_MESSAGE "[[[HELLO]]]"
#define SERVER_CHATFULL_MESSAGE "[[[CHAT_FULL]]]"


int client_sock = 0;
int client_running;

int start_client(char * server_host, char * identification) {

    char port[6];
    char host[HOST_BUFFER_LEN + 1];

    char msgbuff[1000];

    struct addrinfo hints;
    struct addrinfo * serv_host_ptr;

    WSADATA winsock_info;
    int winsock_init_retcode;
    int general_retcode;
	char * inputread_retcode;
    int read_count;

    HANDLE input_thread_handle;

    /* ********************************
    * Begin
    */

    /*
    * Extract the PORT from the host address (after the collon : )
    */
    char * separator = strchr(server_host, ':');
    strcpy(port, separator + 1*sizeof(char));
    if (separator - server_host > HOST_BUFFER_LEN) {
        fprintf(stderr, "Host buffer exceeded. Max=%d\n", HOST_BUFFER_LEN);
        exit(1);
    }
    memset(host, 0, sizeof(host));
    memcpy(host, server_host, (separator - server_host));

    printf("Starting client on host = %s , port = %s\n", host, port);

    /*
    * Winsock and socket initialization
    */
    winsock_init_retcode = WSAStartup(MAKEWORD(2,0), &winsock_info);
    if (winsock_init_retcode != 0) {
        fprintf(stderr, "Cannot initialize Winsock! Error=%d\n", winsock_init_retcode);
        exit(1);
    }
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        fprintf(stderr, "Cannot create socket! Error=%d\n", WSAGetLastError());
        exit(1);
    }

    /*
    * GetAddrInfo and Connect
    */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    general_retcode = getaddrinfo(host, port, &hints, &serv_host_ptr);
    if (general_retcode != 0) {
        fprintf(stderr, "Cannot get addrinfo! Error=%d\n", WSAGetLastError());
        closesocket(client_sock);
        exit(1);
    }

    general_retcode = connect(client_sock, serv_host_ptr->ai_addr, sizeof(struct sockaddr));
    if (general_retcode != 0) {
        fprintf(stderr, "Cannot connect to host! Error=%d\n", WSAGetLastError());

        freeaddrinfo(serv_host_ptr);
        closesocket(client_sock);
        exit(1);
    }

    /*
    * Answers to the HELLO message
    */
    read_count = recv(client_sock, msgbuff, sizeof(msgbuff), 0);
    if (read_count <= 0) {
        fprintf(stderr, "No data received from server");
        freeaddrinfo(serv_host_ptr);
        closesocket(client_sock);
        return 1;
    }

	if (strncmp(msgbuff, SERVER_CHATFULL_MESSAGE, strlen(SERVER_CHATFULL_MESSAGE)) == 0) {
		fprintf(stderr, "The room is full");
        freeaddrinfo(serv_host_ptr);
        closesocket(client_sock);
        return 1;
	}
    if (strncmp(msgbuff, SERVER_HELLO_MESSAGE, strlen(SERVER_HELLO_MESSAGE)) != 0) {
        fprintf(stderr, "Communication error. Was expecting a Hello message");
        freeaddrinfo(serv_host_ptr);
        closesocket(client_sock);
        return 1;
    }

	signal(SIGINT, handle_signal_client);

    if (sendAMessageToServer(identification)) {
        // Start exchanging messages
        client_running = TRUE;

		input_thread_handle = CreateThread(
								0, 0, 
								servermsg_handler_function, 
								NULL, 0, 
								NULL);

        while(client_running) {
			inputread_retcode = fgets(msgbuff, MESSAGE_BUFFER_LEN, stdin);
//TODO Handle Buffer overflow.
			if (inputread_retcode != NULL && msgbuff[0] != '\n')
			{
				sendAMessageToServer(msgbuff);
			}
        }
    }

	WaitForMultipleObjects(1, &input_thread_handle, TRUE, INFINITE);

    freeaddrinfo(serv_host_ptr);
    closesocket(client_sock);

    return 0;
}

/**
* See the declaration
*/
int sendAMessageToServer(char * msgbuff) {
    int retcode;

    retcode = send(client_sock, msgbuff, strlen(msgbuff)*sizeof(char), 0);
    if (retcode < 0) {
        fprintf(stderr, ">>ERROR\nCannot send data! Error=%d\n", WSAGetLastError());
        return FALSE;
    }

    return TRUE;
}

DWORD WINAPI servermsg_handler_function (void * param) {
	int read_count;
	char msgbuff[MESSAGE_BUFFER_LEN];
	char *separator1,*separator2;

    while(client_running) {
        read_count = recv(client_sock, msgbuff, MESSAGE_BUFFER_LEN-1, 0);
		if (read_count <= 0) {
			fprintf(stderr, "::: The connection is closed\n");
			client_running = FALSE;
		} else if (read_count >= (MESSAGE_BUFFER_LEN - 1)){
			fprintf(stderr, "Insufficient buffer");
		} else {
			// A regular message has the following format:
			// SENDER_NAME|TARGET_NAME|msg
			// If it contains the two separators, we split the fields. Otherwise, show unformatted.
			msgbuff[read_count] = 0;
			separator1 = strchr(msgbuff, '|');
			if (separator1) {
				separator2 = strchr(separator1 + 1, '|');
			} else {
				separator2 = NULL;
			}

			if (separator1 && separator2) {
				*separator1 = 0; //Replace separators with string terminators
				*separator2 = 0;
				printf("::: From: %s   To: %s>\n%s\n\n", msgbuff, separator1+1, separator2+1);
			} else {
				printf(":: %s\n", msgbuff);
			}
		}
    }

	return 0;
}

void handle_signal_client(int sig_num)
{
	printf("[System] Signal received: %d\n", sig_num);
	client_running = FALSE;
}
