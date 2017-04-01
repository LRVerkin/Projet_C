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
Envir(int T, float A);

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
void 			renewal(float f);
void 			run(int rounds); //number of rounds


//==============================
//    PUBLIC ATTRIBUTES
//==============================

std::string 	state;

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
static const int 	W_ = 32;
static const int 	H_ = 32;
int 				T_;
float 				t_;
float 				Ainit_;
Box** 				grid_;
float 				pMut_;
float 				D_;
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
