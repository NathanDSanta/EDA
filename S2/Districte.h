#ifndef DISTRICTE_H
#define DISTRICTE_H
#include "Persona.h"
#include <cstdlib>
#include <list>

using namespace std;

class Districte {
public:
  Districte() {};
  void afegir(int any, int codiNivellEstudis, const string &nivellEstudis,
              int anyNaixement, int codiNacionalitat,
              const string &nomNacionalitat);
  long obtenirNumHabitants() const;
  double obtenirEdatMitjana() const;
  // CONTENIDOR resumEstudis() const;
  // CONTENIDOR resumNacionalitats() const;
  long comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const;

private:
  list<Persona> a_hab;
  long a_numHab;
};

#endif // DISTRICTE_H
