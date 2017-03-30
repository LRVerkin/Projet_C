//==============================
//    INCLUDES
//==============================

#include "Envir.h"

using std::random_shuffle;
using std::string;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
Envir::Envir(float T, float A) : t_(0), D_(0.1)
{
  Ainit_= A;
  T_= T;
  grid_ = new Box*[W_];
  for (int i=0;i<W_;i++){
    grid_[i] = new Box[H_];
  }

  std::cout<< "grid_ initialized" <<std::endl;

  vector<int> index;
  for (int i=0;i<W_*H_;i++){
    index.push_back(i);
  }
  random_shuffle(index.begin(),index.end());

  std::cout<< "index created" <<std::endl;

  for (int i=0;i<(W_*H_)/2;i++){
    grid_[index[i]/W_][index[i]%W_].setCell(new LCell);
    grid_[index[i+(W_*H_)/2]/W_][index[i+(W_*H_)/2]%W_].setCell(new SCell);
    //I need to use "new" or else the cell will always be the same
  }

  std::cout << "got cells in boxes" << std::endl;

  renewal(Ainit_); //initialize the culture media



  
}

//==============================
//    DESTRUCTOR
//==============================
Envir::~Envir()
{
  for (int i=0;i<H_;i++)
  {
    /*for (int j=0;j<W_;j++){
      delete grid_[i][j].getCell();
    }*/

    for (int j=0;j<W_;j++)
    {
      delete grid_[i][j].getCell();
    }

    delete[] grid_[i];
  }

  delete grid_;
}

