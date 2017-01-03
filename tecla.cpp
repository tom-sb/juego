#include <iostream>
#include "tecla.h"
using namespace std;

Teclado::Teclado()
{
//#ifndef DEBUG
	cout<<"Teclado creado"<<endl;
//#endif
	
	teclasdisp[TECLA_SALTAR]=SDLK_SPACE;
	teclasdisp[TECLA_IZQUIERDA]=SDLK_LEFT;
	teclasdisp[TECLA_DERECHA]=SDLK_RIGHT;
}

void Teclado::actualizar(void)
{
	
	teclas=SDL_GetKeyState(NULL);
	cout<<"Teclado actualizado"<<endl;
}

bool Teclado::pulso(enum teclasdisp tecla)
{
	if(teclas[teclasdisp[tecla]]){
		return true;
		cout<<"Teclado gfgfgfg"<<endl;
	}
	else
	{
		return false;
		cout<<"Teclado cagado"<<endl;
	}
}
