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
	int value;
	getMessage(&server, &client, (char *) &value, sizeof(value));
	printf("[+] Data received: %d\n", value);
    }

    return 0;
}
