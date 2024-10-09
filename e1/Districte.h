// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef DISTRICTE_H
#define DISTRICTE_H
#include "Persona.h"

class Districte {
public:
  Districte();
  void afegir(int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
  long obtenirNumHabitants() const;
  double obtenirEdatMitjana() const;
  list<string> resumEstudis() const;
  list<string> resumNacionalitats() const;
  long comptaEdatNacionalitat(int edat, int codiNacionalitat) const;

private:
  list<Persona> a_hab;
  int a_any;
  long a_num_hab;
};

#endif // DISTRICTE_H
