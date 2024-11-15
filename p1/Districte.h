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
  map<int, long> obtenirNumHabitantsPerSeccio() const;
  double obtenirPromigNivellEstudis() const;
  set<Nacionalitat> resumNacionalitats() const;
  long obtenirNumHabitantsNacio(int codiNacionalitat) const;
  double obtenirEdatMitjana() const;
  set<Estudi> resumEstudis() const;
  long obtenirNumHabitantsEdatEntre(int any, int edat1, int edat2) const;
  list<string> estudisEdatNacio(int any, int edat, int nacionalitat) const;

private:
  map<int, Seccio> a_seccions;
  set<Estudi> a_resumEstudis;
  set<Nacionalitat> a_resumNacionalitats;
  map<int, long> a_resumHabitantsNacio;
  double sumaEdats;
  double sumaPromigEstudis;
};

#endif // DISTRICTE_H
