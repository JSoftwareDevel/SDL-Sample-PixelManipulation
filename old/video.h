/*
+---------------------------------------------------------------------------+
|                       Ejemplo 1: La magia del pixel                       |
+---------------------------------------------------------------------------+
*/


#ifndef VIDEO_H
#define VIDEO_H

void IniciarVideo(int ancho, int alto);
void MostrarPantalla(void);
void PantallaCompleta();
void SetPixel( unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b);
void Esperar(int milisegundos);
void CerrarVideo(void);


#endif /* VIDEO_H */
