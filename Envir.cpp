//==============================
//    INCLUDES
//==============================
#include <iostream>
#include <chrono>
#include "Envir.h"

using std::random_shuffle;
using std::string;

typedef std::chrono::high_resolution_clock Clock;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
Envir::Envir() : dt_(0.1), D_(0.1)
{
  Ainit_= 50;
  T_= 10;
  nLcell = 0;
  nScell = 0;

  grid_ = new Box*[W_];
  for (int i=0;i<W_;i++)
  {
    grid_[i] = new Box[H_];
  }


  //created so we can simulate randomness
  vector<int> index;
  for (int i=0;i<W_*H_;i++)
  {
    index.push_back(i);
  }
  random_shuffle(index.begin(),index.end());


  for (int i=0;i<(W_*H_)/2;i++){
    grid_[index[i]/W_][index[i]%W_].setCell(new LCell);
    grid_[index[i+(W_*H_)/2]/W_][index[i+(W_*H_)/2]%W_].setCell(new SCell);
  }


  renewal(Ainit_); //initialize the culture media
  
}


Envir::Envir(float T, float Ainit) : Envir()
{
  Ainit_ = Ainit;
  T_ = T;
  renewal(Ainit_);
}

//==============================
//    DESTRUCTOR
//==============================
Envir::~Envir()
{
  for (int i=0;i<H_;i++)
  {

    for (int j=0;j<W_;j++)
    {
      delete grid_[i][j].getCell();
    }

    delete[] grid_[i];
  }

  delete[] grid_;
}

//==============================
//    PUBLIC METHODS
//==============================
void Envir::diffusion()
{

  /*
  All over the grid, metabolites diffuse from each box to its neighbours
  */

  Box** newgrid = new Box*[W_];
  for (int k=0;k<W_;k++)
  {
    for (int j=0;j<H_;j++)
    {
      newgrid[k] = new Box[H_];
      newgrid[k][j].setCell(new LCell);
      newgrid[k][j].setConc(grid_[k][j].getConc()[0],grid_[k][j].getConc()[1],grid_[k][j].getConc()[2]);
    }
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

    newgrid[indices[k]/W_][indices[k]%W_].setConc(a,b,c);
  }  


  for (int i=0;i<H_;i++)
  {
    for (int j=0;j<W_;j++)
    {
      grid_[i][j].setConc(newgrid[i][j].getConc()[0],newgrid[i][j].getConc()[1],newgrid[i][j].getConc()[2]);
      delete newgrid[i][j].getCell();


    }
    delete[] newgrid[i];
  }
  delete[] newgrid;

}

void Envir::division()
{

  /*
  When a gap is found, the fittest cell divides to fill the gap.
  The mother cell has a pMut chance to mutate and the two daughters have the same mutation.
  The mother cell keeps a half of its metabolites and gives the other
  half to its daughter cell.
  */

  vector<int> findGaps;
  for(int i=0; i<W_*H_; i++)
  {
    if(grid_[i/W_][i%W_].getCell()==nullptr)
    {
	  findGaps.push_back(i);
    }
  }
  random_shuffle(findGaps.begin(),findGaps.end());
  for(unsigned int k=0; k<findGaps.size(); k++)
  {
    int x = findGaps[k]/W_;
    int I[3];
    for(int n=-1; n<=1; n++) I[1+n]=x+n;
    
    int y = findGaps[k]%W_;
    int J[3];
    for(int n=-1; n<=1; n++) J[1+n]=y+n;
    
    if(I[0]<0) I[0] = H_-1; // toroidal map
    if(I[2]>H_-1) I[2] = 0; 
    if(J[0]<0) J[0] = W_-1; 
    if(J[2]>W_-1) J[2] = 0;
    
    vector<Box> boxes; //cells around the gap 
    boxes.reserve(8);
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        if (i != 1 || j != 1) {
          boxes.push_back(grid_[I[i]][J[j]]);

        }
      }
    }

    
    // 1  2  3 
    // 4  .  5
    // 6  7  8
    
    Box* bestBox;
    bool bBox1 = false;
    for(int n=0; n<8; n++)
    { // find a first cell
      if(bBox1==false && boxes[n].getCell()!=nullptr)
      {  //the firt box tested to be the best box must not be empty
          bestBox = new Box(boxes[n]);
          bBox1=true;
      }
    }
    
    if(bBox1==true)
    {
      for(int n=0; n<8; n++)
      {
        if(boxes[n].getCell()!=nullptr && boxes[n].getCell()!=bestBox->getCell())
        {
          if (bestBox->getCell()->Fitness() < boxes[n].getCell()->Fitness())
          {
            bestBox = new Box(boxes[n]);
          }
        }
      }
    }
    

    vector<float> conc = bestBox->getCell()->getP();
    bestBox->getCell()->setP(conc[0]/2,conc[1]/2,conc[2]/2);

    bestBox->Mutation();

    if(bestBox->getCell()->LorS()=='L') grid_[x][y].setCell(new LCell(conc[0]/2,conc[1]/2,conc[2]/2));
    else grid_[x][y].setCell(new SCell(conc[0]/2,conc[1]/2,conc[2]/2));
    
    delete bestBox;
  }
}

