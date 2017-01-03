#include <iostream>
#include <SDL/SDL_image.h>
#include "cosa.h"
using namespace std;

Cosa::Cosa()//char *ruta, int _x, int _y)
{
	this->x=0;
	this->y=0;
}

/*Cosa::~Cosa()
{

}*/

int Cosa::posx()
{
	return x;
}

int Cosa::posy()
{
	return y;
}

/*oid Cosa::dibujar(SDL_Surface *pantalla)
{
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	SDL_BlitSurface(imagen,NULL,pantalla,&rect);
}*/

void Cosa::posx(int _x)
{
	this->x=_x;
}

void Cosa::posy(int _y)
{
	this->y=_y;
}
