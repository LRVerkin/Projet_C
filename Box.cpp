//==============================
//    INCLUDES
//==============================

#include "Box.h"

using std::rand;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Box::Box() : pMut_(0), pDeath_(0.02)
{
  conc_.push_back(50);
  conc_.push_back(0);
  conc_.push_back(0);
  cellptr_ = nullptr;
}

Box::Box(char c) : pMut_(0), pDeath_(0.02)
{
  conc_.push_back(50);
  conc_.push_back(0);
  conc_.push_back(0);
  if (c=='L') {
    LCell* lc = new LCell();
    cellptr_ = lc;
  }
  else {
    SCell* sc = new SCell();
    cellptr_ = sc;
  }
  
}

//==============================
//    DESTRUCTOR
//==============================
Box::~Box()
{
  
}

//==============================
//    PUBLIC METHODS
//==============================
void Box::death()
{
  if ( (double)rand() / RAND_MAX <pDeath_){
    if (cellptr_!= nullptr){
      conc_.at(0) += cellptr_->getP().at(0);
      conc_.at(1) += cellptr_->getP().at(1);
      conc_.at(2) += cellptr_->getP().at(2); 
      cellptr_ = nullptr;
    }
  }
  
}

void Box::Mutation(Cell* cell){
  float v = (rand()%1000)/1000; // float between 0 and 1 included
  if (v < pMut_){
    float a = cell->getP()[0];
    float b = cell->getP()[1];
    float c = cell->getP()[2];
    if (typeid(*cell)==typeid(LCell))
    {
      SCell(a,b,c);
    }
    else //ie si le type est SCell
    {
      LCell(a,b,c);
    }
    delete cell; 
  }
}
