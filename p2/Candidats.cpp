// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Candidats.cpp
/// @brief Implementacio de la classe Candidats
#include "Candidats.h"

Candidats::Candidats(int inici, int final){
  aActual = inici;
  aMax = final;
}

bool Candidats::esFi() const{
  return aActual >= aMax; //- 1;
}

int Candidats::actual() const{
  if (esFi()) {
    throw "es el final";
  }
  return aActual;
}

void Candidats::operator++(int){
  if (esFi()) {
    throw "es el final";
  }
  aActual++; 
}
