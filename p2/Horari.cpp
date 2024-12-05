#include "Horari.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Solucio.h"
#include "Solucionador.h"
#include "eines.h"

void Horari::llegirDades(string fitxer) {
  ifstream fin(fitxer);

  if (fin.fail()) throw "Cannot open file";

  string linia;
  getline(fin, linia);  // ignorem la capcalera
  getline(fin, linia);
  while (!fin.eof()) {
    vector<string> dades = tokens(linia, '\t');
    aAssignatures.push_back(Assignatura(dades[0], dades[1], dades[2],
                                        dades[3] == "g", stod(dades[4]),
                                        stoi(dades[5]), stoi(dades[6])));
    getline(fin, linia);
  }

  sort(aAssignatures.begin(), aAssignatures.end());

  fin.close();
}

void Horari::generarIMostrarHorari(int cr, int gc, int s, int algoritme) const {
  Solucio inicial;
  Solucionador backtracking;
  backtracking.solucionar(inicial, algoritme);
  cout << backtracking.obtSolucio();
}
