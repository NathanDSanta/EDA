// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Assignatura.cpp
/// @brief Implementacio de la classe Assignatura
#include "Assignatura.h"
#include <iomanip>
#include <ostream>
#include <string>
using namespace std;

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
  o << a.aCodi << " (tipus "
    << (a.aEsTipusGran ? "g" : "r")
    << ")," << setw(6) << right << a.aGrau
    << "-" << a.aCurs;
  return o;
}
