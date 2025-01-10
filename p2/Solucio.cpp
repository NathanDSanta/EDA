#include "Solucio.h"
#include "Candidats.h"
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>


Solucio::Solucio(set<Assignatura> &assig, map<string, set<string>> &restriccions, vector<string> &assigOrd, int gc, int cr, int d) {
  aAssignatures = assig;
  aRestriccions = restriccions;
  aAssignaturesOrdenades = assigOrd;
  aGcMax = gc;
  aCrMax = cr;
  aDiesMax = d;
  aNiv = 0;
  aTorns = 0;

}

Candidats Solucio::inicialitzarCandidats() { return Candidats(0, aAssignaturesOrdenades.size()); }

bool Solucio::acceptable(const Candidats &iCand) const {
  bool acceptable = true; 
  string assig = aAssignaturesOrdenades.at(iCand.actual());
  set<Assignatura>::const_iterator assigInfo = aAssignatures.find(Assignatura(assig));
  map<string,set<string>>::const_iterator assigRestrict = aRestriccions.find(assig);
  string codiGrauCurs = assigInfo->obtGrau() + assigInfo->obtCurs(); 

  //comprovar capacitat
  if (assigInfo->obtEsGran() && aSolucioActual.back().gcCompletes(aGcMax)) {
    acceptable = false; 
  }

  //comprovar restriccio Grau-Curs
  if (aSolucioActual.back().existeixGrauCurs(codiGrauCurs)) {
    acceptable = false; 
  }
  
  //comprovar llista de restriccions addicionals
  if (assigRestrict != aRestriccions.end() && aSolucioActual.back().existeixAlgunaAssignatura(assigRestrict->second)) {
    acceptable = false;  
  } 

  return acceptable;
}

bool Solucio::completa() const { return aNiv == aAssignatures.size(); }

bool Solucio::completable() const { return aTorns / 2 < aDiesMax; }

bool Solucio::esMillor(int tornsOptima, double desviacioOptima) const{
  return aTorns <= tornsOptima && obtDesviacioMitjana() >= desviacioOptima;
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
  string assig = aAssignaturesOrdenades.at(iCand.actual());
  set<Assignatura>::const_iterator assigInfo = aAssignatures.find(Assignatura(assig));
  string codiGrauCurs = assigInfo->obtGrau() + assigInfo->obtCurs(); 
  if (aSolucioActual.empty() || aSolucioActual.back().ple()) {
    Torn nouTorn;
    nouTorn.anotar(codiGrauCurs,assig);
    aSolucioActual.push_back(nouTorn);
    aTorns++;
  } else {
    aSolucioActual.back().anotar(codiGrauCurs,assig);
  }
  aNiv++;
}

void Solucio::desanotar(const Candidats &iCand) {
  string assig = aAssignaturesOrdenades.at(iCand.actual());
  set<Assignatura>::const_iterator assigInfo = aAssignatures.find(Assignatura(assig));
  string codiGrauCurs = assigInfo->obtGrau() + assigInfo->obtCurs(); 
  aSolucioActual.back().desanotar(codiGrauCurs,assig);
  if (aSolucioActual.back().buit()) {
    aSolucioActual.pop_back();
    aTorns--;
  }
  aNiv--;
}

map<string, double> Solucio::obtDesviacioGrauCurs() const {
  map<string, double> res;
  map<string, double> mitjanaTorns;
  map<string, double> sumaDiferencies;
  map<string, list<int>> tornsGrauCurs;

  // Em guardo els torns dels examens de cada Grau-Curs
  for (list<Torn>::const_iterator i = aSolucioActual.begin(); i != aSolucioActual.end(); i++) {
    list<string> examensTorn = i->obtExamens();
    for (list<string>::const_iterator j = examensTorn.begin(); j != examensTorn.end(); j++) {
      set<Assignatura>::const_iterator examInfo = aAssignatures.find(Assignatura(*j));
      string codiGrauCurs = examInfo->obtGrau() + examInfo->obtCurs();
      map<string, list<int>>::iterator posGrauCurs = tornsGrauCurs.find(codiGrauCurs);
      if (posGrauCurs != tornsGrauCurs.end()) {
        posGrauCurs->second.push_back(aTorns);
      } else {
        list<int> torns;
        torns.push_back(aTorns);
        tornsGrauCurs.insert(pair(codiGrauCurs, torns));
      }
    }
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
    o << "Torn " << comptador << endl;
    o << *i << endl;
  } 
  return o;
}
