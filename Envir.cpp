//==============================
//    INCLUDES
//==============================
#include "Envir.h"

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
Envir::Envir(float T, float A, float pm)
{
  Ainit_= A;
  //W_ = 32;
  //H_ = 32;
  T_= T;
  t_ = 0;
  grid_ = new Box[H_*W_]; /*advised way to do a 2D array in C++:
  * do it in 1D and access it with offsets.
  * To access box [i][j] : grid_[i * W_ + j] */
  renewal(Ainit_); //initialize the culture media
  pDeath = 0.02;
  pMut = pm;
  
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
void Envir::diffusion()
{
  
}

void Envir::division()
{
  vector<int>findGaps[W_*H_];
  for(int i=0; i<W_*H_; i++)
  {
    if(grid_[i].cellptr_!=nullptr)
    {
	  findGaps.erase(i);
    }
  }
  random.shuffle(findGaps);
  for(int i=0; i<size(findGaps); i++)
  {
    vector<Cell> *cells_; //cells around the gap
    if(findGaps[i]<W_)
    {
	  if(findGaps[i]=0) //topleft
	  {
		cells_.push_back(); /////////////////TO DO//////////////////
	  }
	  else if(findGaps[i]=W_-1) //topright
	  {
		
	  }
	  else //top 
	  { 
		  
	  }
    }
  }
}

void Envir::renewal(float f)
{
  //renew the culture media 
  for(int i = 0; i < W_; i++){
    for(int j = 0; j < H_; j++){
	  grid_[i*W_ + j].getConc()[0] = f;
	  grid_[i*W_ + j].getConc()[1] = 0;
	  grid_[i*W_ + j].getConc()[2] = 0;
	}
  }
}

void Envir::run(int rounds)
{
  for (int i = 0;i < rounds;i++)
  {
    if (i%T_ == 0) //if it's time to renew the medium
    {
      renewal();
    }
  }
}
