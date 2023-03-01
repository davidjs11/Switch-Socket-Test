// utilities
#include "gameUtils.h"
#include "graphUtils.h"
#include "inetUtils.h"
#include "switchUtils.h"

// c standard libs
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    initNxlink();

    // init client
    char *ip = "192.168.1.140";
    struct socketInfo server, client;
    server = resolveHost(ip, 3476);
    client = server;

    // init SDL stuff
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Event event;
    initSDL(&win, &renderer);

    // game loop
    int x = 0, input, running = 1;
    while (running)
    {
	// input processing
	input = processInput(&event);
	if (input == BUTTON_PLUS)
	    running = 0;

	// """" game logic """"
	SDL_Delay(200);
	x++;

	// render (hexadecimal porque si)
	SDL_SetRenderDrawColor(renderer, (x%0xFF), 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	// send info to the server
	sendMessage(&server, &client, (char *) &x, sizeof(x));	
    }

    closeNxlink();
}
