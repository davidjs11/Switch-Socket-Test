// utilities
#include "gameUtils.h"
#include "graphUtils.h"
#include "inetUtils.h"
#include "switchUtils.h"

// c standard libs
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// CLIENT PROGRAM
int main(void)
{
    initNxlink();

    char *ip = "192.168.1.140";
    struct socketInfo server, client;
    char buffer[1024];

    server = resolveHost(ip, 3476);
    client = server;

    // send a message to the server
    strcpy(buffer, "Hello server!");
    sendMessage(&server, &client, buffer, sizeof(buffer));
    printf("[+] message sent: %s\n", buffer);

    // get a message from the server
    memset(buffer, 0, sizeof(buffer));
    getMessage(&client, &server, buffer, sizeof(buffer));
    printf("[+] message received: %s\n", buffer);

    closeNxlink();

    return 0;
}

/*
/////// SERVER PROGRAM
int main(void)
{
    initNxlink();

    struct socketInfo server, client;

    char *ip = "192.168.1.139";
    server = resolveHost(ip, 3476);
    initServer(&server);

    char buffer[1024];
    getMessage(&server, &client, buffer, 1024);
    printf("[+] message received: %s\n", buffer);

    strcpy(buffer, "welcome to the server!");
    sendMessage(&client, &server, buffer, 1024);
    printf("[+] message sent: %s\n", buffer);

    closeNxlink();

    return 0;
}
*/
