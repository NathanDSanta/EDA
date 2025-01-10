#include "Torn.h"
#include <list>
#include <string>

Torn::Torn(){
  aGcUsades = 0;
  aCrUsades = 0;
}

bool Torn::ple() const{
  return aExamens.size() == aGcUsades + aCrUsades;
}

bool Torn::buit() const{
  return aExamens.size() == 0;
}

bool Torn::gcCompletes(int aGcMax) const{
  return aGcUsades == aGcMax; 
}

bool Torn::existeixGrauCurs(string codiGrauCurs) const{
  return grauCursos.find(codiGrauCurs) != grauCursos.end();
}

bool Torn::existeixAlgunaAssignatura(set<string> assignatures) const{
  bool existeix = false;
  list<string>::const_iterator i = aExamens.begin();
  while (i != aExamens.end() && !existeix) {
    if (assignatures.find(*i) != assignatures.end()) {
      existeix = true;
    } else{
      i++;
    }
  }
  return existeix;
}

list<string> Torn::obtExamens() const{
  return aExamens;
}

void Torn::anotar(string codiGrauCurs, string assignatura){
  aExamens.push_back(assignatura);
  grauCursos.insert(codiGrauCurs);
}

void Torn::desanotar(string codiGrauCurs, string assignatura){
  if (aExamens.back() != assignatura) {
    throw "l'ultim element no es la assignatura que vols eliminar";
  }
  aExamens.pop_back();
  grauCursos.erase(codiGrauCurs);
}

ostream& operator<<(ostream& o, const Torn& t){
  for (list<string>::const_iterator i = t.aExamens.begin(); i != t.aExamens.end(); i++) {
    o << *i << endl;
  }
  return o;
}
