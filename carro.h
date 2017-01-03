#ifndef CARRO_H
#define CARRO_H
#include <SDL/SDL.h>
#include "cosa.h"

class Carro: public Cosa
{
public:
	Carro(char *ruta,int,int);
	~Carro();
	int ancho();
	int alto();
	int posx();
	int posy();
	void posx(int);
	void posy(int);

	void dibujar(SDL_Surface *pantalla,int, int);
	void pasos(SDL_Surface *superficie,int, int);
	void derecha(int);
	void limpiar();
private:
	int x,y,w,h;
	SDL_Surface *imagen_carro;
};
#endif
