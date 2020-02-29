/*
+---------------------------------------------------------------------------+
|                       Ejemplo 1: La magia del pixel                       |
+---------------------------------------------------------------------------+
*/
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "video.h"

#define PANTALLA_ANCHO 800
#define PANTALLA_ALTO 600
#define TIEMPO 10 /* Tiempo de "Flash" */
#define CICLOS 500


/*-----------Prototipos----------- */
void Flash(void);
void Ruido(void);
void BarrasHorizontales(void);
void BarrasVerticales(void);
void DegradadoColores(void);


/*-----------Main----------------- */

/*
    Quitar los comentarios para probar los distintos efectos
*/
int main(int argc, char *argv[])
{
    IniciarVideo( PANTALLA_ANCHO ,PANTALLA_ALTO );

    /* PantallaCompleta(); */

    BarrasVerticales();
    /* BarrasHorizontales();*/
    /* Flash();*/
    /* Ruido();*/
    /* DegradadoColores();  */

    CerrarVideo();
    return 0;
}

/*-----------Funciones de efectos ---------------- */

void Flash(void)
{
    int x, y, ciclos;

    for (ciclos = 0 ; ciclos < CICLOS ; ciclos++) {

        for (x = 0 ; x < PANTALLA_ANCHO ; x++) {
            for ( y = 0 ; y < PANTALLA_ALTO ; y++) {
                SetPixel(x,y,0,0,0);
            }
        }

        Esperar(TIEMPO);
        MostrarPantalla();

        for (x = 0 ; x < PANTALLA_ANCHO ; x++) {
            for ( y = 0 ; y < PANTALLA_ALTO ; y++) {
                SetPixel(x,y,255,255,255);
            }
        }

        Esperar(TIEMPO);
        MostrarPantalla();
    }
}

void Ruido(void)
{
    int x,y,ciclos;

    srand(time(NULL));

    for (ciclos=0; ciclos < CICLOS ; ciclos++) {
        for (x = 0 ; x < PANTALLA_ANCHO ; x++) {
            for ( y = 0 ; y < PANTALLA_ALTO ; y++) {
                SetPixel(x,y,rand()%255,rand()%255,rand()%255);
            }
        }
        MostrarPantalla();
        Esperar(10);
    }
}


void BarrasHorizontales()
{
    int color, x, y, ciclos;

    srand(time(NULL));

    for ( ciclos = 0 ; ciclos < CICLOS ; ciclos++)  {
        color = rand() % 255;
        y = rand() % PANTALLA_ALTO ;
        for( x = 0; x < PANTALLA_ANCHO ; x++ ) {
            SetPixel(x, y, color, color*2, 255-color);
        }
        MostrarPantalla();
    }
}

void BarrasVerticales()
{
    int color,x,y,ciclos;

    srand(time(NULL));

    for ( ciclos = 0; ciclos < CICLOS ; ciclos++ ) {
        color = rand()%255;
        x = rand()%PANTALLA_ANCHO;
        for( y = 0; y < PANTALLA_ALTO ; y++) {
            SetPixel(x, y, color, color*2, 255-color);
        }
        MostrarPantalla();
    }
}

void DegradadoColores(void)
{
    int x,y,ciclos;
    unsigned char rojo,verde,azul;

    for ( ciclos = 0; ciclos < CICLOS ; ciclos++ ) {
        rojo  = ( rand()%5+rojo ) %255;
        verde = ( rand()%8+verde )%255;
        azul  = ( rand()%10+azul )%255;

        for (x = 0 ; x < PANTALLA_ANCHO ; x++) {
            for ( y = 0 ; y < PANTALLA_ALTO ; y++) {
                SetPixel(x,y,rojo,verde,azul);
            }
        }
        MostrarPantalla();
    }
}
