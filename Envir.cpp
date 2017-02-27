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
  Ainit_=A;
  //W_ = 32;
  //H_ = 32;
  T_=T;
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
  for (int i=0;i<rounds;i++)
  {
    if (i%T_==0) //if it's time to renew the medium
    {
      renewal();
    }
  }
}
