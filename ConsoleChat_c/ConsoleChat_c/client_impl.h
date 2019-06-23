
int start_client(char * server_host, char * identification);



/**
* Handles the user's input in a separate thread, while the main thread
* is receiving the data from server.
*/
unsigned long __stdcall servermsg_handler_function (void * arg);

/**
* Sends a message to the specified server.
*/
int sendAMessageToServer(char * msgbuff);

/**
* Handles the system messages.
*/
void handle_signal_client(int sig_num);