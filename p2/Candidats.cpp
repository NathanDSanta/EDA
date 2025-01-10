#include "Candidats.h"
#include <iostream>

Candidats::Candidats(int inici, int final){
  aActual = inici;
  aMax = final;
}

bool Candidats::esFi() const{
  return aActual == aMax;
}

int Candidats::actual() const{
  if (esFi()) {
    throw "es el final";
  }
  return aActual;
}

string Candidats::seleccionarPrometedor() const{
  std::cout << "Candidats::seleccionarPrometedor no implementat";
  return "";
}

void Candidats::eliminar(){
  std::cout << "Candidats::eliminar no implementat";
}

void Candidats::operator++(int){
  if (!esFi()) {
    aActual++; 
  }
}
