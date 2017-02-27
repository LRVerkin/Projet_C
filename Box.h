#ifndef BOX_H
#define BOX_H 

//==============================
//    INCLUDES
//==============================

#include <vector>
#include "Cell.h"

using std::vector;

/**
 * @class Box
 * @brief Creates a box
 */

class Box
{
public:
//==============================
//    CONSTRUCTORS
//==============================
Box();

//==============================
//    DESTRUCTOR
//==============================
virtual ~Box();

//==============================
//    GETTERS
//==============================

inline vector<float> getConc();

//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
void death();
void Mutation(LCell cell);
void Mutation(SCell cell);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
vector <float> conc_;
float diffusionspeed_;
Cell *cellptr_;
float Pmut_;

};

//==============================
//    GETTER DEFINITION
//==============================

inline vector<float> Box::getConc()
{
	return conc_;
}

//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // BOX_H