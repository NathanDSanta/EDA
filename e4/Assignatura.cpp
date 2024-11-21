#include "Assignatura.h"
#include <ostream>

Assignatura::Assignatura(string grau, string nom, string codi, bool esTipusGran, int credits, int semestre, int curs){
  a_grau = grau;
  a_nom = nom;
  a_codi = codi;
  a_esTipusGran = esTipusGran;
  a_credits = credits;
  a_semestre = semestre;
  a_curs = curs;
}

bool Assignatura::operator==(const Assignatura &a) const{
  return a_codi == a.a_codi;
}

bool Assignatura::obtEsGran() const{
  return a_esTipusGran;
}

ostream& operator<<(ostream& o, const Assignatura& a){
  o << a.a_grau << " "
    << a.a_nom << " "
    << a.a_codi << " "
    << a.a_esTipusGran << " "
    << a.a_credits << " "
    << a.a_semestre << " "
    << a.a_curs << endl;
  return o;
}
