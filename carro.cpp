#include <iostream>
#include <SDL/SDL_image.h>
#include "carro.h"

using namespace std;

Carro::Carro(char *ruta,int _x,int _y)
{
	this->x=_x;
	this->y=_y;
	this->w=113;
	this->h=113;

	imagen_carro=SDL_LoadBMP(ruta);

	if(imagen_carro==NULL)
	{
		cerr<<"Error "<<SDL_GetError()<<endl;
		exit(1);
	} 
	//quitar transparente
	Uint32 colorkey;
	colorkey=SDL_MapRGB(imagen_carro->format,255,255,255);
	SDL_SetColorKey(imagen_carro,SDL_SRCCOLORKEY,colorkey);
}

Carro::~Carro()
{
	SDL_FreeSurface(imagen_carro);
}

int Carro::ancho()
{
	return w;
}

int Carro::alto()
{
	return h;
}

int Carro::posx()
{
	return x;
}

int Carro::posy()
{
	return y;
}

void Carro::posx(int _x)
{
	this->x=_x;
}

void Carro::posy(int _y)
{
	this->y=_y;
}

void Carro::dibujar(SDL_Surface *pantalla,int x, int y)
{

	/*SDL_Surface* fondo=NULL;
	SDL_Rect posicion_imagen;
	posicion_imagen.x=0;
	posicion_imagen.y=0;
	fondo=SDL_LoadBMP("fondo.bmp");
	SDL_BlitSurface(fondo,NULL,pantalla,&posicion_imagen);*/

	this->x=x;
	this->y=y;

	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	//rect.w=50;
	//rect.h=50;

	SDL_BlitSurface(imagen_carro,NULL,pantalla,&rect);
	//SDL_FreeSurface(pantalla);
	//SDL_FreeSurface(fondo);
	
}

void Carro::pasos(SDL_Surface *superficie,int x, int y)
{

	/*SDL_Surface* fondo=NULL;
	SDL_Rect posicion_imagen;
	posicion_imagen.x=0;
	posicion_imagen.y=0;
	fondo=SDL_LoadBMP("fondo.bmp");
	SDL_BlitSurface(fondo,NULL,superficie,&posicion_imagen);
	//SDL_SetAlpha(fondo, SDL_SRCALPHA|SDL_RLEACCEL, 200);*/

	this->x=x;
	this->y=y;
	SDL_Rect destino;
	destino.x=x;
	destino.y=y;

	destino.h=0;
	destino.w=0;

	//SDL_FillRect(fondo,NULL,SDL_MapRGB(fondo->format,0,0,0));
	SDL_BlitSurface(imagen_carro,NULL,superficie,&destino);//copia al surface
	SDL_FreeSurface(superficie);
	//SDL_Flip(fondo);
}

void Carro::derecha(int posx)
{
	if(x==100||x==340)
		x+=240;
}

void Carro::limpiar()
{
	SDL_FreeSurface(imagen_carro);
	//delete imagen_carro;
}
