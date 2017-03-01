//==============================
//    INCLUDES
//==============================
#include "Box.h"

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Box::Box()
{
  conc_[0] = 50;
  conc_[1] = 0;
  conc_[2] = 0;
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
  conc_[0] = conc_[0] + cellptr_->getP()[0];
  conc_[1] = conc_[1] + cellptr_->getP()[1];
  conc_[2] = conc_[2] + cellptr_->getP()[2]; 
  delete cellptr_;
}

void Mutation(Cell* cell){
  float v = (rand()%1000)/1000; // float between 0 and 1 included
  if (v < pMut_){
    float a = p_[0];
    float b = p_[1];
    float c = p_[2];
    if (typeid(*cell)==typeid(LCell))
    {
      SCell(a,b,c);
    }
    else //ie si le type est SCell
    {
      LCell(a,b,c);
    }
    delete *cell; 
  }
}
