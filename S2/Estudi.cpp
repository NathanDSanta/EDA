#include "Estudi.h"

Estudi::Estudi(int id, string nom) {
  // Pre: --;
  // Post: objecte creat amb id=id i nom=nom
  a_id = id;
  a_nom = nom;
}

int Estudi::obtenirId() const {
  // Pre: --; Post: retorna identificador de l'estudi
  return a_id;
}

string Estudi::obtenirNom() const {
  // Pre: --; Post: retorna el nom de l'estudi
  return a_nom;
}

bool Estudi::operator==(const Estudi &estudi) const {
  // Pre: --; Post: retorna si 2 estudis són iguals
  return a_id == estudi.a_id;
}