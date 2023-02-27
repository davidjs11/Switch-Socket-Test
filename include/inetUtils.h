////////////////////////////////////////////////
/// inetUtils: internet connection utilities ///
////////////////////////////////////////////////

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

// server side functions
int initServerSocket(int port, int backlog); // returns the server socket


// client side functions
int connectToServer(char *ip, int port); // returns the connection socket
