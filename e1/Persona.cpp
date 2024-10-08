// Darius Natan Santa
// u1994947
// Exercici 1
#include "Persona.h"

Persona::Persona(int codiNivellEstudis, const string &nivellEstudis,
                 int anyNaixement, int codiPaisNaixement,
                 const string &paisNaixement) {
  // Pre: --; Post: objecte creat
  a_est = Estudi(codiNivellEstudis, nivellEstudis);
  a_nac = Nacionalitat(codiPaisNaixement, paisNaixement);
  a_anyNaix = anyNaixement;
}

int Persona::obtenirAnyNaixement() const {
  // Pre: --; Post: retorna l'any de naixement
  return a_anyNaix;
}

string Persona::obtenirNivellEstudis() const {
  // Pre: --; Post: retorna el nivell d'estudis
  return a_est.obtenirNom();
}

int Persona::obtenirCodiPaisNaixement() const {
  // Pre: --; Post: retorna el codi del pais de naixement
  return a_nac.obtenirId();
}