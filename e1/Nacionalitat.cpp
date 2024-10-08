#include "Nacionalitat.h"

Nacionalitat::Nacionalitat(int id, string nom) {
  // Pre: --; Post: objecte creat
  a_id = id;
  a_nom = nom;
}

int Nacionalitat::obtenirId() const {
  // Pre: --; Post: retorna l'identificador de la nacionalitat
  return a_id;
}

string Nacionalitat::obtenirNom() const {
  // Pre: --; Post: retorna el nom de la nacionalitat
  return a_nom;
}

bool Nacionalitat::operator==(const Nacionalitat &nacio) const {
  // Pre: --; Post: retorna true si les dues nacionalitats són iguals
  return a_id == nacio.a_id;
}