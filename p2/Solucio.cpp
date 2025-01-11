#include "Solucio.h"
#include "Candidats.h"
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>


Solucio::Solucio(set<Assignatura> &assig, map<string, set<string>> &restriccions, vector<string> &assigOrd, int gc, int cr, int d) {
  aAssignatures = assig;
  aRestriccions = restriccions;
  aAssignaturesOrdenades = assigOrd;
  aGcMax = gc;
  aCrMax = cr;
  aDiesMax = d;
  aNiv = 0;
  Torn buit(gc, cr);
  aSolucioActual.push_back(buit);
  aTorns = 1;
}

Candidats Solucio::inicialitzarCandidats() { return Candidats(0, aAssignaturesOrdenades.size()); }

bool Solucio::acceptable(const Candidats &iCand) const {
  string assig = aAssignaturesOrdenades.at(iCand.actual());
  set<Assignatura>::const_iterator assigInfo = aAssignatures.find(Assignatura(assig));
  map<string,set<string>>::const_iterator assigRestrict = aRestriccions.find(assig);
  string codiGrauCurs = assigInfo->obtGrau() + assigInfo->obtCurs(); 

  //comprovar capacitat
  if (assigInfo->obtEsGran() && aSolucioActual.back().gcCompletes(aGcMax)) {
    return false;
  }

  //comprovar restriccio Grau-Curs
  if (!aSolucioActual.empty() && aSolucioActual.back().existeixGrauCurs(codiGrauCurs)) {
    return false;
  }

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
  aSolucioActual.back().anotar(codiGrauCurs,assig, assigInfo->obtEsGran());
  if (aSolucioActual.back().ple()) {
    Torn nouTorn(aGcMax, aCrMax);
    aSolucioActual.push_back(nouTorn);
    aTorns++;
  }
  aNiv++;
}

void Solucio::desanotar(const Candidats &iCand) {
  string assig = aAssignaturesOrdenades.at(iCand.actual());
  set<Assignatura>::const_iterator assigInfo = aAssignatures.find(Assignatura(assig));
  string codiGrauCurs = assigInfo->obtGrau() + assigInfo->obtCurs(); 
  aSolucioActual.back().desanotar(codiGrauCurs,assig, assigInfo->obtEsGran());
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
    o << "Torn " << comptador << endl;
    list<string> llistaExamens = i->obtExamens();
    for (list<string>::const_iterator j = llistaExamens.begin(); j != llistaExamens.end(); j++) {
      if (*j == "") {
        o << "Sense examen" << endl;
      } else{
        o << *s.aAssignatures.find(Assignatura(*j)) << endl;
      }
    }
    comptador++;
  } 
  return o;
}

bool Solucio::solucioRapida(){
  bool trobat = false;
  int comptador = 1;
  map<int,string> candidats;
  for (vector<string>::const_iterator i = aAssignaturesOrdenades.begin(); i != aAssignaturesOrdenades.end(); i++) {
    candidats.insert(pair(comptador, *i));
    comptador++;
  }
  while (!completaR() && !candidats.empty()) {
    pair<int,string> x = seleccionarPrometedor(candidats); 
    candidats.erase(x.first);
    if (completable()) {
      afegirR(x.second);
    }
  }
  return completaR();
}

pair<int, string> Solucio::seleccionarPrometedor(const map<int,string>& candidats) const{
  bool trobat = false;
  map<int,string>::const_iterator i = candidats.begin();
  while (i != candidats.end() && !trobat) {
    string assig = i->second;
    set<Assignatura>::const_iterator assigInfo = aAssignatures.find(Assignatura(assig));
    map<string,set<string>>::const_iterator assigRestrict = aRestriccions.find(assig);
    string codiGrauCurs = assigInfo->obtGrau() + assigInfo->obtCurs(); 

    //comprovar capacitat
    if (assigInfo->obtEsGran() && aSolucioActual.back().gcCompletes(aGcMax)) {
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
    return *i; 
  }
  else return pair(0,"");
}

bool Solucio::completaR() const{
  return aNiv >= aAssignaturesOrdenades.size();
}

bool Solucio::completableR(string x) const{
  return aTorns/2 < aDiesMax;
}

void Solucio::afegirR(string x){
  if (x != "") {
    set<Assignatura>::const_iterator assigInfo = aAssignatures.find(Assignatura(x));
    string codiGrauCurs = assigInfo->obtGrau() + assigInfo->obtCurs();
    aSolucioActual.back().anotar(codiGrauCurs, x, assigInfo->obtEsGran());
  }
  if (aSolucioActual.back().ple() || x == "") {
    Torn nouTorn(aGcMax, aCrMax);
    aSolucioActual.push_back(nouTorn);
    aTorns++;
  }
  if (x != "") aNiv++;
}
