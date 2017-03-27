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
float pMut_;
vector <float> conc_;
float pDeath_;
Cell* cellptr_;
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

inline vector<float> getconstConc() const;
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
friend std::ostream &operator<<(std::ostream &os, Box const &b);
void death();
void Mutation(Cell* cell);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
/*float pMut_;
vector <float> conc_;
float pDeath_;
Cell* cellptr_;*/


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
	delete cellptr_;
	cellptr_ = c;
}

/*inline void Box::setCell(SCell* c)
{
	cellptr_ = c;
}*/

//==============================
//    OPERATOR DEFINITION
//==============================

inline std::ostream &operator<<(std::ostream &os, Box const &b) { 
    return os << "pMut_ = " << b.pMut_ << " pDeath_ = " << b.pDeath_ << " and cellptr_ = " << b.cellptr_ <<std::endl;
}



#endif // BOX_H
