// Darius Natan Santa
// u1994947
// Exercici 1
#include "Padro.h"
#include "Districte.h"
#include <list>
#include <string>
#include <utility>
#include <vector>

Padro::Padro() { a_districtes = vector<Districte>(7); } // Els atributs tenen constructor per defecte;

int Padro::afegir(int any, int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat) {
  // Pre: --; Post: afegeix la persona al padro
  if (codiNivellEstudis == 0 || codiNacionalitat == -1)
    return 0;

  a_districtes[districte].afegir(any, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
  return 1;
}

vector<long> Padro::obtenirNumHabitantsPerDistricte() const {
  // Pre: --; Post: retorna el numero d'habitants en cada districte
  vector<long> vec(7);
  for (int i = 1; i < 8; i++) {
    vec[i] = a_districtes[i].obtenirNumHabitants();
  }
  return vec;
}

list<string> Padro::resumEstudis() const {
  // Pre: --; Post: retorna tots els tipus diferents d'estudis
  list<string> est;

  for (int i = 1; i < 8; i++) {
    est.merge(a_districtes[i].resumEstudis());
  }
  est.unique();
  est.reverse();

  return est;
}

vector<pair<string, double>> Padro::resumEdat() const {
  // Pre: --; Post: retorna la edat mitjana per districte
  vector<pair<string, double>> res(7);
  for (int i = 1; i < 8; i++) {
    res[i] = pair<string, double>(DISTRICTES[i], a_districtes[i].obtenirEdatMitjana());
  }
  return res;
}

pair<list<string>, list<string>> Padro::diferentsNacionalitats(int districte1, int districte2) const {
  // Pre: --; Post: retorna les nacionalitats exclusives entre els districtes
  list<string> d1 = a_districtes[districte1].resumNacionalitats();
  list<string> d2 = a_districtes[districte2].resumNacionalitats();
  list<string> aux = d1;
  for (list<string>::const_iterator i = d2.begin(); i != d2.end(); i++) {
    d1.remove(*i);
  }
  for (list<string>::const_iterator i = aux.begin(); i != aux.end(); i++) {
    d2.remove(*i);
  }
  return pair<list<string>, list<string>>(d1, d2);
}

vector<pair<string, long>> Padro::edatNacioPerDistricte(int edat, int codiNacionalitat) const {
  // Pre: --; Post: retorna el nombre d'habitants que son de 'codiNacionalitat'
  // i tenen 'edat' anys
  vector<pair<string, long>> vec(7);
  for (int i = 1; i < 8; i++) {
    vec[i] = pair<string, long>(DISTRICTES[i], a_districtes[i].comptaEdatNacionalitat(edat, codiNacionalitat));
  }
  return vec;
}