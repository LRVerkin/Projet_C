//==============================
//    INCLUDES
//==============================
#include <vector>
#include <algorithm>
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
  vector<int> index;
  for (int i=0;i<W_*H_;i++){
    index.push_back(i);
  }
  std::random_shuffle(index.begin(),index.end());
  for (int i=0;i<(W_*H_)/2;i++){
    grid_[index[i]/W_][index[i]%W_]->setCell(LCell());
    grid_[index[i+(W_*H_)/2]/W_][index[i(W_*H_)/2]%W_]->setCell(SCell());
  }
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
    if(grid_[i/W_][i%W_].cellptr_!=nullptr)
    {
	  findGaps.erase(i);
    }
  }
  random.shuffle(findGaps);
  for(int k=0; k<size(findGaps); k++)
  {
    vector<Cell> *cells; //cells around the gap 
    // 1  2  3 
    // 8  .  4
    // 7  6  5
    int i = findGaps[i]/W_;
    int j = findGaps[i]%W_;
    int i_less = i-1;
    int i_plus = i+1;
    int j_less = j-1;
    int j_plus = j+1;   
    if(i_less<0) i_less = H_-1; // toroidal map
    if(i_plus>H_-1) i_plus = 0; 
    if(j_less<0) i_less = W_-1; 
    if(j_plus>W_-1) j_plus = 0;
    cells->push_back(grid_[i_less][j_less]); //1
    cells->push_back(grid_[i_less][j]);  //2
    cells->push_back(grid_[i_less][j_plus]);  //3
    cells->push_back(grid_[i][j_plus]);  //4
    cells->push_back(grid_[i_plus][j_plus]);  //5
    cells->push_back(grid_[i_plus][j]);  //6
    cells->push_back(grid_[i_plus][j_less]);  //7
    cells->push_back(grid_[i][j_less]);  //8
    random.shuffle(cells);
    Cell betterCell = cells[0]; 
    for(int n=1; n<9; n++) // find the cell with the better fitness
    {
	  if(cell.w_ > betterCell.w_) betterCell = cell;
	}
	inline vector<float> conc = betterCell.getP();
	betterCell.p_/2;
	grid_[i][j]=new Cell(conc[0],conc[1],conc[2]);
	// MAKE MUTATION
	
  }
}

void Envir::renewal(float f)
{
  //renew the culture media 
  for(int i=0; i<W_; i++){
    for(int j=0; j<H_; j++){
	  grid_[i][j].getConc()[0]=f;
	  grid_[i][j].getConc()[1]=0;
	  grid_[i][j].getConc()[2]=0;
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
