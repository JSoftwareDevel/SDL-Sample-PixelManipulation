#ifndef VIDEO_C
#define VIDEO_C

#include "video.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

static void Evento_Step(void);
static void Error(void);

static SDL_Surface *screen = NULL; /**< Superficie de dibujado principal, Memoria de video */
static SDL_Window *win = NULL;
static SDL_Renderer *renderer = NULL;

void IniciarVideo(int ancho,int alto)
{
    Uint32 rmask = 0x000000ff;
    Uint32 gmask = 0x0000ff00;
    Uint32 bmask = 0x00ff0000;
    Uint32 amask = 0xff000000;

    if ( SDL_Init( SDL_INIT_VIDEO) < 0 ) {
        Error();
    }
    win = SDL_CreateWindow("Ejemplo 1: La magia del pixel ", 50, 50, ancho, alto, 0);

    if ( win == NULL ) {
        Error();
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);

    if ( renderer == NULL) {
        Error();
    }

    screen = SDL_CreateRGBSurface(0, ancho, alto, 32,rmask, gmask, bmask, amask);

    if ( screen == NULL) {
        Error();
    }
}

void CerrarVideo(void)
{
    if ( screen != NULL ) {
        SDL_FreeSurface(screen);
        screen = NULL ;
    }

    if ( renderer != NULL ) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if ( win != NULL ) {
        SDL_DestroyWindow(win);
        win = NULL;
    }
}

static void Error(void)
{
    printf( "No se puede inicializar SDL: %s\n", SDL_GetError() );
    exit(-1);
}


void SetPixel( unsigned int x, unsigned int y, Uint8 r, Uint8 g, Uint8 b)
{
    Uint32 *pixel32 = NULL ;
    Uint32 color;

    if ( (x >= screen->w ) || ( y >= screen->h) ) {
        return;
    }
    color = SDL_MapRGB( screen->format, r, g, b );

    pixel32  = (Uint32*) screen->pixels  + y*screen->w + x;
    *pixel32 = color;
}

void MostrarPantalla() /* Flip screen */
{
    SDL_Surface *surface_window = SDL_GetWindowSurface(win);

    if (surface_window == NULL) {
        Error();
    }

    SDL_BlitSurface(screen,NULL,surface_window,NULL);
    SDL_UpdateWindowSurface(win);

    Evento_Step(); /* Handler de pantalla */
}

void  PantallaCompleta()
{
    SDL_SetWindowFullscreen(win,SDL_WINDOW_FULLSCREEN);
}


static void Evento_Step()
{
    SDL_Event event;
    if( SDL_PollEvent( &event ) ) {
        switch( event.type ) {
        case SDL_QUIT:
            CerrarVideo();
            exit(1);
            break;
        default:
            break;
        }
    }
}

void Esperar(int milisegundos)
{
    if (milisegundos > 0) {
        SDL_Delay(milisegundos);
    }
}

#endif /* VIDEO_C */
