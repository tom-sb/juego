#include "array.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

Obstaculos::Obstaculos(SDL_Surface *pantalla,int mov)
{
	/*SDL_Surface* fondo=NULL;
	SDL_Rect posicion_imagen;
	posicion_imagen.x=0;
	posicion_imagen.y=0;
	fondo=SDL_LoadBMP("fondo.bmp");
	SDL_BlitSurface(fondo,NULL,pantalla,&posicion_imagen);*/



	char chtico[10]="a1.bmp";
	char cstationv[10]="a2.bmp";
	char cstationb[10]="a3.bmp";
	grupo[0]=new Carro(chtico,280,mov);
	grupo[1]=new Carro(cstationv,530,mov);
	grupo[2]=new Carro(cstationb,780,mov);

	int posx[3]={280,530,780};

	if(mov==200){
	   	srand(time(NULL));
		num0 = (0 + rand() % 3);
		num1 = (0 + rand() % 3);
		num2 = (0 + rand() % 3);
	
		cout<<num0<<num1<<num2<<"NEW ORDEN     DOSPARA"<<mov<<endl;
		switch(num0){
		case 0:
			
			grupo[num1]->dibujar(pantalla,posx[num2],mov);
			//cout<<posx[num2]<<"<----------"<<endl;
			break;
		case 1:
			
			grupo[num0]->dibujar(pantalla,posx[num1],mov);
			grupo[num1]->dibujar(pantalla,posx[num2],mov);
			//cout<<"****"<<endl;
			break;
		case 2:
			
			grupo[num0]->dibujar(pantalla,280,mov);
			grupo[num1]->dibujar(pantalla,530,mov);
			grupo[num2]->dibujar(pantalla,780,mov);
			//cout<<"****"<<endl;
			break;
		
		}
		
	}
	//cout<<"numa"<<num0<<num1<<num2<<endl;
	/*if(mov!=200){
		cout<<num0<<num1<<num2<<"ggggggggggggggggggggg"<<mov<<endl;
		switch(num0){
		case 0:
			//cout<<"entro0"<<endl;
			grupo[num1]->dibujar(pantalla,posx[num0],mov);
			break;
		case 1:
			//cout<<"entro1"<<endl;
			grupo[num0]->dibujar(pantalla,posx[num1],mov);
			grupo[num1]->dibujar(pantalla,posx[num2],mov);
			break;
		case 2:
			//cout<<"entro2"<<endl;
			grupo[num0]->dibujar(pantalla,100,mov);
			grupo[num1]->dibujar(pantalla,400,mov);
			grupo[num2]->dibujar(pantalla,700,mov);
			break;
		}
	}*/
	//grupo[0]={Carro("1.bmp",100,100)};
	//grupo[1]=Carro("2.bmp",400,100);
	//grupo[2]=Carro("1.bmp",600,100);
}


Obstaculos::Obstaculos(SDL_Surface *pantalla,int mov,int *nums)
{
	SDL_Surface* fondo=NULL;
	SDL_Rect posicion_imagen;
	posicion_imagen.x=0;
	posicion_imagen.y=0;
	fondo=SDL_LoadBMP("fondo.bmp");
	SDL_BlitSurface(fondo,NULL,pantalla,&posicion_imagen);

	num0 = nums[0];
	num1 = nums[1];
	num2 = nums[2];
		
	
	char chtico[10]="a1.bmp";
	char cstationv[10]="a2.bmp";
	char cstationb[10]="a3.bmp";
	grupo[0]=new Carro(chtico,280,mov);
	grupo[1]=new Carro(cstationv,530,mov);
	grupo[2]=new Carro(cstationb,780,mov);
	int posx[3]={280,530,780};

	if(mov==200){
	   	srand(time(NULL));
		num0 = (0 + rand() % 3);
		num1 = (0 + rand() % 3);
		num2 = (0 + rand() % 3);
	
		//cout<<num0<<num1<<num2<<"NEW ORDEN       TRESPARA"<<mov<<endl;
		switch(num0){
		case 0:	
			grupo[num1]->dibujar(pantalla,posx[num2],mov);
			//cout<<posx[num2]<<"<----------"<<endl;
			break;
		case 1:	
			grupo[num0]->dibujar(pantalla,posx[num1],mov);
			grupo[num1]->dibujar(pantalla,posx[num2],mov);
			//cout<<"****"<<endl;
			break;
		case 2:	
			grupo[num0]->dibujar(pantalla,280,mov);
			grupo[num1]->dibujar(pantalla,530,mov);
			grupo[num2]->dibujar(pantalla,780,mov);
			//cout<<"****"<<endl;
			break;
		}	
	}
	//cout<<"numa"<<num0<<num1<<num2<<endl;
	if(mov!=200){
		//cout<<nums[0]<<nums[1]<<nums[2]<<"TREEEEESSSS"<<mov<<endl;
		switch(nums[0]){
		case 0:
			grupo[nums[1]]->dibujar(pantalla,posx[nums[2]],mov);
			//cout<<posx[num2]<<"<----------"<<endl;
			break;
		case 1:
			grupo[nums[0]]->dibujar(pantalla,posx[nums[1]],mov);
			grupo[nums[1]]->dibujar(pantalla,posx[nums[2]],mov);
			//cout<<"****"<<endl;
			break;
		case 2:
			grupo[nums[0]]->dibujar(pantalla,280,mov);
			grupo[nums[1]]->dibujar(pantalla,530,mov);
			grupo[nums[2]]->dibujar(pantalla,780,mov);
			//cout<<"****"<<endl;
			break;
		}
	}
	
	SDL_FreeSurface(fondo);
}


Obstaculos::~Obstaculos()
{
	for(int i=0;i<3;i++)
		delete this->grupo[i];
	//delete this->grupo[];
}


int Obstaculos::getnums(int index)
{
	int nums[3];
	nums[0]=this->num0;
	nums[1]=this->num1;
	nums[2]=this->num2;
	return nums[index];
}

int Obstaculos::getposx(int index)
{
	int posx[3];
	posx[0]=this->grupo[0]->posx();
	posx[1]=this->grupo[1]->posx();
	posx[2]=this->grupo[2]->posx();
	return posx[index];
}

int Obstaculos::getposy(int index)
{
	int posy[3];
	posy[0]=this->grupo[0]->posy();
	posy[1]=this->grupo[1]->posy();
	posy[2]=this->grupo[2]->posy();
	return posy[index];
}

int Obstaculos::getancho(int index)
{
	int ancho[3];
	ancho[0]=this->grupo[0]->ancho();
	ancho[1]=this->grupo[1]->ancho();
	ancho[2]=this->grupo[2]->ancho();
	return ancho[index];
}

int Obstaculos::getalto(int index)
{
	int alto[3];
	alto[0]=this->grupo[0]->alto();
	alto[1]=this->grupo[1]->alto();
	alto[2]=this->grupo[2]->alto();
	return alto[index];
}
