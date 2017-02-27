#ifndef BOX_H
#define BOX_H 

//==============================
//    INCLUDES
//==============================

#include <vector>
#include "Cell.h"
#include "SCell.h"
#include "LCell.h"

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
inline void setCell(LCell* c);
inline void setCell(SCell* c);

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

inline void Box::setConc(float a, float b, float c)
{
	vector<float> tamp{a,b,c};
	conc_ = tamp;
}

inline void Box::setCell(LCell* c)
{
	cellptr_ = c;
}

inline void Box::setCell(SCell* c)
{
	cellptr_ = c;
}

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // BOX_H