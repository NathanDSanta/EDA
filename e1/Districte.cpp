// Darius Natan Santa
// u1994947
// Exercici 1
#include "Districte.h"

Districte::Districte() {
  // Pre: --; Post: objecte creat
  a_num_hab = 0;
}

void Districte::afegir(int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat) {
  // Pre: --; Post: persona afegida al districte
  a_hab.push_back(Persona(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat));
  a_num_hab++;
  a_any = any;
}

long Districte::obtenirNumHabitants() const {
  // Pre: --; Post: retorna el nombre d'habitants en el districte;
  return a_num_hab;
}

list<string> Districte::resumEstudis() const {
  // Pre: --; Post: retorna els diferents tipus d'estudi del districte
  list<string> est;
  list<Persona>::const_iterator i = a_hab.begin();
  while (i != a_hab.end()) {
    est.push_back(i->obtenirNivellEstudis());
    i++;
  }
  est.sort();
  est.unique();
  return est;
}

double Districte::obtenirEdatMitjana() const {
  // Pre: --; Post: retorna l'edat mitjana
  double mitjana = 0;
  for (list<Persona>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    mitjana += a_any - i->obtenirAnyNaixement();
  }
  mitjana /= a_num_hab;
  return mitjana;
}

list<string> Districte::resumNacionalitats() const {
  // Pre: --; Post: retorna les diferents nacionalitats del districte
  list<string> res;
  for (list<Persona>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    res.push_back(i->obtenirNomPaisNaixement());
  }
  res.sort();
  res.unique();
  return res;
}

long Districte::comptaEdatNacionalitat(int edat, int codiNacionalitat) const {
  // Pre: --; Post: retorna el nombre de habitants amb 'edat' anys i amb nacionalitat 'codiNacionalitat'
  long n_hab = 0;
  for (list<Persona>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    if (i->obtenirCodiPaisNaixement() == codiNacionalitat && i->obtenirAnyNaixement() == a_any - edat)
      n_hab++;
  }
  return n_hab;
}