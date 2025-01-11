// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Solucio.cpp
/// @brief Implementacio de la classe Solucio
#include "Solucio.h"
#include "Assignatura.h"
#include "Candidats.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>


Solucio::Solucio(vector<Assignatura> &assig, map<int, set<int>> &restriccions, int gc, int cr, int d) {
  aAssignatures = assig;
  aRestriccions = restriccions;
  aAssignaturesUtilitzada = vector(aAssignatures.size(), false);
  aGcMax = gc;
  aCrMax = cr;
  aDiesMax = d;
  aNiv = 0;
  aTorns = 1;
}

Candidats Solucio::inicialitzarCandidats() { return Candidats(0, aAssignatures.size()); }

bool Solucio::acceptable(const Candidats &iCand) const {
  //comprovar si s'ha anotat
  if (aAssignaturesUtilitzada.at(iCand.actual())) {
    return false; 
  }
  Assignatura assig = aAssignatures.at(iCand.actual());
  string codiGrauCurs = assig.obtGrau() + assig.obtCurs(); 

  //comprovar restriccio Grau-Curs
  if (!aSolucioActual.empty() && aSolucioActual.back().existeixGrauCurs(codiGrauCurs)) {
    return false;
  }

  //comprovar capacitat
  if (assig.obtEsGran() && aSolucioActual.back().gcCompletes()) {
    return false;
  }


  map<int,set<int>>::const_iterator assigRestrict = aRestriccions.find(iCand.actual());
  //comprovar llista de restriccions addicionals
  if (!aSolucioActual.empty() && assigRestrict != aRestriccions.end() && aSolucioActual.back().existeixAlgunaAssignatura(assigRestrict->second)) {
    return false;
  } 

  return true;
}

bool Solucio::completa() const { return aNiv == aAssignatures.size(); }

bool Solucio::completable() const { return aTorns / 2 < aDiesMax; }

bool Solucio::esMillor(int tornsOptima, double desviacioOptima) const{
  return aTorns <= tornsOptima && obtDesviacioMitjana() >= desviacioOptima;
}

bool Solucio::esMillorable(int tornsOptima) const{
  return aTorns <= tornsOptima;
}

double Solucio::obtDesviacioMitjana() const {
  map<string, double> desviacions = obtDesviacioGrauCurs();
  double suma = 0;
  for (map<string, double>::const_iterator i = desviacions.begin(); i != desviacions.end(); i++) {
    suma += i->second;
  }
  return suma / desviacions.size();
}

int Solucio::obtTorns() const { return aTorns; }

void Solucio::anotar(const Candidats &iCand) {
  Assignatura assig = aAssignatures.at(iCand.actual());
  string codiGrauCurs = assig.obtGrau() + assig.obtCurs(); 
  if (aSolucioActual.empty()) {
    Torn nouTorn(aGcMax, aCrMax);
    aSolucioActual.push_back(nouTorn);
    aTorns++;
  }
  aSolucioActual.back().anotar(codiGrauCurs,iCand.actual(), assig.obtEsGran());
  aAssignaturesUtilitzada[iCand.actual()] = true;
  if (aSolucioActual.back().ple()) {
    Torn nouTorn(aGcMax, aCrMax);
    aSolucioActual.push_back(nouTorn);
    aTorns++;
  }
  aNiv++;
}

void Solucio::desanotar(const Candidats &iCand) {
  Assignatura assig = aAssignatures.at(iCand.actual());
  string codiGrauCurs = assig.obtGrau() + assig.obtCurs(); 
  aSolucioActual.back().desanotar(codiGrauCurs,iCand.actual(), assig.obtEsGran());
  aAssignaturesUtilitzada[iCand.actual()] = false;
  if (aSolucioActual.back().buit()) {
    aSolucioActual.pop_back();
    aTorns--;
  }
  aNiv--;
}

