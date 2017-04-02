//==============================
//    INCLUDES
//==============================
#include "SCell.h"



//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
SCell::SCell() : Cell(), Rbb_(0.1), Rbc_(0.1)
{
	w_ = Fitness();
}

SCell::SCell(float a, float b, float c) : Cell(a,b,c), Rbb_(0.1), Rbc_(0.1)
{
	w_ = Fitness();
}


//==============================
//    DESTRUCTOR
//==============================
SCell::~SCell(){
}

//==============================
//    PUBLIC METHODS
//==============================

float SCell::Fitness()
{

  /*
  updates fitness and returns it
  */

  if (p_.at(2) < WMIN_)
  {
    w_ = 0;
  }
  else
  {
    w_ = p_.at(2);
  }

  return w_;
}

void SCell::Metabolism(vector<float> conc, float dt)
{

  /*
  metabolites (in cell and in box) vary
  according to the equations that rule SCell metabolism.
  Fitness is updated
  */

  conc.at(1) += - conc.at(1) * Rbb_ * dt;
  p_.at(1) += (conc.at(1) * Rbb_ - p_.at(1) * Rbc_) * dt;
  p_.at(2) += conc.at(1) * Rbc_ * dt;
  Fitness();
}

char SCell::LorS()
{
  return 'S';
}
