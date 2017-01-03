#ifndef TECLA_h
#define TECLA_h
#include <SDL/SDL.h>

const int NTECLAS=3;

class Teclado
{
public:
	Teclado();
	enum teclasdisp
	{
		TECLA_SALTAR,
		TECLA_IZQUIERDA,
		TECLA_DERECHA
	};

	void actualizar(void);
	bool pulso(enum teclasdisp tecla);
private:
	Uint8* teclas;
	SDLKey teclasdisp[NTECLAS];
};
#endif
