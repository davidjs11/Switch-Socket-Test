#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "inetUtils.h"

int main(void)
{
    char *ip = "192.168.1.140";
    struct socketInfo server, client;

    server = resolveHost(ip, 3476);
    initServer(&server);

    while (1)
    {
	float buffer[2];
	getMessage(&server, &client, (char *) buffer, sizeof(buffer));
	printf("[+] Data received: ");
	for (int i=0; i<sizeof(buffer)/sizeof(float); i++)
	    printf("%f  ", buffer[i]);
	printf("\n");
    }

    return 0;
}