void Envir::renewal(float A)
{
  /*
  Renew the culture media:
  B and C are drained
  A goes back to its initial Ainit concentration
  */


  for(int i=0; i<W_; i++)
  {
    for(int j=0; j<H_; j++)
    {
      grid_[i][j].setConc(A,0,0);
    }
  }
}

void Envir::run(int rounds)
{

  /*
  Main method that simulate a given number of rounds:
  - every T rounds, the media is renewed;
  - metabolites diffuse from each cell to its neighbours;
  - some cells die;
  - the fittest cell around a gap gets to divide and fill the gap,
  and it has a chance to mutate
  - cells accomplish their metabolism.
  */


  auto t1 = Clock::now();


  for (int i = 0; i < rounds;i++)
  {


    //POSSIBLE RENEWAL
    if (i%(int)T_ == 0) //if it's time to renew the medium
    {
      renewal(Ainit_);
    }
  

    
    vector<int> browse; //will be used to browse grid_
    for (int k=0;k<W_*H_;k++)
    {
      browse.push_back(k);
    }
    std::random_shuffle(browse.begin(),browse.end());
    

    //METABOLITES DIFFUSE
    diffusion();

    

    //RANDOM DEATHS AMONG INDIVIDUALS
    for(int k = 0;k<W_;k++){
      for (int i=0;i<H_;i++){
        grid_[k][i].death();
      }
    }



    //DIVISION
    division();
    


    //INDIVIDUALS ADAPT THEIR METABOLITE CONCENTRATIONS
    //ACCORDING TO THEIR METABOLISM
    vector<int> ran;
    ran.reserve(W_*H_);
    for (int i=0;i<W_*H_;i++){
      ran.push_back(i);
    }
    random_shuffle(ran.begin(),ran.end());
    for (int i=0;i<W_*H_;i++){
      grid_[ran[i]/W_][ran[i]%W_].getCell()->Metabolism(grid_[ran[i]/W_][ran[i]%W_].getConc(),dt_);
    }


  }
  
  
  
  // STATE OF THE POPULATION
  for(int i=0; i<W_; i++){
    for(int j=0; j<H_; j++){
	   if(grid_[i][j].getCell()->LorS()=='L') nLcell++;
	   if(grid_[i][j].getCell()->LorS()=='S') nScell++;
	 }
  }
  if (nScell == 0 && nLcell == 0) state = "Extinction";
  else if (nScell == 0 && nLcell != 0) state = "Exclusion of SCells by LCells";
  else state = "Cohabitation";
  
  std::cout << "Nombre de LCell : " << nLcell << std::endl;
  std::cout << "Nombre de SCell : " << nScell << std::endl;
  std::cout << state << std::endl;

    
  auto t2 = Clock::now();

  std::cout << "Duration : " 
            << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count()
            << " seconds" << std::endl;
  
}
