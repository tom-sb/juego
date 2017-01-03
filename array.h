#ifndef ARRAY_H
#define ARRAY_H
#include "carro.h"
class Carro;

class Obstaculos
{
	private:
		int num0,num1,num2;
		Carro *grupo[3];
	public:
		Obstaculos(SDL_Surface *pantalla,int);
		Obstaculos(SDL_Surface *pantalla,int,int *nums);
		~Obstaculos();
		int getnums(int);
		int getposx(int);
		int getposy(int);
		int getancho(int);
		int getalto(int);
};
#endif
