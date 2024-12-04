#include "Horari.h"
#include "Assignatura.h"
#include "Solucio.h"
#include "Solucionador.h"
#include "eines.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>


void Horari::llegirDades(string fitxer){
  ifstream fin(fitxer);
  
  if(fin.fail()) throw "Cannot open file";

  string linia;
  getline(fin, linia); //ignorem la capcalera
  getline(fin, linia);
  while (!fin.eof()) {
    vector<string> dades = tokens(linia,'\t');
    aAssignatures.push_back(Assignatura(dades[0], dades[1], dades[2], dades[3] == "g", stod(dades[4]), stoi(dades[5]), stoi(dades[6])));
    getline(fin,linia);
  }

  fin.close();
}

void Horari::generarIMostrarHorari(int cr, int gc, int s, bool m) const{
  Solucio inicial(aAssignatures, cr, gc, s);
  Solucionador backtracking;
  backtracking.solucionar(inicial, m);
  cout << backtracking.obtSolucio();
}

