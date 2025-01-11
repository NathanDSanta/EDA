// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file main.cpp
/// @brief fitxer del main del programa
#include "Horari.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;


int main (int argc, char *argv[]) {
  if (argc > 1 && argv[1][1] == 'h') {
    cout << "Us : ./main [-h] | [-v] [-m] [-cr <int>] [-gc <int>] [-s <int>] [-d <int>] fitxer\n\n"
      << "opcio pot ser :\n"
      << setw(20) << left << "  -h , --help"<< "mostra aquest missatge d’ajuda i surt\n"
      << setw(20) << left << "  -v "        << "cerca rapida amb un algoritme vorac¸\n"
      << setw(20) << left << "  -m "        << "cerca la solucio que minimitza el nombre de torns i\n"
      << setw(20) << left << "  "           << "maximitza la dispersio\n"
      << setw(20) << left << "  -cr <int>"  << "assigna <int> com a nombre d’aules de capacitat\n"
      << setw(20) << left << "  "           << "reduida disponibles per als examens\n"
      << setw(20) << left << "  -gc <int>"  << "assigna <int> com a nombre d’aules de gran\n"
      << setw(20) << left << "  "           << "capacitat disponibles per als examens\n"
      << setw(20) << left << "  -s <int>"   << "indica que s’ha de fer l’assignacio per al\n"
      << setw(20) << left << "  "           << "semestre <int> (1 o 2)\n"
      << setw(20) << left << "  -d <int>"   << "indica el l´ımit m`axim de dies que es poden fer servir\n\n"
      << setw(20) << left << "fitxer"       << "fitxer de text amb totes les assignatures a les\n"
      << setw(20) << left << "  "           << "que es vol assignar un torn d’examen i possibles\n"
      << setw(20) << left << "  "           << "restriccions entre parells d’assignatures\n";
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

    Horari setmanaExamens(granCapacitat,capacitatReducida,semestre,duracioMaxima);
    setmanaExamens.llegirAssignatures(fitxer);
    setmanaExamens.generarIMostrarHorari(algoritme);

    // cout << capacitatReducida << endl
    //   << granCapacitat << endl
    //   << semestre << endl
    //   << duracioMaxima << endl
    //   << algoritme << endl
    //   << fitxer << endl;
    // cout << setmanaExamens;

  }
  return 0;
}