//==============================
//    PUBLIC METHODS
//==============================
void Envir::diffusion()
{

  Box** newgrid = new Box*[W_];
  for (int k=0;k<W_;k++){
    for (int j=0;j<H_;j++){
      newgrid[k] = new Box[H_];
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


  std::cout << "Getting into the copying loop (at long freaking last)" << std::endl;
  for (int i=0;i<H_;i++)
  {
    for (int j=0;j<W_;j++){
      //std::cout << "newgrid[" << i << "][" << j << "] : " << newgrid[i][j];
      grid_[i][j].setConc(newgrid[i][j].getConc()[0],newgrid[i][j].getConc()[1],newgrid[i][j].getConc()[2]);
      //std::cout << "grid_[" << i << "][" << j << "] : " << grid_[i][j];

    }
    delete[] newgrid[i];
  }
  delete newgrid;

}

void Envir::division()
{
  vector<int> findGaps;
  for(int i=0; i<W_*H_; i++)
  {
    //std::cout << "grid_[" << i/W_ << "][" << i%W_ << "] : " << grid_[i/W_][i%W_];
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
          //std::cout << "grid_[" << I[i] << "][" << J[j] << "] : " << grid_[I[i]][J[j]];

        }
      }
    }
    /* 
       I don't know why but grid_[I[i]][J[j]].getCell()->Fitness() don't work
    */
    
    // 1  2  3 
    // 4  .  5
    // 6  7  8
    
    Box* bestBox;
    bool bBox1 = false;
    for(int n=0; n<8; n++){ // find a first cell
      if(bBox1==false && boxes[n].getCell()!=nullptr){  //the firt box tested to be the best box must not be empty
          bestBox = new Box(boxes[n]);
          bBox1=true;
      }
    }
    
    if(bBox1==true){
      for(int n=0; n<8; n++){ // find the cell with the better fitness
        //std::cout << "get into problematic loop, n = " << n << std::endl;
        if(boxes[n].getCell()!=nullptr && boxes[n].getCell()!=bestBox->getCell()){
          //std::cout << "best box : " << bestBox->getCell() << " has fitness : " << bestBox->getCell()->Fitness() << std::endl;
          //std::cout << "other box : " << boxes[n].getCell() << " has fitness : " << boxes[n].getCell()->Fitness() << std::endl;
          if (bestBox->getCell()->Fitness() < boxes[n].getCell()->Fitness()){
            //std::cout<< "get into second loop" << std::endl;
            bestBox = new Box(boxes[n]);
          }
        }
      }
    }
    
    /* PROBLEMS :
       
       As the fitness is always null (no metabolism of cells before use fitness() -> [B]=[C]=0)
       we never change bestBox
      
    */

    vector<float> conc = bestBox->getCell()->getP();
    bestBox->getCell()->setP(conc[0]/2,conc[1]/2,conc[2]/2);
    bestBox->Mutation(bestBox->getCell());
    if(bestBox->getCell()->LorS()=='l') grid_[x][y].setCell(new LCell(conc[0]/2,conc[1]/2,conc[2]/2));
    else grid_[x][y].setCell(new SCell(conc[0]/2,conc[1]/2,conc[2]/2));
    
    delete bestBox;
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

  std::cout << "Size at beginning: " << std::endl;
  std::cout << grid_[0][0].getCell()->getP().size() << std::endl;


  for (int i = 0;i < rounds*10;i++)
  {

    std::cout<< "round " << i << std::endl;

    //POSSIBLE RENEWAL
    if (i%int(T_) == 0) //if it's time to renew the medium
    {
      renewal(Ainit_);
      std::cout << "Renewal over" << std::endl;
    }

    
    vector<int> browse; //will be used to browse grid_
    for (int k=0;k<W_*H_;k++)
    {
      browse.push_back(k);
    }
    std::random_shuffle(browse.begin(),browse.end());
    


    std::cout << "Onto diffusion" << std::endl;

    //METABOLITES DIFFUSE
    diffusion();

    std::cout << "Diffusion over" << std::endl;


    std::cout << "Deaths are about to occur" << std::endl;

    //std::cout << "grid_[" << 0 << "][" << 0 << "] : " << grid_[0][0] << std::endl;
    //std::cout << "grid_[" << 5 << "][" << 20 << "] : " << grid_[5][20] << std::endl;

    

    //RANDOM DEATHS AMONG INDIVIDUALS
    for(int k = 0;k<W_;k++){
      for (int i=0;i<H_;i++){
        //std::cout << "Cell " << grid_[k][i].getCell() << std::endl;
        grid_[k][i].death();
      }
    }

    std::cout<<"Some cells died" << std::endl;

    for(int k = 0;k<W_;k++){
      for (int i=0;i<H_;i++){
        //std::cout << "grid_[" << k << "][" << i << "] = " << grid_[k][i] << std::endl;
        if (grid_[k][i].getCell()!=nullptr) {
          //std::cout << "Fitness = " << grid_[k][i].getCell()->Fitness() << std::endl;
        }
      }
    }

    std::cout << "division about to start" << std::endl;


    //DIVISION
    division();
    std::cout << "division done" << std::endl;


    //INDIVIDUALS ADAPT THEIR METABOLISM
    vector<int> ran;
    ran.reserve(W_*H_);
    for (int i=0;i<W_*H_;i++){
      ran.push_back(i);
    }
    random_shuffle(ran.begin(),ran.end());
    for (int i=0;i<W_*H_;i++){
      grid_[ran[i]/W_][ran[i]%W_].getCell()->Metabolism(grid_[ran[i]/W_][ran[i]%W_].getConc(),t_);
    }

    std::cout << "Metabolism done" << std::endl;


    t_ += 0.1;
  }
  
  // STATE OF THE POPULATION
  int nLcell = 0;
  int nScell = 0;
  for(int i=0; i<W_; i++){
    for(int j=0; j<H_; j++){
	   if(grid_[i][j].getCell()->LorS()=='l') nLcell++;
	   if(grid_[i][j].getCell()->LorS()=='s') nScell++;
	 }
  }
  if(nScell == 0){
	 if(nLcell == 0) state = "Extinction";
	 else state = "Exclusion";
  } else state = "Cohabitation";
  
  std::cout << state << std::endl;
  
}
