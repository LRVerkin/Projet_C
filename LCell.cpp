//==============================
//    INCLUDES
//==============================
#include "LCell.h"



//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
LCell::LCell() : Cell(), Raa_(0.1), Rab_(0.1) 
{
	w_ = Fitness();
}

LCell::LCell(float a, float b, float c) : Cell(a,b,c), Raa_(0.1), Rab_(0.1)
{
	w_ = Fitness();
}


//==============================
//    DESTRUCTOR
//==============================
LCell::~LCell(){
}

//==============================
//    PUBLIC METHODS
//==============================

float LCell::Fitness()
{

  /*
  updates fitness and returns it
  */

  if (p_.at(1) < WMIN_)
  {
    w_ = 0;
  }
  else 
  {
    w_ = p_.at(1);
  }

  return w_;
}

void LCell::Metabolism(vector<float> conc,float dt)
{

  /*
  metabolites (in cell and in box) vary
  according to the equations that rule LCell metabolism.
  Fitness is updated
  */

  conc.at(0) += - conc.at(0) * Raa_ * dt;
  p_.at(0) += (conc.at(0) * Raa_ - p_.at(0) * Rab_) * dt;
  p_.at(1) += p_.at(0) * Rab_ * dt;
  Fitness();
}

char LCell::LorS()
{
  return 'L';
}
