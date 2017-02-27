//==============================
//    INCLUDES
//==============================
#include "LCell.h"
#include <cmath>
#include<cstdlib>
#include <iostream>


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
LCell::LCell() : Raa_(0.1), Rab_(0.1) 
{
	
}

LCell::LCell(float a, float b, float c) : Raa_(0.1), Rab_(0.1)
{
	
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
	if (p_[1] < WMIN_){
		return 0;
	}
	else {
		return p_[1];
	}
}

vector<float> LCell::Metabolism(vector<float>* conc,float t){
	conc->at(0) += -t*conc->at(0)*Raa_;
	p_.at(0) += t*(conc->at(0)*Raa_-p_.at(0)*Rab_);
	p_.at(1) += t*p_.at(0)*Rab_;
	w_ = Fitness();

	return *conc;
}

void Mutation(){
  float v = static_cast<float>(rand())/static_cast<float>(RAND_MAX); // float between 0 and 1 included
  if (v < pMut_){
    // attributes reinitialization
  }
}