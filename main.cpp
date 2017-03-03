//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Envir.h"
#include "Box.h"
#include "Cell.h"
//#include "SCell.h"
//#include "LCell.h"

using std::cout;
using std::endl;
using std::string;


//==============================
//    FUNCTION DeCLARATION
//==============================


//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{
  ofstream fichier("test.txt", ios::out | ios::trunc); 
  if(fichier){
    for(float Ainit=0; Ainit<=50; Ainit++){
	  for(int T=0; T<=1500; T++){
	    fichier << Ainit << " " << T << " " << enviro(T,Ainit).run(10000) << endl;
	  }
    }          
    fichier.close();
  } else cout << "Impossible d'ouvrir le fichier !" << endl;
  
  Envir gonnaFail(10,50);

  gonnaFail.run(50);

  cout<< "And it did!"<<endl;
  
  
  return 0;
}
