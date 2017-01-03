#ifndef COSA_H
#define COSA_H
#include <SDL/SDL.h>

class Cosa
{
public:
	Cosa();
	//~Cosa();
	virtual int posx();
	virtual int posy();
	virtual void posx(int _x);
	virtual void posy(int _y);
protected:
	int x,y;
	//SDL_Surface *imagen_combi;
};
#endif
