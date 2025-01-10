#include "Horari.h"

#include <fstream>
#include <iostream>
#include <set>
#include <vector>

#include "Assignatura.h"
#include "Solucio.h"
#include "Solucionador.h"
#include "eines.h"

Horari::Horari(int gc, int cr, int s, int d){
  aGranCapacitat = gc;
  aCapacitatReduida = cr;
  aSemestre = s;
  aDiesMaxims = d;
}

void Horari::llegirAssignatures(string fitxer) {
  list<string> aAssignaturesGrans;
  list<string> aAssignaturesReduides;
  ifstream fin(fitxer);

  if (fin.fail()) throw "Cannot open file";

  string linia;
  getline(fin, linia);  // ignorem la capcalera
  getline(fin, linia);
  vector<string> dades = tokens(linia, '\t');
  while (dades[0] != "*" && !fin.eof()) {
    int sem = stoi(dades[5]);
    if (sem == aSemestre) {
      bool esGran = dades[3] == "g";
      string codi = dades[2];
      Assignatura perInserir(codi, dades[1], dades[0], esGran, stod(dades[4]), sem, stoi(dades[6]));
      aAssignatures.insert(perInserir);
      if (perInserir.obtEsGran()) {
        aAssignaturesGrans.push_back(perInserir.obtCodi());
      } else{
        aAssignaturesReduides.push_back(perInserir.obtCodi());
      }
    }
    getline(fin, linia);
    dades = tokens(linia, '\t');
  }
  aAssignaturesOrdenades.insert(aAssignaturesOrdenades.end(),aAssignaturesGrans.begin(), aAssignaturesGrans.end());
  aAssignaturesOrdenades.insert(aAssignaturesOrdenades.end(),aAssignaturesReduides.begin(), aAssignaturesReduides.end());
  while (!fin.eof()) {  
    getline(fin, linia);
    dades = tokens(linia, '\t');
    string assig1 = dades[0];
    string assig2 = dades[1];
    map<string,set<string>>::iterator restrAssig1 = aRestriccions.find(assig1);
    map<string,set<string>>::iterator restrAssig2 = aRestriccions.find(assig2);
    if (restrAssig1 != aRestriccions.end()) {
      restrAssig1->second.insert(assig2);
    } else{
      set<string> llistaRestriccions1;
      llistaRestriccions1.insert(assig2);
      aRestriccions.insert(pair(assig1,llistaRestriccions1));
    }
    if (restrAssig2 != aRestriccions.end()) {
      restrAssig2->second.insert(assig1);
    } else{
      set<string> llistaRestriccions2;
      llistaRestriccions2.insert(assig1);
      aRestriccions.insert(pair(assig2,llistaRestriccions2));
    }
  }

  fin.close();
}

void Horari::generarIMostrarHorari(string algoritme){
  Solucio inicial(aAssignatures, aRestriccions, aAssignaturesOrdenades,aGranCapacitat,aCapacitatReduida,aDiesMaxims);
  Solucionador solucionador;
  solucionador.solucionar(inicial,algoritme);
  solucionador.mostrarSolucio();
}

ostream& operator<<(ostream& o, const Horari& h){
  o << "gc " << h.aGranCapacitat << endl
    << "cr " << h.aCapacitatReduida << endl
    << "sm " << h.aSemestre << endl
    << "dm " << h.aDiesMaxims << endl;
  for (set<Assignatura>::const_iterator i = h.aAssignatures.begin(); i != h.aAssignatures.end(); i++) {
    o << *i;
  }
  for (map<string,set<string>>::const_iterator i = h.aRestriccions.begin(); i != h.aRestriccions.end(); i++) {
    o << "Restriccions " << i->first << ": \n";
    for (set<string>::const_iterator j = i->second.begin(); j != i->second.end(); j++) {
      o << *j << endl;
    }
  }
  return o;
}
