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

float LCell::Fitness(){
  std::cout << "calculate fitness" << std::endl;
  if (p_.at(1) < WMIN_){
    //std::cout << "got into LCell, p_[1] < WMIN" << std::endl;
    return 0.0;
  }
  else {
    //std::cout << "LCell with p_[1] > WMIN" << std::endl;
    return p_.at(1);
  }
}

void LCell::Metabolism(vector<float> conc,float t){
  conc.at(0) += -t*conc.at(0)*Raa_;
  p_.at(0) += t*(conc.at(0)*Raa_-p_.at(0)*Rab_);
  p_.at(1) += t*p_.at(0)*Rab_;
  w_ = Fitness();
}

char LCell::LorS(){
  return 'l';
}
