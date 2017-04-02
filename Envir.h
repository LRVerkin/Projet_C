#ifndef ENVIR_H
#define ENVIR_H 

//==============================
//    INCLUDES
//==============================

#include <vector>
#include <algorithm>
#include "Box.h"


/**
 * @class Envir
 * @brief Creates an environment
 */

class Envir
{
public:
//==============================
//    CONSTRUCTORS
//==============================

Envir();
Envir(float T, float A);

//==============================
//    DESTRUCTOR
//==============================
~Envir();

//==============================
//    GETTERS
//==============================


//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
void 			diffusion();
void 			division();
void 			renewal(float A);
void 			run(int rounds); //number of rounds


//==============================
//    PUBLIC ATTRIBUTES
//==============================

std::string 			state;

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
static const int 	W_ = 32;
static const int 	H_ = 32;
float 						T_; //number of rounds between each renewal of the culture media
float 						dt_;
float 						Ainit_; // initial concentration of A
Box** 						grid_;
float 						D_; // diffusion coefficient
};

//==============================
//    GETTER DEFINITION
//==============================


//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // ENVIR_H
