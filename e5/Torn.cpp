#include "Torn.h"
#include "Assignatura.h"
#include <list>
#include <vector>

Torn::Torn() {
  aGcUsades = 0;
  aCrUsades = 0;
}

bool Torn::existeixCurs(string curs) const{
  return aCursExisteix.find(curs) != aCursExisteix.end();
}

bool Torn::pleGrans(int gc) const{
  return gc < aGcUsades;
}

bool Torn::ple(int totals) const{
  return totals < aGcUsades + aCrUsades;
}

bool Torn::buit() const{
  return aExamens.empty(); 
}

list<int> Torn::obtenirExamens() const {
  return aExamens;
}

void Torn::inserir(const vector<Assignatura> &assig, int candidat) {
  aExamens.push_back(candidat);
  if (assig[candidat].obtEsGran()) aGcUsades++;
  else aCrUsades++;
  aCursExisteix.insert(assig[candidat].obtenirGrau());
}

void Torn::eliminar(const vector<Assignatura> &assig){
  if (assig[aExamens.back()].obtEsGran()) aGcUsades--;
  else aCrUsades--;
  aCursExisteix.erase(assig[aExamens.back()].obtenirGrau());
  aExamens.pop_back();
}

ostream& operator<<(ostream& o, const Torn& t){
  for (list<int>::const_iterator i = t.aExamens.begin(); i != t.aExamens.end(); i++) {
    o << *i << endl;
  }
  return o;
}
