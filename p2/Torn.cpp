#include "Torn.h"
#include <list>
#include <string>

Torn::Torn(int gc, int cr){
  aGcUsades = 0;
  aCrUsades = 0;
  aGcMax = gc;
  aCrMax = cr;
}

bool Torn::ple() const{
  return aGcMax + aCrMax == aGcUsades + aCrUsades;
}

bool Torn::buit() const{
  return aExamens.size() == 0;
}

bool Torn::gcCompletes(int aGcMax) const{
  return aGcUsades == aGcMax; 
}

bool Torn::existeixGrauCurs(string codiGrauCurs) const{
  return aGrauCursos.find(codiGrauCurs) != aGrauCursos.end();
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

set<string> Torn::obtGrauCursos() const{
  return aGrauCursos;
}

void Torn::anotar(string codiGrauCurs, string assignatura, bool esGran){
  aExamens.push_back(assignatura);
  aGrauCursos.insert(codiGrauCurs);
  if (esGran) {
    aGcUsades++;
  } else {
    aCrUsades++;
  }
}

void Torn::desanotar(string codiGrauCurs, string assignatura, bool esGran){
  if (aExamens.back() != assignatura) {
    throw "l'ultim element no es la assignatura que vols eliminar";
  }
  aExamens.pop_back();
  aGrauCursos.erase(codiGrauCurs);
  if (!esGran) {
    aGcUsades--;
  } else {
    aCrUsades--;
  }
}

ostream& operator<<(ostream& o, const Torn& t){
  for (list<string>::const_iterator i = t.aExamens.begin(); i != t.aExamens.end(); i++) {
    o << *i << endl;
  }
  return o;
}
