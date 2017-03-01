#ifndef LCell_H
#define LCell_H 

//==============================
//    INCLUDES
//==============================

#include "Cell.h"

using std::vector;

/**
 * @class LCell
 * @brief Creates a LCell, Cell
 */


class LCell : public Cell
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  LCell();
  LCell(float a, float b, float c);

//==============================
//    DESTRUCTOR
//==============================
  ~LCell();

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
  float Fitness();
  void Metabolism(vector<float> conc, float t);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  
  const float Raa_;
  const float Rab_;

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


#endif // LCell_H