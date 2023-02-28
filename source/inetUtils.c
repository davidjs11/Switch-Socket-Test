#include "inetUtils.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

struct socketInfo resolveHost(char *ip, int port)
{
    struct socketInfo server;
    memset(&server, 0, sizeof(server));

    // create server socket
    server.socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server.socket < 0) {
	perror("[-] initServer in socket()");
	memset(&server, 0, sizeof(server));
	return server;
    }

    // set address info
    server.address.sin_family = AF_INET;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = inet_addr(ip);

    return server;
}


int initServer(struct socketInfo *server)
{
    // bind server address to the socket
    int tmp = bind(server->socket, (struct sockaddr *) &(server->address),
	       sizeof(server->address));
    if (tmp < 0) {
	perror("[-] initServer in bind()");
	memset(server, 0, sizeof(*server));
	return -1;
    }

    return 0;
}

int getMessage(struct socketInfo *receiver, struct socketInfo *sender, char *buffer, int bufferSize)
{
    int tmp;
    memset(buffer, 0, bufferSize);
    sender->size = sizeof(sender->address);

    tmp = recvfrom(receiver->socket, buffer, bufferSize, 0, (struct sockaddr *) &(sender->address),
	    &(sender->size));
    return tmp;
}

int sendMessage(struct socketInfo *receiver, struct socketInfo *sender, char *buffer, int bufferSize)
{
   int tmp;

   tmp = sendto(sender->socket, buffer, bufferSize, 0, (struct sockaddr *) &(receiver->address),
		sizeof(receiver->address));

   return tmp;
}
