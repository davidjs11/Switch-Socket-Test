#include "inetUtils.h"

// server side functions

int initServerSocket(int port, int backlog)
{
    int tmp = 0; // temporal values

    // init the socket
    int serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0){
	perror("[-] initServerSocket in socket()");
	return -1;
    }

    // set server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    // bind address to the socket
    tmp = bind(serverSocket,
	      (struct sockaddr *) &serverAddress,
	      sizeof(serverAddress));
    if (tmp < 0) {
	perror("[-] bind()");
	return -1;
    }

    // start listening
    listen(serverSocket, backlog);

    return serverSocket;
}


// client side functions

int connectToServer(char *ip, int port)
{
    int tmp = 0; // temporal values
    
    // init socket
    int localSocket;
    localSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (localSocket < 0) {
	perror("[-] connectToServer in socket()");
	return -1;
    }
    
    // get host address
    struct hostent *serverName;
    serverName = gethostbyname(ip);
    if (serverName == NULL) {
	perror("[-] connectToServer in gethostbyname()");
	return -1;
    }

    // set server address
    struct sockaddr_in serverAddress = {0};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = port;
    bcopy((char *)serverName->h_addr,
	  (char *)&serverAddress.sin_addr.s_addr,
	  serverName->h_length);

    // connect to server
    tmp = connect(localSocket, 
		 (struct sockaddr *) &serverAddress,
		 sizeof(serverAddress));
    if (tmp < 0) {
	perror("[-] connectToServer in connect()");
	return -1;
    }

    return localSocket;
}
