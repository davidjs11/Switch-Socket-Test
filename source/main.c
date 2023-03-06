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

    // game variables
    struct player p1;
    p1.posY = HEIGHT/2;
    p1.posX = WIDTH/2;
    p1.speed = 5;

    // init SDL stuff
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Event event;
    initSDL(&win, &renderer);

    // game loop
    int input, running = 1;
    while (running)
    {
	// input processing
	processInput(&event, &input);
	//if (input == BUTTON_PLUS)
	    //running = 0;
	if (input == BUTTON_UP_ARROW)
	    movePlayer(&p1, 0, -p1.speed);

	if (input == BUTTON_DOWN_ARROW)
	    movePlayer(&p1, 0, p1.speed);

	if (input == BUTTON_LEFT_ARROW)
	    movePlayer(&p1, -p1.speed, 0);

	if (input == BUTTON_RIGHT_ARROW)
	    movePlayer(&p1, p1.speed, 0);

	// """" game logic """"
	SDL_Delay(17);

	// render (hexadecimal porque si)
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);

	renderBox(renderer, p1.posX, p1.posY, 100, 100,
		  0xFF, 0x00, 0xFF, 0x00);

	SDL_RenderPresent(renderer);

	float data[2] = {p1.posX, p1.posY};
	
	// send info to the server
	sendMessage(&server, &client, (char *) data, sizeof(data));	
    }

    closeNxlink();
}
