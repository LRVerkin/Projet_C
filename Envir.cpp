//==============================
//    INCLUDES
//==============================
#include "Envir.h"
#include "Box.h"

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
Envir::Envir(float T, float Ainit)
{
  W_ = 32;
  H_ = 32;
  T_=T;
  t = 0;
  Box grid_[W_][H_];
  renewal();
  
}

//==============================
//    DESTRUCTOR
//==============================
Envir::~Envir()
{
  
}

//==============================
//    PUBLIC METHODS
//==============================
void diffusion()
{
}

void division()
{
  
}

void renewal()
{
  //renew the culture media 
  for(int i=0; i<W_; i++){
    for(int j=0; j<H_; j++){
	  grid_[i][j].conc_[0]=Ainit;
	  grid_[i][j].conc_[1]=0;
	  grid_[i][j].conc_[2]=0;
	}
  }
}

void run(){
}
