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

void Mutation(LCell cell){
  float v = static_cast<float>(rand())/static_cast<float>(RAND_MAX); // float between 0 and 1 included
  if (v < pMut_){
    SCell();
    ~cell 
  }
}

void Mutation(SCell cell){
  float v = static_cast<float>(rand())/static_cast<float>(RAND_MAX); // float between 0 and 1 included
  if (v < pMut_){
    LCell();
    ~cell 
  }
}