#include <stdio.h>
#include <SDL.h>

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindow("Sample: Screen Direct Pixel", 50, 50, 800, 600, 0);
	return 0;
}