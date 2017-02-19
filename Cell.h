#ifndef CELL_H
#define CELL_H 

//==============================
//    INCLUDES
//==============================


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

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

  virtual vector<float> Metabolism(vector<float>* conc, float t)=0;
  virtual float Fitness()=0;


protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

const float WMIN_ = 0.001;

float pDeath_;
float pMut_;
float w_; //fitness
vector<float>p_; //A, B and C

};


//==============================
//    GETTER DEFINITION
//==============================

inline vector<float> Cell::getP()
{
	return p_;
}

//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // CELL_H