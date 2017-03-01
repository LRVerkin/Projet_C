//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Envir.h"
#include "Box.h"
#include "Cell.h"
//#include "SCell.h"
//#include "LCell.h"

using std::cout;
using std::endl;


//==============================
//    FUNCTION DeCLARATION
//==============================


//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{
  
  Envir gonnaFail(10,50);

  gonnaFail.run(50);
  
  
  return 0;
}
