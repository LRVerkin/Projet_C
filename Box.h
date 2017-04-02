#ifndef BOX_H
#define BOX_H 

//==============================
//    INCLUDES
//==============================

#include <vector>
#include <typeinfo>
#include "SCell.h"
#include "LCell.h"

using std::vector;
using std::rand;
using std::ostream;

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
Box(const Box& b);

//==============================
//    DESTRUCTOR
//==============================
~Box();

//==============================
//    GETTERS
//==============================

inline vector<float> 			getconstConc() const;
inline vector<float> 			getConc();
inline Cell* 					getCell();

//==============================
//    SETTERS
//==============================


inline void 					setConc(float a, float b, float c);
inline void 					setCell(Cell* c);
//inline void setCell(SCell* c);

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
friend ostream 					&operator<<(ostream &os, Box const &b);
void 							death();
void 							Mutation();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

float 							pMut_;
vector <float> 					conc_;
float 							pDeath_;
Cell* 							cellptr_;



};

//==============================
//    GETTER DEFINITION
//==============================

inline vector<float> Box::getconstConc() const
{
	return conc_;
}

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
	//delete cellptr_; //gives seg fault
	cellptr_ = c;
}


//==============================
//    OPERATOR DEFINITION
//==============================

inline std::ostream &operator<<(std::ostream &os, Box const &b) 
{ 
    return os << "pMut_ = " << b.pMut_ << " pDeath_ = " << b.pDeath_ << " and cellptr_ = " << b.cellptr_ <<std::endl;
}



#endif // BOX_H
