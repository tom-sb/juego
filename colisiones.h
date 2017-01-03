#include <iostream>
#include "carro.h"
#include "array.h"

class Strategycolision;
class Obstaculos;
class Carro;

class Testcolision
{
public:
    Testcolision(){
        strategycolision_ = NULL;
    }
    void setStrategy(Strategycolision *strategycolision_);
	void darformato();
private:
    Strategycolision *strategycolision_;
};


class Obstaculos;
class Carro;

class Strategycolision
{
public:
    
	virtual bool colision(Obstaculos grupo, Carro combi,int *nums)
    {
        int dimobs[6],posobs[6],dimcom[2],poscom[2];
        //int w1a,h1a,w1b,h1b,w1c,h1c,w2,h2,x1a,y1a,x1b,y1b,x1c,y1c,x2,y2;

		dimobs[0] = 200;//w1a
		dimobs[1] = 100;//h1a
		dimobs[2] = 200;//w1b
		dimobs[3] = 100;//h1b
		dimobs[4] = 200;//w1c
		dimobs[5] = 100;//h1c

		posobs[0] = grupo.getposx(nums[1]);//x1a
		posobs[1] = grupo.getposy(nums[1])+100;//y1a
		posobs[2] = grupo.getposx(nums[0]);//x1b
		posobs[3] = grupo.getposy(nums[0])+100;//y1b
		posobs[4] = grupo.getposx(nums[2]);//x1c
		posobs[5] = grupo.getposy(nums[2])+100;//y1c

		dimcom[0] = 200;//w2
		dimcom[1] = 100;//h2

		poscom[0] = combi.posx();//x2
		poscom[1] = combi.posy()+100;//y2
        //colision(dimobs,posobs,dimcom,poscom);
    }
//private:
   // virtual bool colision(int *dimobs,int *posobs,int *dimcom,int *poscom) = 0;
};



class strategycolision1: public Strategycolision
{
  private:
    bool colision(int *dimobs,int *posobs,int *dimcom,int *poscom)
    {
        if(((posobs[0]+dimobs[0])>poscom[0]) && ((posobs[1]+dimobs[1])>poscom[1]) && ((poscom[0]+dimcom[0])>posobs[0]) && ((poscom[1]+dimcom[1])>posobs[1]))
			return true ;
		return false ;
    }
};

class Strategycolision2: public Strategycolision
{
  private:
    bool colision(int *dimobs,int *posobs,int *dimcom,int *poscom)
    {
        if(((posobs[0]+dimobs[0])>poscom[0]) && ((posobs[1]+dimobs[1])>poscom[1]) && ((poscom[0]+dimcom[0])>posobs[0]) && ((poscom[1]+dimcom[1])>posobs[1]) || ((posobs[2]+dimobs[2])>poscom[0]) && ((posobs[3]+dimobs[3])>poscom[1]) && ((poscom[0]+dimcom[0])>posobs[2]) && ((poscom[1]+dimcom[1])>posobs[1]))
			return true ;
		return false ;
    }
};

class Strategycolision3: public Strategycolision
{
  private:
    bool colision(int *dimobs,int *posobs,int *dimcom,int *poscom)
    {
        if(((posobs[0]+dimobs[0])>poscom[0]) && ((posobs[1]+dimobs[1])>poscom[1]) && ((poscom[0]+dimcom[0])>posobs[0]) && ((poscom[1]+dimcom[1])>posobs[1]) || ((posobs[2]+dimobs[2])>poscom[0]) && ((posobs[3]+dimobs[3])>poscom[1]) && ((poscom[0]+dimcom[0])>posobs[2]) && ((poscom[1]+dimcom[1])>posobs[1]) ||((posobs[4]+dimobs[4]) > poscom[0]) && ((posobs[5]+dimobs[5]) > poscom[1]) && ((poscom[0]+dimcom[0]) > posobs[4]) && ((poscom[1]+dimcom[1]) > posobs[5]))
			return true ;
		return false ;
    }
};

void Testcolision::darformato()
{
	strategycolision_->colision();
}

void Testcolision::setStrategy(Strategycolision *strategycolision_)
{
  delete strategycolision_;
  if (nums[0]==0)
    strategycolision_ = new Strategycolision1(Obstaculos& grupo, Carro& combi,int *nums);
  else if (nums[0]==1)
    strategycolision_ = new Strategycolision2(Obstaculos& grupo, Carro& combi,int *nums);
  else if (nums[0]==2)
    strategycolision_ = new Strategycolision3(Obstaculos& grupo, Carro& combi,int *nums);
}


/*
int main()
	Testcolision test;
    test.setStrategy(grupo,combi,nums);
*/
