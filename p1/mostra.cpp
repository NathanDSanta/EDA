// FUNCIONS DE MOSTRA
// Arxiu amb les funcions de mostra del exercici 2
// format ==> 'mostra$()' on $ es el numero de l'opcio
#include "mostra.h"

#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>

#include "ResumNacionalitats.h"
#include "ResumNivellEstudis.h"

void error(const string &missatge) { cout << "ERROR " << missatge << endl; }

void banner(const int &opcio) {
  switch (opcio) {
  case 1:
    cout << "********************\n"
         << "* 01: Llegir dades *\n"
         << "********************\n";
    break;
  case 2:
    cout << "********************\n"
         << "* 02: Existeix any *\n"
         << "********************\n";
    break;
  case 3:
    cout << "**********************************\n"
         << "* 03: Obtenir nombre d'habitants *\n"
         << "**********************************\n";
    break;
  case 4:
    cout << "*******************************************\n"
         << "* 04: Obtenir nombre d'habitants d'un any *\n"
         << "*******************************************\n";
    break;
  case 5:
    cout << "*******************************************************\n"
         << "* 05: Obtenir nombre d'habitants d'un any i districte *\n"
         << "*******************************************************\n";
    break;
  case 6:
    cout << "*************************\n"
         << "* 06: Resum per estudis *\n"
         << "*************************\n";
    break;
  case 7:
    cout << "**************************************\n"
         << "* 07: Nombre d'estudis per districte *\n"
         << "**************************************\n";
    break;
  case 8:
    cout << "******************************\n"
         << "* 08: Resum nivell d'estudis *\n"
         << "******************************\n";
    break;
  case 9:
    cout << "******************************\n"
         << "* 09: Resum de nacionalitats *\n"
         << "******************************\n";
    break;
  case 10:
    cout << "*********************************\n"
         << "* 10: Moviments d'una comunitat *\n"
         << "*********************************\n";
    break;
  case 11:
    cout << "*********************\n"
         << "* 11: Resum d'edats *\n"
         << "*********************\n";
    break;
  case 12:
    cout << "****************************\n"
         << "* 12: Moviments dels vells *\n"
         << "****************************\n";
    break;
  case 13:
    cout << "******************\n"
         << "* 13: Més joves *\n"
         << "******************\n";
    break;
  case 14:
    cout << "********************************************\n"
         << "* 14: Estudis any,districte, edat i nació *\n"
         << "********************************************\n";
    break;
  }
}

void mostrar1(const int &linies) { cout << "Numero de linies: " << linies << endl; }

void mostrar2(const int &any, const bool &existeix) {
  cout << "Any:" << any << endl;
  cout << "Any ";
  if (!existeix)
    cout << "in";
  cout << "existent\n";
}

void mostrar3(const map<int, long> &dades) {
  double promig = 0;
  long total = 0;
  for (map<int, long>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << i->first << "   " << "habitants:" << setw(7) << right << i->second << endl;
    promig += i->second;
  }
  cout << "PROMIG : " << promig / dades.size() << endl;
}

void mostrar4(const int &any, const vector<long> &dades) {
  cout << "Any:" << any << endl;
  int total = 0;
  for (int i = 1; i < 7; i++) {
    cout << "Districte " << i << "   ";
    cout << "habitants:" << setw(7) << right << dades[i] << endl;
    total += dades[i];
  }
  cout << "TOTAL : " << total << endl;
}

void mostrar5(const map<int, long> &dades, const int &any, const int &districte) {
  cout << "Any:" << any << "  Districte:" << districte << endl;
  long total = 0;
  for (map<int, long>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << "Seccio " << i->first << "   habitants:" << setw(7) << right << i->second << endl;
    total += i->second;
  }
  cout << "TOTAL : " << total << endl;
}

void mostrar6(const ResumEstudis &dades) {
  for (ResumEstudis::const_iterator i = dades.begin(); i != dades.end(); i++) {
    set<Estudi>::const_reverse_iterator ii = i->second.rbegin();
    cout << i->first << "  Estudis:" << ii->obtenirNom();
    ii++;
    while (ii != i->second.rend()) {
      cout << " -- " << ii->obtenirNom();
      ii++;
    }
    cout << endl;
  }
}

void mostrar7(int districte, const map<int, int> &dades) {
  cout << "Districte:" << districte << endl;
  for (map<int, int>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << "Any " << i->first << "  Num Estudis:" << i->second << endl;
  }
}

void mostrar8(const ResumNivellEstudis &dades) {
  for (ResumNivellEstudis::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << i->first << ": \n";
    for (map<int, pair<double, int>>::const_iterator j = i->second.begin(); j != i->second.end(); j++) {
      cout << "       ";
      if (j->second.second == 1)
        cout << "+ ";
      else if (j->second.second == -1)
        cout << "- ";
      else
        cout << "  ";
      cout << setw(32) << left << Any::DISTRICTES[j->first] << "Promig Estudis: " << setw(10) << right << j->second.first << endl;
    }
  }
}

void mostrar9(const ResumNacionalitats &dades) {
  for (ResumNacionalitats::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << i->first << endl;
    for (list<pair<long, Nacionalitat>>::const_reverse_iterator j = i->second.rbegin(); j != i->second.rend(); j++) {
      cout << "       ";
      cout << left << setw(30) << j->second.obtenirNom() + " (" + to_string(j->second.obtenirId()) + ")"
        << ":" << setw(11) << right << j->first << endl;
    }
  }
}

void mostrar10(const map<int, string> &dades, const int &nacionalitat) {
  cout << "Codi Nacionalitat:" << nacionalitat << endl;
  for (map<int, string>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << i->first << setw(30) << right << i->second << endl;
  }
}

void mostrar11(const ResumEdats &dades) {
  for (ResumEdats::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << i->first << ": \n";
    for (map<double, string>::const_iterator ii = i->second.begin(); ii != i->second.end(); ii++) {
      cout << "       " << setw(32) << left << ii->second << "Promig Edat:" << setw(11) << right << setprecision(2) << ii->first << endl;
    }
  }
}

void mostrar12(const map<int, string> &dades) {
  for (map<int, string>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << setw(8) << left << i->first << i->second << endl;
  }
}

void mostrar13(const pair<string, long> &dades, const int &anyInici, const int &anyFinal) {
  cout << "Any Inicial: " << anyInici << "  AnyFinal:" << anyFinal << endl;
  cout << dades.first << setw(8) << right << dades.second << endl;
}

void mostrar14(int any, int districte, int edat, int codiNacionalitat, const list<string> &dades) {
  cout << "Any: " << any << "  Districte:" << districte << "  Edat:" << edat << "  Codi Nacionalitat:" << codiNacionalitat << endl;
  for (list<string>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << *i << endl;
  }
}
