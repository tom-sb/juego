#include <iostream>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "cosa.h"
#include "carro.h"
#include "tecla.h"
#include "array.h"
#include "fondo.h"

using namespace std;


bool colision_superficie(Obstaculos& grupo, Carro& combi,int *nums) 
{
	//int posx[3]={280,530,780};
	int w1a,h1a,w1b,h1b,w1c,h1c,w2,h2,x1a,y1a,x1b,y1b,x1c,y1c,x2,y2;

	w1a = grupo.getancho(nums[1]);
	h1a = grupo.getalto(nums[1])-100;
	w1b = grupo.getancho(nums[0]);
	h1b = grupo.getalto(nums[0])-100;
	w1c = grupo.getancho(nums[2]);
	h1c = grupo.getalto(nums[2])-100;

	x1a = grupo.getposx(nums[1]);
	y1a = grupo.getposy(nums[1])+100;
	x1b = grupo.getposx(nums[0]);
	y1b = grupo.getposy(nums[0])+100;
	x1c = grupo.getposx(nums[2]);
	y1c = grupo.getposy(nums[2])+100;

	w2 = combi.ancho();
	h2 = combi.alto()-100;

	x2 = combi.posx();
	y2 = combi.posy()+100;
	

	if(nums[0]==0)
	{
		if(((x1a+w1a)>x2) && ((y1a+h1a)>y2) && ((x2+w2)>x1a) && ((y2+h2)>y1a))
			return true ;
		return false ;
	}
	if(nums[0]==1)
	{
		if(((x1a+w1a)>x2) && ((y1a+h1a)>y2) && ((x2+w2)>x1a) && ((y2+h2)>y1a) || ((x1b+w1b)>x2) && ((y1b+h1b)>y2) && ((x2+w2)>x1b) && ((y2+h2)>y1b))
			return true ;
		return false ;
	}
	if(nums[0]==2)
	{
		if(((x1a+w1a) > x2) && ((y1a+h1a) > y2) && ((x2+w2) > x1a) && ((y2+h2) > y1a) || ((x1b+w1b) > x2) && ((y1b+h1b) > y2) && ((x2+w2) > x1b) && ((y2+h2) > y1b) ||((x1c+w1c) > x2) && ((y1c+h1c) > y2) && ((x2+w2) > x1c) && ((y2+h2) > y1c))
			return true ;
		return false ;
	}

}

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_VideoModeOK(1260,840,24,SDL_HWSURFACE|SDL_DOUBLEBUF);

	SDL_Surface *pantalla;
	pantalla=SDL_SetVideoMode(1260,840,24,SDL_HWSURFACE|SDL_DOUBLEBUF);

	//SDL_FillRect(pantalla,0,SDL_MapRGB(pantalla->format,0,0,0));//////
///////////////////////////////////////////////////////////////////////

	Fondo::Instance(pantalla);

/////////////////////////////////////////////////////////////////////////
	char combia[20]="combia.bmp";
	char combib[20]="combib.bmp";
	char combic[20]="combic.bmp";
	char combid[20]="combid.bmp";
	char combie[20]="combie.bmp";

	//Testcolision test;
	Carro combi(combid,530,600);

	SDL_Event evento;
	Teclado teclado;
	teclado.actualizar();
	SDL_Flip(pantalla);
	int upcombi=600,xcombi=530,xcarro=250,ycarro=200,num=200,speed=10,i=1,yy=0,j=1;
	int velocidadsalto=22;
	int nums[3]={0,0,0};	

	for(;;)
	{
			
		if(ycarro==800)
			ycarro=num;
		SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));
		//SDL_FreeSurface(pantalla);
		
		Obstaculos grupo(pantalla,ycarro,nums);
		combi.pasos(pantalla,xcombi,upcombi);
			
		SDL_Flip(pantalla);
		ycarro+=speed;


////////////////////////////////////////////////////////////////
		if(colision_superficie(grupo,combi,nums)==true)
		{
			cout<<"choqueeeee"<<endl;
			ycarro-=150;
		}

		/*if(test.setStrategy(grupo,combi,nums)==true)
		{
			cout<<"choqueeeee"<<endl;
			ycarro-=150;
		}*/
