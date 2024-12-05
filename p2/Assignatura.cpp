#include "Assignatura.h"
#include <ostream>

Assignatura::Assignatura(string grau, string nom, string codi, bool esTipusGran, double credits, int semestre, int curs){
  aGrau = grau;
  aNom = nom;
  aCodi = codi;
  aEsTipusGran = esTipusGran;
  aCredits = credits;
  aSemestre = semestre;
  aCurs = curs;
}

bool Assignatura::operator==(const Assignatura &a) const{
  return aCodi == a.aCodi;
}

bool Assignatura::operator<(const Assignatura &a) const{
  return aEsTipusGran && !a.aEsTipusGran; 
}

bool Assignatura::obtEsGran() const{
  return aEsTipusGran;
}

string Assignatura::obtenirGrau() const{
  return aGrau;
}

ostream& operator<<(ostream& o, const Assignatura& a){
  o << a.aGrau << " "
    << a.aNom << " "
    << a.aCodi << " "
    << a.aEsTipusGran << " "
    << a.aCredits << " "
    << a.aSemestre << " "
    << a.aCurs << endl;
  return o;
}
