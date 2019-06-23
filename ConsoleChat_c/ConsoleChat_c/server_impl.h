
/**
* Main server funcion (service entry-point)
*/
int start_server(char * port);

///////// AUXILIARY FUNCTION

/**
* Handle the Ctrl+C termination.
*/
void handle_signal(int signal);

/**
* Returns the next free client slot. A new thread will be initiated for this client
*/
struct client_info * nextFreeClientSlot();

/**
* Keeps conversation to a client. This is used as the entry point for each client handler thread.
*/
unsigned long __stdcall client_handler_function (void * arg);

/**
* Sends a message to the specified client, or a broadcast the first arg is NULL.
* If the sender arg is NULL, the sender is the server itself.
*/
void sendAMessage(struct client_info *target, struct client_info *sender, char * msgbuff, int includeRecipients);
