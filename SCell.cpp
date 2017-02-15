//==============================
//    INCLUDES
//==============================
#include "SCell.h"
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
	return p_[2];
}

void SCell::Metabolism(float a, float b, float c){
	
}