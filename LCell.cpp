//==============================
//    INCLUDES
//==============================
#include "LCell.h"
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
	return p_[1];
}

void LCell::Metabolism(float a, float b, float c){
	
}