// Darius Natan Santa
// u1994947
// Exercici 1
#include "Padro.h"
#include <fstream>
#include <iostream>
#include <limits>

int stringToInt(string s) {
  if (s.length() == 0)
    return -1;
  for (char c : s) {
    if (c < '0' || c > '9')
      return -1;
  }
  return stoi(s);
}

int readInt() {
  // Pre: --; Post: retorna un int llegit amb casting de string
  string aux;
  cin >> aux;
  return stringToInt(aux);
}

int demanar_opcio(string missatge) {
  // Pre: --; Post: retorna la opcio entrada per teclat
  cerr << missatge << endl;
  int opcio;
  cin >> opcio;
  return opcio;
}

bool habitant_complet() {
  // Pre: --; Post: retorna si l'habitant conte totes les dades correctes
  bool correcte = true;
}

void llegir_dades(ifstream &fin, Padro &p) {
  // Pre: --; Post: llegeix les dades de fitxer
  cerr << "Insereix la ruta de l'arxiu" << endl;
  string ruta;
  cin >> ruta;
  fin.open(ruta);
  while (!fin.is_open()) {
    fin.clear();
    cerr << "Ruta equivocada!" << endl;
    cin >> ruta;
    fin.open(ruta);
  }
  while (fin.is_open()) {
    while (!fin.eof()) {
      fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      string nivell_estudis, nacionalitat;
      int any, districte, codi_estudis, any_naixement, codi_nacionalitat;
      any = readInt();
      districte = readInt();
      codi_estudis = readInt();
      cin >> nivell_estudis;
      any_naixement = readInt();
      codi_nacionalitat = readInt();
      cin >> nacionalitat;
      bool guardar = habitant_complet();
      p.afegir(any, districte, codi_estudis, nivell_estudis, any_naixement,
               codi_nacionalitat, nacionalitat);
    }
    fin.close();
  }
}

int main() {
  Padro padro;
  int menu = demanar_opcio("");
  while (menu != 0) {
    switch (menu) {
    case 1: {
      ifstream fitxer_entrada;
      llegir_dades(fitxer_entrada, padro);
      break;
    }
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    }
    menu = demanar_opcio("");
  }
  return 0;
}