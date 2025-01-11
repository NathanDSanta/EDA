// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Horari.cpp
/// @brief Implementacio de la classe Horari
#include "Horari.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

#include "Assignatura.h"
#include "Solucio.h"
#include "Solucionador.h"
#include "eines.h"

Horari::Horari(int gc, int cr, int s, int d) {
  aGranCapacitat = gc;
  aCapacitatReduida = cr;
  aSemestre = s;
  aDiesMaxims = d;
}

void Horari::llegirAssignatures(string fitxer) {
  list<Assignatura> aAssignaturesGrans;
  list<Assignatura> aAssignaturesReduides;
  ifstream fin(fitxer);

  if (fin.fail())
    throw "Cannot open file";

  string linia;
  getline(fin, linia); // ignorem la capcalera
  getline(fin, linia);
  vector<string> dades = tokens(linia, '\t');
  while (dades[0] != "*" && !fin.eof()) {
    int sem = stoi(dades[5]);
    if (sem == aSemestre) {
      bool esGran = dades[3] == "g";
      string codi = dades[2];
      Assignatura perInserir(codi, dades[1], dades[0], esGran, stod(dades[4]), sem, stoi(dades[6]));
      if (perInserir.obtEsGran()) {
        aAssignaturesGrans.push_back(perInserir);
      } else {
        aAssignaturesReduides.push_back(perInserir);
      }
    }
    getline(fin, linia);
    dades = tokens(linia, '\t');
  }
  aAssignatures.reserve(aAssignaturesGrans.size() + aAssignaturesReduides.size() + 1);
  aAssignatures.insert(aAssignatures.end(), aAssignaturesGrans.begin(), aAssignaturesGrans.end());
  aAssignatures.insert(aAssignatures.end(), aAssignaturesReduides.begin(), aAssignaturesReduides.end());
  getline(fin, linia);
  while (!fin.eof()) {
    dades = tokens(linia, '\t');
    string codiAssig1 = dades[0];
    string codiAssig2 = dades[1];
    int assig1 = trobarAssignatura(codiAssig1);
    int assig2 = trobarAssignatura(codiAssig2);
    if (assig1 != -1 && assig2 != -1) {
      map<int, set<int>>::iterator restrAssig1 = aRestriccions.find(assig1);
      map<int, set<int>>::iterator restrAssig2 = aRestriccions.find(assig2);
      if (restrAssig1 != aRestriccions.end()) {
        restrAssig1->second.insert(assig2);
      } else {
        set<int> llistaRestriccions1;
        llistaRestriccions1.insert(assig2);
        aRestriccions.insert(pair(assig1, llistaRestriccions1));
      }
      if (restrAssig2 != aRestriccions.end()) {
        restrAssig2->second.insert(assig1);
      } else {
        set<int> llistaRestriccions2;
        llistaRestriccions2.insert(assig1);
        aRestriccions.insert(pair(assig2, llistaRestriccions2));
      }
    }
  getline(fin, linia);
  }

  fin.close();
}

void Horari::generarIMostrarHorari(string algoritme) {
  auto inici = chrono::high_resolution_clock::now();
  Solucio inicial(aAssignatures, aRestriccions, aGranCapacitat, aCapacitatReduida, aDiesMaxims);
  Solucionador solucionador;
  solucionador.solucionar(inicial, algoritme);
  auto final = chrono::high_resolution_clock::now();
  chrono::duration<double> temps = final - inici;
  solucionador.mostrarSolucio(temps.count());
}

ostream &operator<<(ostream &o, const Horari &h) {
  o << "gc " << h.aGranCapacitat << endl << "cr " << h.aCapacitatReduida << endl << "sm " << h.aSemestre << endl << "dm " << h.aDiesMaxims << endl;
  for (vector<Assignatura>::const_iterator i = h.aAssignatures.begin(); i != h.aAssignatures.end(); i++) {
    o << *i << endl;
  }
  for (map<int, set<int>>::const_iterator i = h.aRestriccions.begin(); i != h.aRestriccions.end(); i++) {
    o << "Restriccions " << i->first << ": \n";
    for (set<int>::const_iterator j = i->second.begin(); j != i->second.end(); j++) {
      o << *j << endl;
    }
  }
  return o;
}

int Horari::trobarAssignatura(string codiAssignatura) const {
  bool trobat = false;
  int i = 0;
  while (i < aAssignatures.size() && !trobat) {
    if (aAssignatures.at(i).obtCodi() == codiAssignatura) {
      trobat = true;
    } else {
      i++;
    }
  }
  if (trobat) {
    return i;
  } else {
    return -1;
  }
}
