#ifndef CELL_H
#define CELL_H 

//==============================
//    INCLUDES
//==============================

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;

/**
 * @virtual class Cell
 * @inherited by LCell and SCell
 * @brief Creates a Cell
 */


class Cell
{
public:
//==============================
//    CONSTRUCTORS
//==============================

  Cell();
  Cell(float a, float b, float c);

//==============================
//    DESTRUCTOR
//==============================

  virtual ~Cell();


//==============================
//    GETTERS
//==============================

  inline vector<float> getP();

//==============================
//    SETTERS
//==============================

  inline void         setP(float a, float b, float c);

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

  virtual void        Metabolism(vector<float> conc, float t) = 0;
  virtual float       Fitness() = 0;
  virtual char        LorS() = 0;


protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

const float           WMIN_ = 0.001;

float                 w_; //fitness
vector<float>         p_; //A, B and C

};


//==============================
//    GETTER DEFINITION
//==============================

inline vector<float> Cell::getP()
{
  //std::cout<< "Size of p_ = " << p_.size()<< std::endl;
	return p_;
}

//==============================
//    SETTER DEFINITION
//==============================

inline void Cell::setP(float a, float b, float c)
{
  //p_.reserve(15); //just in case p_ is empty
  p_[0] = a;
  p_[1] = b;
  p_[2] = c;
  
}

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // CELL_H
