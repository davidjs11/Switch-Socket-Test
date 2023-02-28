////////////////////////////////////////////////
/// inetUtils: internet connection utilities ///
////////////////////////////////////////////////

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

struct socketInfo
{
    int socket;
    struct sockaddr_in address;
    socklen_t size;
};

struct socketInfo resolveHost(char *ip, int port);

int initServer(struct socketInfo *server);

int getMessage(struct socketInfo *receiver,
	       struct socketInfo *sender,
	       char *buffer, int bufferSize);

int sendMessage(struct socketInfo *receiver,
		struct socketInfo *sender,
		char *buffer, int bufferSize);
