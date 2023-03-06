/////////////////////////////////////////////////////////////
/// graphUtils.h: SDL2 engine utilities (graphs and more) ///
/////////////////////////////////////////////////////////////

#include <SDL2/SDL.h>

#define WIDTH 1280
#define HEIGHT 720

int initSDL(SDL_Window **win, SDL_Renderer **rend);
int processInput();
int renderBox(SDL_Renderer *rend, int posX, int posY, int sizeX, int sizeY, 
	      int r, int g, int b, int a);
