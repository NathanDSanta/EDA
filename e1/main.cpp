// Darius Natan Santa
// u1994947
// Exercici 1
#include "Padro.h"
#include <iomanip>
#include <string>
#include <utility>

// MOSTRAR
void mostrar1(const int &dades) {
  // Pre: --; Post: mostra missatge opcio 1
  cout << "*******************\n"
       << "* 1: Llegir dades *\n"
       << "*******************\n"
       << "Numero de linies: " << dades << endl;
}
void mostrar2(const vector<long> &dades) {
  // Pre: --; Post: mostra missatge opcio 2
  cout << "***************************************\n"
       << "* 2: Nombre d'habitants per districte *\n"
       << "***************************************\n";
  long suma = 0;
  for (int i = 1; i < 7; i++) {
    suma += dades[i];
    cout << "Districte " << i << "   habitants:" << setw(7) << right << dades[i] << endl;
  }
  cout << "TOTAL : " << suma << endl;
}
void mostrar3(const list<string> &dades) {
  // Pre: --; Post: mostra missatge opcio 3
  cout << "**************\n"
       << "* 3: Estudis *\n"
       << "**************\n";
  for (list<string>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    cout << " - " << *i << endl;
  }
}
void mostrar4(const vector<pair<string, double>> &dades) {
  // Pre: --; Post: mostra missatge opcio 4
  cout << "*********************\n"
       << "* 4: Edats mitjanes *\n"
       << "*********************\n";
  for (vector<pair<string, double>>::const_iterator i = dades.begin() + 1; i != dades.end(); i++) {
    cout << "\t " << setw(32) << left << i->first << "Promig Edat:" << setw(11) << right << setprecision(4) << i->second << endl;
  }
}
void mostrar5(const pair<list<string>, list<string>> &dades, const int &districte1, const int &districte2) {
  // Pre: --; Post: mostra missatge opcio 5
  cout << "*******************************\n"
       << "* 5: Nacionalitats exclusives *\n"
       << "*******************************\n";
  cout << "Districte " << districte1 << ": \n";
  for (list<string>::const_iterator i = dades.first.begin(); i != dades.first.end(); i++) {
    cout << " - " << *i << endl;
  }
  cout << "Districte " << districte2 << ": \n";
  for (list<string>::const_iterator i = dades.second.begin(); i != dades.second.end(); i++) {
    cout << " - " << *i << endl;
  }
}
void mostrar6(const vector<pair<string, long>> &dades, const int &edat, const int &nacionalitat) {
  // Pre: --; Post: mostra missatge opcio 6
  cout << "****************************************\n"
       << "* 6: Compta edat i nació per districte *\n"
       << "****************************************\n";
  cout << "Edat:" << edat << "  Codi Nacionalitat:" << nacionalitat << endl;
  for (vector<pair<string, long>>::const_iterator i = dades.begin(); i != dades.end(); i++) {
    if (i->second != 0)
      cout << i->first << ": " << i->second << endl;
  }
}

int stringToInt(string s) {
  if (s.length() == 0)
    return -1;
  for (char c : s) {
    if (c < '0' || c > '9')
      return -1;
  }
  return stoi(s);
}

int readInt(ifstream &fin) {
  // Pre: --; Post: retorna un int llegit amb casting de string
  string aux;
  fin >> aux;
  return stringToInt(aux);
}

int demanar_opcio() {
  // Pre: --; Post: retorna la opcio entrada per teclat
  int opcio;
  cin >> opcio;
  return opcio;
}

void llegir_dades(ifstream &fin, Padro &p, int &linies) {
  // Pre: --; Post: llegeix les dades de fitxer
  linies = 0;
  string ruta;
  cin >> ruta;
  fin.open(ruta.c_str());
  while (!fin.is_open()) {
    fin.close();
    fin.clear();
    cin >> ruta;
    fin.open(ruta.c_str());
  }
  while (fin.is_open()) {
    while (!fin.eof()) {
      fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      string nivell_estudis, nacionalitat;
      int any, districte, codi_estudis, any_naixement, codi_nacionalitat;
      any = readInt(fin);
      districte = readInt(fin);
      codi_estudis = readInt(fin);
      fin >> nivell_estudis;
      any_naixement = readInt(fin);
      codi_nacionalitat = readInt(fin);
      fin >> nacionalitat;
      int afegit = p.afegir(any, districte, codi_estudis, nivell_estudis, any_naixement, codi_nacionalitat, nacionalitat);
      if (afegit == 1)
        linies++;
    }
    fin.close();
  }
}

int main() {
  Padro padro;
  int menu = demanar_opcio();
  while (menu != 0) {
    switch (menu) {
    case 1: {
      ifstream fitxer_entrada;
      int linies;
      llegir_dades(fitxer_entrada, padro, linies);
      mostrar1(linies);
      break;
    }
    case 2: {
      vector<long> num_habitants = padro.obtenirNumHabitantsPerDistricte();
      mostrar2(num_habitants);
    } break;
    case 3: {
      list<string> estudis = padro.resumEstudis();
      mostrar3(estudis);
    } break;
    case 4: {
      vector<pair<string, double>> edats = padro.resumEdat();

      mostrar4(edats);
    } break;
    case 5: {
      int districte1, districte2;
      cin >> districte1 >> districte2;
      pair<list<string>, list<string>> nacio_exc = padro.diferentsNacionalitats(districte1, districte2);
      mostrar5(nacio_exc, districte1, districte2);
    } break;
    case 6: {
      int edat, nacionalitat;
      cin >> edat >> nacionalitat;
      vector<pair<string, long>> edatNacioDistricte = padro.edatNacioPerDistricte(edat, nacionalitat);
      mostrar6(edatNacioDistricte, edat, nacionalitat);
    } break;
    }
    menu = demanar_opcio();
  }
  return 0;
}
