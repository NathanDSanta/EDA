#include "Assignatura.h"
#include <ostream>
#include <string>

Assignatura::Assignatura(string codi, string nom, string grau, bool esTipusGran, double credits, int semestre, int curs){
  aCodi = codi;
  aNom = nom;
  aGrau = grau;
  aEsTipusGran = esTipusGran;
  aCredits = credits;
  aSemestre = semestre;
  aCurs = curs;
}

bool Assignatura::operator==(const Assignatura &a) const{
  return aCodi == a.aCodi;
}

bool Assignatura::operator<(const Assignatura &a) const{
  return aCodi < a.aCodi;
}

bool Assignatura::obtEsGran() const{
  return aEsTipusGran;
}

string Assignatura::obtGrau() const{
  return aGrau;
}

string Assignatura::obtCurs() const{
  return to_string(aCurs);
}

string Assignatura::obtCodi() const{
  return aCodi;
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
