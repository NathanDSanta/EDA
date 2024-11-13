// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef DISTRICTE_H
#define DISTRICTE_H
#include <list>
#include <map>
#include <set>

#include "Estudi.h"
#include "Nacionalitat.h"
#include "Seccio.h"

class Districte {
 public:
  Districte();
  void afegir(int any, int seccio, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
  long obtenirNumHabitants() const;
  double obtenirEdatMitjana() const;
  set<Estudi> resumEstudis() const;
  set<Nacionalitat> resumNacionalitats() const;
  list<string> estudisEdatNacio(int any, int edat, int nacionalitat) const;

 private:
  map<int, Seccio> a_seccions;
  set<Estudi> a_resumEstudis;
  set<Nacionalitat> a_resumNacionalitats;
  double suma_edats;
};

#endif  // DISTRICTE_H
