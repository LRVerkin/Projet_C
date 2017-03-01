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

Box::Box() : pMut_(0),cellptr_(nullptr)
{
  conc_.push_back(50);
  conc_.push_back(0);
  conc_.push_back(0);
}

Box::Box(const Box& b) : diffusionspeed_(0.1)
{
  conc_[0] = b.getConc[0];
  conc_[1] = b.getConc[1];
  conc_[2] = b.getConc[2];
  cellptr_ = b.cellptr_;
}

//==============================
//    DESTRUCTOR
//==============================
Box::~Box()
{
  delete cellptr_;
}

//==============================
//    PUBLIC METHODS
//==============================
void Box::death()
{
  if (cellptr_!= nullptr){
    conc_.at(0) += cellptr_->getP().at(0);
    conc_.at(1) += cellptr_->getP().at(1);
    conc_.at(2) += cellptr_->getP().at(2); 
    cellptr_ = nullptr;
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
