#ifndef SCell_H
#define SCell_H 

//==============================
//    INCLUDES
//==============================

#include "SCell.h"
#include <vector>

/**
 * @class SCell
 * @brief Creates a SCell, Cell
 */


class SCell : public Cell
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  SCell();
  SCell(float a, float b, float c);

//==============================
//    DESTRUCTOR
//==============================
  ~SCell();

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
  void Metabolism(float a, float b, float c);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  
  const float Rbb_;
  const float Rbc_;

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


#endif // SCell_H