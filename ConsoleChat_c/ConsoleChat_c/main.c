#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server_impl.h"
#include "client_impl.h"

#define _CRT_SECURE_NO_WARNINGS 

int main(int argc, char ** argv)
{
	if (argc == 3 && strncmp(argv[1], "server", 6) == 0) {
        return start_server(argv[2]);

    } else if (argc == 4 && strncmp(argv[1], "client", 6) == 0
                && strchr(argv[2], ':') != NULL) {
        return start_client(argv[2], argv[3]);

    } else {
        printf("Usage:\n  Running as server:  %s server [PORT]\n  Running as client:  %s client [HOST:PORT] [IDENTIFICATION]\n", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }
}
