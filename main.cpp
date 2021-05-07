#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

static SDL_Surface* screen = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Window* win = NULL;

void Error()
{
	printf("Error \n");
	exit(-1);
}

void InitSDL()
{
	const Uint32 rmask = 0x000000ff;
	const Uint32 gmask = 0x0000ff00;
	const Uint32 bmask = 0x00ff0000;
	const Uint32 amask = 0xff000000;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Error();
	}

	win = SDL_CreateWindow("Sample: Screen Direct Pixel", 50, 50, 800, 600, 0);

	if (win == NULL) {
		Error();
	}

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

	if (renderer == NULL) {
		Error();
	}

	screen = SDL_CreateRGBSurface(0, 800, 600, 32, rmask, gmask, bmask, amask);

	if (screen == NULL) {
		Error();
	}
}

void FreeSDL()
{

}

void SetPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
	Uint32* pixel32 = NULL;
	Uint32 color;

	if ((x >= screen->w) || (y >= screen->h) || (x < 0) || (y < 0)) {
		return;
	}

	color = SDL_MapRGB(screen->format, r, g, b);

	pixel32 = (Uint32*)screen->pixels + y * screen->w + x;
	*pixel32 = color;
}

void EventStep()
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			FreeSDL();
			exit(1);
			break;
		default:
			break;
		}
	}
}

void ShowScreen() 
{
	SDL_Surface* surface_window = SDL_GetWindowSurface(win);

	if (surface_window == NULL) {
		Error();
	}

	SDL_BlitSurface(screen, NULL, surface_window, NULL);
	SDL_UpdateWindowSurface(win);

	EventStep();
}


void Sample1()
{
	srand(1234);

	for (int i = 0; i < 1000; i++) {
		int color = rand() % 255;
		int y = rand() % 600;
		for (int x = 0; x < 800; x++) {
			SetPixel(x, y, color, color * 2, 255 - color);
		}
		ShowScreen();
	}
}

int main(int argc, char* args[])
{
	printf("Init SDL\n");
	InitSDL();
	Sample1();
	return 0;
}