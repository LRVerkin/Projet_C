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
  grid_ = new Box*[W_];
  for (int i=0;i<W_;i++){
    grid_[i] = new int[H_];
  }
  renewal(Ainit_); //initialize the culture media
  pDeath = 0.02;
  pMut = pm;
  
}

//==============================
//    DESTRUCTOR
//==============================
Envir::~Envir()
{
  for (int i=0;i<H_;i++)
  {
    delete[] grid_[i];
  }

  delete[] grid_;
}

//==============================
//    PUBLIC METHODS
//==============================
void Envir::diffusion()
{
  Box** newgrid = new Box*[W_];
  for (int k=0;k<W_;k++){
    newgrid[k] = new Box[H_];
  }

  float a = 0;
  float b = 0;
  float c = 0;
  int x = 0;
  int y = 0;

  /*prepare array of random indices so we can
  * diffuse at random*/
  vector<int> indices;
  for (k=0;k<W_*H_;k++){
    indices.push_back(k);
  }
  random_shuffle(indices.begin(),indices.end());


  for (k=0;k<W_*H_;k++){
    x = indices[k]/W_;
    y = indices[k]%W_;
    /*x and y may change later on so 
    * we need to do this now*/
    a = -grid_[x][y]->getConc()[0];
    b = -grid_[x][y]->getConc()[1];
    c = -grid_[x][y]->getConc()[2];
    for (int i=-1;i<=1;i++){
      for (int j=-1;j<=1;j++){
        a = grid_[x][y]->getConc()[0];
        b = grid_[x][y]->getConc()[1];
        c = grid_[x][y]->getConc()[2];
        //stream of cases
        if(x+i<0){
          x = H_-1;
        }
        if(x+i==H_){
          x = 0;
        }
        if(y+j<0){
          y = W_-1;
        }
        if(y+j==W_){
          y = 0;
        }
        a += D_*grid_[x][y]->getConc()[0];
        b += D_*grid_[x][y]->getConc()[1];
        c += D_*grid_[x][y]->getConc()[2];
      }
    }
    //x and y may have been changed, so we're using their initial value
    newgrid[indices[k]/W_][indices[k]%W_]->setConc(a,b,c);
  }  

  //destroy newgrid
  grid_ = newgrid;
  for (i=0;i<H_;i++)
  {
    delete[] newgrid[i];
  }
  delete[] newgrid;

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
