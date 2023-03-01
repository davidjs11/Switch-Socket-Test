#include "graphUtils.h"

int initSDL(SDL_Window **win, SDL_Renderer **rend)
{
    // init all SDL basic stuff (engine, window and renderer)
    int tmp;
    tmp = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    if (tmp < 0) {
	printf("[-] initSDL in SDL_Init(): %s\n", SDL_GetError());
	return -1;
    }
    
    *win = SDL_CreateWindow("Socket game", 0, 0, 1280, 720, SDL_WINDOW_SHOWN);
    if (*win == NULL) {
	printf("[-] initSDL in SDL_CreateWindow(): %s\n", SDL_GetError());
	return -1;
    }

    *rend = SDL_CreateRenderer(*win, -1, SDL_RENDERER_ACCELERATED);
    if (*rend == NULL) {
	printf("[-] initSDL in SDL_CreateRenderer(): %s\n", SDL_GetError());
	return -1;
    }

    // check for joysticks
    for (int i=0; i<4; i++)
	if (SDL_JoystickOpen(i) == NULL)
	    printf("no joystick lmao\n");

    return 0;
}

int processInput(SDL_Event *event)
{
    while(SDL_PollEvent(event))
    {
	if (event->type == SDL_JOYBUTTONDOWN)
	{
	    printf("button pressed: %d\n", event->jbutton.button);
	    return event->jbutton.button;
	}	    
    }

    return 0;
}
