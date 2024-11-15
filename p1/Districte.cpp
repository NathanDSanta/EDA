// Darius Natan Santa
// u1994947
// Exercici 1
#include "Districte.h"

#include <list>
#include <map>
#include <set>
#include <utility>

#include "Estudi.h"
#include "Nacionalitat.h"

Districte::Districte() {
  // Pre: cert; Post: incialitzacio a 0
  sumaEdats = 0;
  sumaPromigEstudis = 0;
}

void Districte::afegir(int any, int seccio, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat) {
  // Pre: cert; Post: persona afegida a la ED
  map<int, Seccio>::iterator pos = a_seccions.find(seccio);
  if (pos == a_seccions.end())
    pos = a_seccions.emplace(seccio, Seccio()).first;
  pos->second.afegir(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
  sumaEdats += any - anyNaixement;
  sumaPromigEstudis += codiNivellEstudis;
  a_resumEstudis.emplace(codiNivellEstudis, nivellEstudis);
  a_resumNacionalitats.emplace(codiNacionalitat, nomNacionalitat);
  map<int, long>::iterator posicio = a_resumHabitantsNacio.find(codiNacionalitat);
  if (posicio != a_resumHabitantsNacio.end()) {
    posicio->second++;
  } else {
    a_resumHabitantsNacio.emplace(codiNacionalitat, 1);
  }
}

long Districte::obtenirNumHabitants() const {
  // Pre: cert; Post: retorna el nombre d'habitants del districte
  long total = 0;
  for (map<int, Seccio>::const_iterator i = a_seccions.begin(); i != a_seccions.end(); i++) {
    total += i->second.obtenirNumHabitants();
  }
  return total;
}

map<int, long> Districte::obtenirNumHabitantsPerSeccio() const {
  map<int, long> resultat;
  for (map<int, Seccio>::const_iterator i = a_seccions.begin(); i != a_seccions.end(); i++) {
    resultat.emplace(i->first, i->second.obtenirNumHabitants());
  }
  return resultat;
}

double Districte::obtenirPromigNivellEstudis() const { return sumaPromigEstudis / obtenirNumHabitants(); }

set<Nacionalitat> Districte::resumNacionalitats() const {
  // Pre: cert; Post: retorna les diferents nacionalitats del Districte
  return a_resumNacionalitats;
}

long Districte::obtenirNumHabitantsNacio(int codiNacionalitat) const { return a_resumHabitantsNacio.find(codiNacionalitat)->second; }

double Districte::obtenirEdatMitjana() const {
  long habitants = obtenirNumHabitants();
  return sumaEdats / habitants;
}

set<Estudi> Districte::resumEstudis() const {
  // Pre: cert; Post: retorna els diferents estudis del districte
  return a_resumEstudis;
}

long Districte::obtenirNumHabitantsEdatEntre(int any, int edat1, int edat2) const {
  long total = 0;
  for (map<int, Seccio>::const_iterator i = a_seccions.begin(); i != a_seccions.end(); i++) {
    total += i->second.obtenirNumHabitantsEdatEntre(any, edat1, edat2);
  }
  return total;
}

list<string> Districte::estudisEdatNacio(int any, int edat, int nacionalitat) const {
  // Pre: cert; Post: retorna els estudis d'una nació en una determinada edat
  list<string> aux;
  for (map<int, Seccio>::const_iterator i = a_seccions.begin(); i != a_seccions.end(); i++) {
    aux.merge(i->second.estudisEdatNacio(any, edat, nacionalitat));
  }
  aux.sort();
  aux.unique();
  return aux;
}
