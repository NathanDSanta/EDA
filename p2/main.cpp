#include "Horari.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;


int main (int argc, char *argv[]) {
  cout << fixed << setprecision(2);  

  if (argc > 1 && argv[1][1] == 'h') {
    cout << "help" << endl;
  }
  else {
    int capacitatReducida = 1;
    int granCapacitat = 1;
    int semestre = 1;
    int duracioMaxima = numeric_limits<int>::max();
    string algoritme = "PRIMER";
    string fitxer = "";
    int i = 1;
    while (i < argc && fitxer == ""){
      if (argv[i][0] == '-') {
        string element_actual = string(argv[i] + 1);
        if (element_actual == "cr") {
          capacitatReducida = stoi(argv[i + 1]);
          i++;
        }
        else if(element_actual == "gc") {
          granCapacitat = stoi(argv[i + 1]);
          i++;
        }
        else if(element_actual == "s"){
          semestre = stoi(argv[i + 1]);
          i++;
        } 
        else if(element_actual == "d"){
          duracioMaxima = stoi(argv[i + 1]);
          i++;
        } 
        else if(element_actual == "m") algoritme = "MILLOR";
        else if(element_actual == "v") algoritme = "RAPID";
        else throw "invalid argument " + string(argv[i]);
      }
      else fitxer = string(argv[i]);
      i++;
    }

    cout << capacitatReducida << endl
      << granCapacitat << endl
      << semestre << endl
      << duracioMaxima << endl
      << algoritme << endl
      << fitxer << endl;

    Horari setmanaExamens(granCapacitat,capacitatReducida,semestre,duracioMaxima);
    setmanaExamens.llegirAssignatures(fitxer);
    cout << setmanaExamens;

    setmanaExamens.generarIMostrarHorari(algoritme);
  }
  return 0;
}
