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
    cellptr_ = new LCell();
  }
  else {
    cellptr_ = new SCell();
  }
  
}

Box::Box(const Box& b) : pMut_(0), pDeath_(0.02)
{
  conc_.push_back(b.getconstConc()[0]);
  conc_.push_back(b.getconstConc()[1]);
  conc_.push_back(b.getconstConc()[2]);
  cellptr_ = b.cellptr_;
}

//==============================
//    DESTRUCTOR
//==============================
Box::~Box()
{
  if (cellptr_!=nullptr){
  	delete cellptr_;
  }
}

//==============================
//    PUBLIC METHODS
//==============================

void Box::death()
{
  if ((double)(rand() / (double)RAND_MAX) < pDeath_){
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
