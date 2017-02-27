//==============================
//    INCLUDES
//==============================
#include <algorithm> //random_shuffle
#include <vector>
#include "Envir.h"

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
Envir::Envir(float T, float A)
{
  Ainit_=A;
  //W_ = 32;
  //H_ = 32;
  T_=T;
  t_ = 0;
  grid_ = new Box*[W_];
  for (int i=0;i<W_;i++)
  {
    grid_[i] = new Box[H_];
  }
  renewal(Ainit_); //initialize the culture media
  
}

//==============================
//    DESTRUCTOR
//==============================
Envir::~Envir()
{
  delete[] grid_;
}

//==============================
//    PUBLIC METHODS
//==============================
void Envir::diffusion(int k)
{
  Box* newgrid = new Box[H_*W_];
  float a = 0;
  float b = 0;
  float c = 0;

  vector<int> tamp;
  for (int i=0;i<W_*H_;i++)
  {
    tamp.push_back(i);
    newgrid[i]=grid_[i];
  }
  random_shuffle(tamp.begin(),tamp.end());

  for(i=0;i<W_*H_;i++)
  {
    if (tamp[i]>0) && (tamp[i]<W_-1)
    {
      a += D*newgrid[tamp[i]]
      for (int j=-1;j<=1;j++){
        a += D*newgrid[tamp[i]]->getConc()[0];
        b += D*newgrid[tamp[i]]->getConc()[1];
        c += D*newgrid[tamp[i]]->getConc()[2];
      }
      
    }
  }

  grid_ = newgrid;
  delete[] newgrid;
}

void Envir::division()
{
  
}


void Envir::renewal(float f)
{
  //renew the culture media 
  for(int i=0; i<W_; i++){
    for(int j=0; j<H_; j++){
	   grid_[getConc(0)=Ainit;
	   grid_[i*W_+j]->getConc(1)=0;
	   grid_[i*W_+j]->getConc(2)=0;
	  }
  }
}


void Envir::run(int rounds)
{
  for (int i=0;i<rounds;i++)
  {
    if (i%T_==0) //if it's time to renew the medium
    {
      renewal();
    }
  }
}
