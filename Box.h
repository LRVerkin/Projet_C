#ifndef BOX_H
#define BOX_H 

//==============================
//    INCLUDES
//==============================

#include <vector>
#include <typeinfo>
#include "Cell.h"
#include "SCell.h"
#include "LCell.h"

using std::vector;
using std::rand;

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
Box(char c);

//==============================
//    DESTRUCTOR
//==============================
~Box();

//==============================
//    GETTERS
//==============================

inline vector<float> getConc();
inline Cell* getCell();

//==============================
//    SETTERS
//==============================

inline void setConc(float a, float b, float c);
inline void setCell(Cell* c);
//inline void setCell(SCell* c);

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
void death();
void Mutation(Cell* cell);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
float pMut_;
vector <float> conc_;
float pDeath_;
Cell* cellptr_;


};

//==============================
//    GETTER DEFINITION
//==============================

inline vector<float> Box::getConc()
{
	return conc_;
}

inline Cell* Box::getCell()
{
	return cellptr_;
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

/*inline void Box::setCell(SCell* c)
{
	cellptr_ = c;
}*/

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // BOX_H
