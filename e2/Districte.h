// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef DISTRICTE_H
#define DISTRICTE_H
#include "Estudi.h"
#include "Nacionalitat.h"
#include "Persona.h"
#include <list>
#include <map>
#include <set>

class Districte {
public:
  Districte();
  void afegir(int any, int seccio, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
  long obtenirNumHabitants() const;
  double obtenirEdatMitjana() const;
  set<Estudi> resumEstudis() const;
  set<Nacionalitat> resumNacionalitats() const;
  list<string> estudisEdatNacio(int edat, int nacionalitat) const;

private:
  map<int, list<Persona>> a_hab;
  set<Estudi> a_resumEstudis;
  set<Nacionalitat> a_resumNacionalitats;
  int a_any;
  double suma_edats;
};

#endif // DISTRICTE_H
