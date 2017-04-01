//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

#include "Envir.h"

/*using std::cout;
using std::endl;
using std::string;
using std::ofstream;

using namespace std;*/

//==============================
//    FUNCTION DeCLARATION
//==============================


//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{
  std::ofstream fichier("test.txt", std::ios::out | std::ios::trunc); 
  
  if(fichier){
    for(float Ainit=0; Ainit<=50; Ainit+=10){
	  for(int T=1; T<=1500; T+=300){
	    int nb_test=1; //for each (Ainit,t) we simulate nb_test times
	    for(int i=1; i<(nb_test+1); i++){
	      Envir enviro(T,Ainit);
	      enviro.run(10);
	      fichier << i << " " << Ainit << " " << T << " " << enviro.state << std::endl;
	    }
	  }
    }          
    fichier.close();
  } else std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
  
  
  return 0;
}
