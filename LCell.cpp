//==============================
//    INCLUDES
//==============================
#include "LCell.h"
#include <cmath>
#include <iostream>


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
LCell::LCell(){
	Raa_ = 0.1;
	Rab_ = 0.1;
}

LCell::LCell(float a, float b, float c)
{
	Rab_ = 0.1;
	Rab_ = 0.1;
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
	if (p_[1] < WMIN){
		return 0;
	}
	else {
		return p_[1];
	}
}

vector<float> LCell::Metabolism(vector<float> conc,float t){
	conc.at(0) = exp(-Raa*t);
	p_.at(0) = ;
	p_.at(1) = ;

	return conc;
}