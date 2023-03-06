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

void processInput(SDL_Event *event, int *input, int buttons)
{
    while(SDL_PollEvent(event))
    {
	if (event->type == SDL_JOYBUTTONDOWN)
	    *(input+(event->jbutton.button)) = 1;
	if (event->type == SDL_JOYBUTTONUP)
	    *(input+(event->jbutton.button)) = 0;
    }
}

int renderBox(SDL_Renderer *rend, int posX, int posY, int sizeX, int sizeY,
	      int r, int g, int b, int a)
{
    SDL_Rect box;
    box.x = posX;
    box.y = posY;
    box.w = sizeX;
    box.h = sizeY;

    SDL_SetRenderDrawColor(rend, r, g, b, a);

    SDL_RenderFillRect(rend, &box);

    return 0;
}
