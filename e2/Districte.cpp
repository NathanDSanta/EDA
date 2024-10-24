// Darius Natan Santa
// u1994947
// Exercici 1
#include "Districte.h"
#include "Estudi.h"
#include "Nacionalitat.h"
#include "Persona.h"
#include <list>
#include <map>
#include <set>
#include <utility>

Districte::Districte() {
  // Pre: cert; Post: incialitzacio a 0
  a_any = 0;
  suma_edats = 0;
}

void Districte::afegir(int any, int seccio, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat) {
  // Pre: cert; Post: persona afegida a la ED
  if (a_any != any)
    a_any = any;
  map<int, list<Persona>>::iterator pos = a_hab.find(seccio);
  if (pos == a_hab.end())
    pos = a_hab.emplace(seccio, list<Persona>()).first;
  pos->second.push_back(Persona(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat));
  suma_edats += a_any - anyNaixement;
  a_resumEstudis.emplace(codiNivellEstudis, nivellEstudis);
  a_resumNacionalitats.emplace(codiNacionalitat, nomNacionalitat);
}

long Districte::obtenirNumHabitants() const {
  // Pre: cert; Post: retorna el nombre d'habitants del districte
  long total = 0;
  for (map<int, list<Persona>>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    total += i->second.size();
  }
  return total;
}

double Districte::obtenirEdatMitjana() const {
  long habitants = 0;
  for (map<int, list<Persona>>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    habitants += i->second.size();
  }
  return suma_edats / habitants;
}

set<Estudi> Districte::resumEstudis() const {
  // Pre: cert; Post: retorna els diferents estudis del districte
  return a_resumEstudis;
}

set<Nacionalitat> Districte::resumNacionalitats() const {
  // Pre: cert; Post: retorna les diferents nacionalitats del Districte
  return a_resumNacionalitats;
}

list<string> Districte::estudisEdatNacio(int edat, int nacionalitat) const {
  // Pre: cert; Post: retorna els estudis d'una nació en una determinada edat
  list<string> aux;
  for (map<int, list<Persona>>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    for (list<Persona>::const_iterator j = i->second.begin(); j != i->second.end(); j++) {
      if (j->obtenirCodiPaisNaixement() == nacionalitat && a_any - j->obtenirAnyNaixement() == edat) {
        aux.push_back(j->obtenirNivellEstudis());
      }
    }
  }
  aux.sort();
  aux.unique();
  return aux;
}