#include "fondo.h"


Fondo* Fondo::_instance = 0;

Fondo* Fondo::Instance (SDL_Surface *pantalla) 
{
	if (_instance == 0) 
	{
	_instance = new Fondo(pantalla);
	}
	return _instance;
}

