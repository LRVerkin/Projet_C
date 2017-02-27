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

inline void setConc(float a, float b, float c);
inline void setCell(Cell* c);

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
void death();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
vector <float> conc_;
Cell *cellptr_;

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

inline void Box::setConc(float a, float b, float c)
{
	vector<float> tamp{a,b,c};
	conc_ = tamp;
}

inline void Box::setCell(Cell* c)
{
	cellptr_ = c;
}

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // BOX_H