// FUNCIONS DE MOSTRA
// Arxiu amb les funcions de mostra del exercici 2
// format ==> 'mostra$()' on $ es el numero de l'opcio
#include "Padro.h"
#include <iomanip>
#include <list>
#include <map>
#include <string>
#include <vector>

void mostrar1(const int &linies) {
  cout << "********************\n"
       << "* 01: Llegir dades *\n"
       << "********************\n"
       << "Numero de linies: ";

  cout << linies << endl;
}

void mostrar2(const int &any, const bool &existeix) {
  cout << "********************\n"
       << "* 02: Existeix any *\n"
       << "********************\n";

  cout << "Any:" << any << endl;
  cout << "Any ";
  if (!existeix)
    cout << "in";
  cout << "existent\n";
}

void mostrar4(const int &any, const vector<long> &dades) {
  cout << "*******************************************\n"
       << "* 04: Obtenir nombre d'habitants d'un any *\n"
       << "*******************************************\n";

  cout << "Any:" << any << endl;
  int total = 0;
  for (int i = 1; i < 7; i++) {
    cout << "Districte " << i << "   ";
    cout << "habitants:" << setw(7) << right << dades[i];
    total += dades[i];
  }
  cout << "TOTAL : " << total;
}

void mostrar6(const ResumEstudis &dades) {
  cout << "*************************\n"
       << "* 06: Resum per estudis *\n"
       << "*************************\n";
  for (ResumEstudis::const_iterator i = dades.begin(); i != dades.end(); i++) {
    set<Estudi>::const_iterator ii = i->second.begin();
    cout << i->first << "  Estudis:" << ii->obtenirNom();
    ii++;
    while (ii != i->second.end()) {
      cout << " -- " << ii->obtenirNom();
      ii++;
    }
  }
}

void mostrar7(int districte, const map<int, int> &dades) {
  cout << "**************************************\n"
       << "* 07: Nombre d'estudis per districte *\n"
       << "**************************************\n";
  cout << "Districte:" << districte << endl;
  for (map<int, int>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << "Any " << i->first << "  Num Estudis:" << i->second << endl;
  }
}

void mostrar11(const ResumEdats &dades) {
  cout << "*********************\n"
       << "* 11: Resum d'edats *\n"
       << "*********************\n";

  for (ResumEdats::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << i->first << ":\n";
    for (map<double, string>::const_iterator ii = i->second.begin(); ii != i->second.end(); ii++) {
      cout << "      " << setw(33) << left << ii->second << "Promig Edat:" << setw(11) << setprecision(2) << ii->first << endl;
    }
  }
}

void mostrar14(int any, int districte, int edat, int codiNacionalitat, const list<string> &dades) {
  cout << "Any: " << any << "  Disctricte:" << districte << "  Edat:" << edat << "  Codi Nacionalitat:" << codiNacionalitat << endl;
  for (list<string>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << *i << endl;
  }
}