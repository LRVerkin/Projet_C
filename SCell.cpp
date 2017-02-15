//==============================
//    INCLUDES
//==============================
#include "SCell.h"
#include <cmath>
#include <iostream>


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================


//==============================
//    CONSTRUCTORS
//==============================
SCell::SCell(){
	Rbb_ = 0.1;
	Rbc_ = 0.1;
}

SCell::SCell(float a, float b, float c)
{
	Rbb_ = 0.1;
	Rbc_ = 0.1;
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
	if (p_[2] < WMIN)
	{
		return 0;
	}
	else{
		return p_[2];
	}
}

vector<float> SCell::Metabolism(vector<float> conc, float t){
	conc.at(1) = ;
	p_.at(1) = ;
	p_.at(2) = ;

	return conc;
}