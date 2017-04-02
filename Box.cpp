//==============================
//    INCLUDES
//==============================

#include <cassert>
#include "Box.h"

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================

Box::Box() : pMut_(0), pDeath_(0.1)
{
  conc_.push_back(50);
  conc_.push_back(0);
  conc_.push_back(0);

  cellptr_ = nullptr;
}

Box::Box(char c) : Box()
{
  conc_.push_back(50);
  conc_.push_back(0);
  conc_.push_back(0);

  if (c=='L') 
  {
    cellptr_ = new LCell();
  }
  else 
  {
    cellptr_ = new SCell();
  }
  
}

Box::Box(const Box& b) : pMut_(0), pDeath_(0.1)
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
  /*if (cellptr_!=nullptr){
  	delete cellptr_;
    cellptr_ = nullptr;
  }*/
  //cellptr_ n'est pas alloué manuellement
}

//==============================
//    PUBLIC METHODS
//==============================

void Box::death()
{

  /*
  Cell has a pDeath chance to die:
  - its metabolites spread into the box;
  - cellptr is deleted then set to nullptr.
  */

  if ((double)(rand() / (double)RAND_MAX) < pDeath_)
  {
    if (cellptr_!= nullptr)
    {
      conc_.at(0) += cellptr_->getP().at(0);
      conc_.at(1) += cellptr_->getP().at(1);
      conc_.at(2) += cellptr_->getP().at(2); 
      
      delete cellptr_;
      cellptr_ = nullptr;
    }
  }
  
}

void Box::Mutation(){

  /*
  Cell has a pMut chance of mutating
  (if L: becomes S)
  (if S: becomes L)
  */

  if ((rand()%1000)/1000 < pMut_)
  {
    float a = cellptr_->getP()[0];
    float b = cellptr_->getP()[1];
    float c = cellptr_->getP()[2];

    delete cellptr_; 

    if (cellptr_->LorS()=='L')
    {
      cellptr_ = new SCell(a,b,c);
    }
    else
    {
      cellptr_ = new LCell(a,b,c);
    }
    
  }
}