map<string, double> Solucio::obtDesviacioGrauCurs() const {
  map<string, list<int>> tornsGrauCurs;
  map<string, double> mitjanaTorns;
  map<string, double> res;

  // Em guardo els torns dels examens de cada Grau-Curs
  int comptador = 1;
  for (list<Torn>::const_iterator i = aSolucioActual.begin(); i != aSolucioActual.end(); i++) {
    set<string> grauCursosTorn = i->obtGrauCursos();
    for (set<string>::const_iterator j = grauCursosTorn.begin(); j != grauCursosTorn.end(); j++) {
      map<string, list<int>>::iterator posGrauCurs = tornsGrauCurs.find(*j);
      if (posGrauCurs != tornsGrauCurs.end()) {
        posGrauCurs->second.push_back(comptador);
      } else {
        list<int> torns;
        torns.push_back(comptador);
        tornsGrauCurs.insert(pair(*j, torns));
      }
    }
    comptador++;
  }

  // Calculo la mitjana dels torns
  for (map<string, list<int>>::const_iterator i = tornsGrauCurs.begin(); i != tornsGrauCurs.end(); i++) {
    double sumaMitjana = 0;
    for (list<int>::const_iterator j = i->second.begin(); j != i->second.end(); j++) {
      sumaMitjana += *j;
    }
    mitjanaTorns.insert(pair(i->first, sumaMitjana / i->second.size()));
  }

  // Calculo suma de les diferencies
  for (map<string, list<int>>::const_iterator i = tornsGrauCurs.begin(); i != tornsGrauCurs.end(); i++) {
    double sumaDiferencia = 0;
    double mitjana = mitjanaTorns.find(i->first)->second;
    for (list<int>::const_iterator j = i->second.begin(); j != i->second.end(); j++) {
      sumaDiferencia += (*j - mitjana) * (*j - mitjana);
    }
    res.insert(pair(i->first, sumaDiferencia));
  }

  // Divideixo i arrel quadrada
  for (map<string, double>::iterator i = res.begin(); i != res.end(); i++) {
    i->second = sqrt(i->second / tornsGrauCurs.find(i->first)->second.size());
  }

  return res;
}


ostream& operator<<(ostream& o, const Solucio& s) {
  int comptador = 1;
  for (list<Torn>::const_iterator i = s.aSolucioActual.begin(); i != s.aSolucioActual.end(); i++) {
    list<int> llistaExamens = i->obtExamens();
    o << "*********************************\n";
    o << "* Torn " << comptador  << setw(21) << right << "n=" << llistaExamens.size() << "  *\n";
    o << "*-------------------------------*\n";
    for (list<int>::const_iterator j = llistaExamens.begin(); j != llistaExamens.end(); j++) {
      if (*j != -1) {
        o << "* " << s.aAssignatures.at(*j) << " *\n";
      }
    }
    o << "*********************************\n\n";
    comptador++;
  } 
  return o;
}

bool Solucio::solucioRapida(){
  bool trobat = false;
  while (!completaR() && quedenCandidats()) {
    int x = seleccionarPrometedor(); 
    if (x != -1) {
      aAssignaturesUtilitzada[x] = true;
    }
    if (completable()) {
      afegirR(x);
    }
  }
  return completaR();
}

int Solucio::seleccionarPrometedor() const{
  bool trobat = false;
  int i = 0;
  while (i < aAssignatures.size() && !trobat) {
    if (aAssignaturesUtilitzada.at(i)) {
      i++;
      continue;
    }
    Assignatura assig = aAssignatures.at(i);
    map<int,set<int>>::const_iterator assigRestrict = aRestriccions.find(i);
    string codiGrauCurs = assig.obtGrau() + assig.obtCurs(); 


    //comprovar capacitat
    if (assig.obtEsGran() && aSolucioActual.back().gcCompletes()) {
      i++;
      continue;
    }

    //comprovar restriccio Grau-Curs
    if (!aSolucioActual.empty() && aSolucioActual.back().existeixGrauCurs(codiGrauCurs)) {
      i++;
      continue;
    }

    //comprovar llista de restriccions addicionals
    if (!aSolucioActual.empty() && assigRestrict != aRestriccions.end() && aSolucioActual.back().existeixAlgunaAssignatura(assigRestrict->second)) {
      i++;
      continue;
    } 

    trobat = true;
  }
  if (trobat) {
    return i; 
  }
  else return -1;
}

bool Solucio::completaR() const{
  return aNiv >= aAssignatures.size();
}

bool Solucio::completableR(string x) const{
  return aTorns/2 < aDiesMax;
}

void Solucio::afegirR(int x){
  if (aSolucioActual.empty()) {
    Torn nouTorn(aGcMax, aCrMax);
    aSolucioActual.push_back(nouTorn);
    aTorns++;
  }
  if (x != -1) {
    Assignatura assig = aAssignatures.at(x);
    string codiGrauCurs = assig.obtGrau() + assig.obtCurs();
    aSolucioActual.back().anotar(codiGrauCurs, x, assig.obtEsGran());
  }
  if (aSolucioActual.back().ple() || x == -1) {
    Torn nouTorn(aGcMax, aCrMax);
    aSolucioActual.push_back(nouTorn);
    aTorns++;
  }
  if (x != -1) aNiv++;
}

bool Solucio::quedenCandidats() const{
  bool queden = false;
  int i = 0;
  while (!queden && i < aAssignaturesUtilitzada.size()) {
    if (!aAssignaturesUtilitzada.at(i)) {
      queden = true; 
    } else{
      i++; 
    } 
  }
  return queden;
}