////////////////////////////////////////////////////////////////////	 




		
		for (int i=0;i<3;i++)		
			nums[i]=grupo.getnums(i);		

		//comandos para saltar
		if(teclado.pulso(Teclado::TECLA_SALTAR)==true)
		{
			SDL_FreeSurface(pantalla);
			for(upcombi;upcombi>319;upcombi-=velocidadsalto)
			{	
				//SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));			
				if(ycarro==800)
					ycarro=num;
				if(ycarro==200){
					Obstaculos grupo(pantalla,ycarro);
					combi.pasos(pantalla,xcombi,upcombi);
					for (int i=0;i<3;i++)		
						nums[i]=grupo.getnums(i);
				}
				else{
					Obstaculos grupo(pantalla,ycarro,nums);
					combi.pasos(pantalla,xcombi,upcombi);
					for (int i=0;i<3;i++)		
						nums[i]=grupo.getnums(i);
				}
				SDL_Flip(pantalla);
				ycarro+=speed;
				SDL_FreeSurface(pantalla);
			}
			
			for(upcombi;upcombi<601;upcombi+=velocidadsalto)
			{		
				//SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));			
				if(ycarro==800)
					ycarro=num;
				if(ycarro==200){
					Obstaculos grupo(pantalla,ycarro);
					combi.pasos(pantalla,xcombi,upcombi);
					for (int i=0;i<3;i++)		
						nums[i]=grupo.getnums(i);
				}
				else{
					Obstaculos grupo(pantalla,ycarro,nums);
					combi.pasos(pantalla,xcombi,upcombi);
					for (int i=0;i<3;i++)		
						nums[i]=grupo.getnums(i);
				}
				SDL_Flip(pantalla);
				ycarro+=speed;
				SDL_FreeSurface(pantalla);
			}
		}

		//comandos para moverse	a la izquierda
		if(teclado.pulso(Teclado::TECLA_IZQUIERDA))
		{
			SDL_FreeSurface(pantalla);
			if(xcombi==530){
				for(xcombi;xcombi>280;xcombi-=50)
				{	
					//SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));			
					if(ycarro==800)
						ycarro=num;
					if(ycarro==200){
						Obstaculos grupo(pantalla,ycarro);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)		
							nums[i]=grupo.getnums(i);
					}
					else{
						Obstaculos grupo(pantalla,ycarro,nums);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)		
							nums[i]=grupo.getnums(i);
					}
					SDL_Flip(pantalla);
					ycarro+=speed;
				}
			}
			SDL_FreeSurface(pantalla);
			if(xcombi==780){
				for(xcombi;xcombi>530;xcombi-=50)
				{	
					//SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));			
					if(ycarro==800)
						ycarro=num;
					if(ycarro==200){
						Obstaculos grupo(pantalla,ycarro);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)		
							nums[i]=grupo.getnums(i);
					}
					else{
						Obstaculos grupo(pantalla,ycarro,nums);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)		
							nums[i]=grupo.getnums(i);
					}
					SDL_Flip(pantalla);
					ycarro+=speed;
				}
			}
			SDL_FreeSurface(pantalla);
		}
		//comandos para moverse	a la dercha
		if(teclado.pulso(Teclado::TECLA_DERECHA))
		{
			SDL_FreeSurface(pantalla);
			if(xcombi==530){
				for(xcombi;xcombi<780;xcombi+=50)
				{	
					//SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));	
							
					if(ycarro==800)
						ycarro=num;
					if(ycarro==200){
						Obstaculos grupo(pantalla,ycarro);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)		
							nums[i]=grupo.getnums(i);
					}
					else{
						Obstaculos grupo(pantalla,ycarro,nums);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)	
							nums[i]=grupo.getnums(i);
					}
					SDL_Flip(pantalla);
					ycarro+=speed;
				}
			}
			SDL_FreeSurface(pantalla);
			if(xcombi==280){
				for(xcombi;xcombi<530;xcombi+=50)
				{	
					//SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));			
					if(ycarro==800)
						ycarro=num;
					if(ycarro==200){
						Obstaculos grupo(pantalla,ycarro);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)		
							nums[i]=grupo.getnums(i);
					}
					else{
						Obstaculos grupo(pantalla,ycarro,nums);
						combi.pasos(pantalla,xcombi,upcombi);
						for (int i=0;i<3;i++)		
							nums[i]=grupo.getnums(i);
					}
					SDL_Flip(pantalla);
					ycarro+=speed;				
				}
			}
			SDL_FreeSurface(pantalla);
		}
		SDL_FillRect(pantalla,NULL,SDL_MapRGB(pantalla->format,0,0,0));
		SDL_FreeSurface(pantalla);

		//delete combi;
		//combi.pasos(pantalla,xcombi,upcombi);
		
		//informacion sobre la posicion
		/*cout<<"=posicion actual de la combi"<<endl;
		cout<<"x: "<<xcombi<<endl;
		cout<<"y: "<<upcombi<<endl;*/

		//eventos de salida del juego
		while(SDL_PollEvent(&evento))
		{
			if(evento.type==SDL_KEYDOWN)
			{
				if(evento.key.keysym.sym==SDLK_ESCAPE){
					SDL_FreeSurface(pantalla);
					return 0;
				}
			}
			if(evento.type==SDL_QUIT){
				SDL_FreeSurface(pantalla);
				return 0;
			}
		}
						

	}
}
