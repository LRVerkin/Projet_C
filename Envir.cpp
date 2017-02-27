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
Envir::Envir(float T, float A, float pm) : t_(0), pDeath_(0.02), D_(0.1)
{
  Ainit_= A;
  T_= T;
  grid_ = new Box*[H_];
  for (int i=0;i<H_;i++){
    grid_[i] = new Box[W_];
  }

  renewal(Ainit_); //initialize the culture media
  pMut_ = pm;
  
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
  for (int k=0;k<W_*H_;k++){
    indices.push_back(k);
  }
  random_shuffle(indices.begin(),indices.end());


  for (int k=0;k<W_*H_;k++){
    x = indices[k]/W_;
    y = indices[k]%W_;
    /*x and y may change later on so 
    * we need to do this now*/
    a = -grid_[x][y].getConc()[0];
    b = -grid_[x][y].getConc()[1];
    c = -grid_[x][y].getConc()[2];
    for (int i=-1;i<=1;i++){
      for (int j=-1;j<=1;j++){
        a = grid_[x][y].getConc()[0];
        b = grid_[x][y].getConc()[1];
        c = grid_[x][y].getConc()[2];
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
        a += D_*grid_[x][y].getConc()[0];
        b += D_*grid_[x][y].getConc()[1];
        c += D_*grid_[x][y].getConc()[2];
      }
    }
    //x and y may have been changed, so we're using their initial value
    newgrid[indices[k]/W_][indices[k]%W_].setConc(a,b,c);
  }  

  //destroy newgrid
  grid_ = newgrid;
  for (int i=0;i<H_;i++)
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
    if(grid_[i/W_][i%W_].cellptr_!=nullptr)
    {
	  findGaps.erase(i);
    }
  }
  random.shuffle(findGaps);
  for(int k=0; k<size(findGaps); k++)
  {
    int x = findGaps[k]/W_;
    int I[3];
    for(int n=-1, n<=1, n++) I[1+n]=x+n;
    
    int y = findGaps[k]%W_;
    int J[3];
    for(int n=-1, n<=1, n++) J[1+n]=y+n;
    
    if(I[0]<0) I[0] = H_-1; // toroidal map
    if(I[2]>H_-1) I[2] = 0; 
    if(J[0]<0) J[0] = W_-1; 
    if(J[2]>W_-1) J[2] = 0;
    
    vector<Cell> *cells; //cells around the gap 
    for(i=0; i<=2; i++){
	  for(j=0; j<=2; j++){
	    if (i!=1 && j!=1) cells->push_back(grid_[I[i]][J[j]]);
	  }
	}
    // 1  2  3 
    // 4  .  5
    // 6  7  8
    random.shuffle(cells);
    
    Cell betterCell = cells[0]; 
    for(int n=1; n<9; n++) // find the cell with the better fitness
    {
	  if(cell.w_ > betterCell.w_) betterCell = cell;
	}
	
	inline vector<float> conc = betterCell.getP();
	betterCell.p_/2;
	Mutation(betterCell);
	if(type(betterCell)==LCell) grid_[i][j]=new LCell(conc[0],conc[1],conc[2]);
	else grid_[i][j]=new SCell(conc[0],conc[1],conc[2]);
  }
}

void Envir::renewal(float f)
{
  //renew the culture media 
  for(int i=0; i<W_; i++){
    for(int j=0; j<H_; j++){
	  grid_[i][j].setConc(f,0,0);
	  }
  }
}

void Envir::run(int rounds)
{
  for (int i = 0;i < rounds;i++)
  {
    if (i%T_ == 0) //if it's time to renew the medium
    {
      renewal(Ainit_);
    }

    t_ += 0.1;
  }
}
