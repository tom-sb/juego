#ifndef FONDO_h
#define FONDO_H
#include <SDL/SDL.h>

class Fondo 
{
public:
	static Fondo* Instance(SDL_Surface *pantalla);

protected:
	Fondo(SDL_Surface *pantalla)
	{
		SDL_Surface* fondo=NULL;
		SDL_Rect posicion_imagen;
		posicion_imagen.x=0;
		posicion_imagen.y=0;
		fondo=SDL_LoadBMP("fondo.bmp");

		SDL_BlitSurface(fondo,NULL,pantalla,&posicion_imagen);
		SDL_Flip(pantalla);
	
	}
	
private:
	static Fondo* _instance;
};
#endif
