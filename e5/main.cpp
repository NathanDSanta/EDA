#include "Horari.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
  cout << fixed << setprecision(2);

  if (argc > 1 && argv[1][1] == 'h') {
    cout << "show help" << endl;
  }
  else{
    //Parse Arguments
    int capacitatReduida = 1;
    int granCapacitat = 1;
    int semestre = 1;
    bool millorSolucio = false;
    bool endOfValidArguments = false;
    string fitxer = "";
    int i = 1;
    while (i < argc) {
      if (argv[i][0] == '-') {
        string element_actual = string(argv[i] + 1);
        if (element_actual == "cr") capacitatReduida = stoi(argv[i + 1]);
        else if (element_actual == "gc") granCapacitat = stoi(argv[i + 1]);
        else if (element_actual == "s") semestre = stoi(argv[i + 1]);
        else if(element_actual == "m") millorSolucio = true;
        else throw "invalid argument " + string(argv[i]);
      }
      else if (fitxer == ""){
        fitxer = string(argv[i]);
        if (fitxer == "") {
          throw "missing file argument";
        }
        endOfValidArguments = true;
      }
      else if(endOfValidArguments){
        throw "too many arguments";
      }
      i++;
    }
    Horari setmanaExamens;
    setmanaExamens.llegirDades(fitxer);
    setmanaExamens.generarIMostrarHorari(capacitatReduida, granCapacitat, semestre, millorSolucio);
  }
  return 0;
}
