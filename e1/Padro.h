// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef PADRO_H
#define PADRO_H
#include "Districte.h"
#include <istream>

using namespace std;

class Padro {
public:
  Padro();
  int afegir(int any, int districte, int codiNivellEstudis,
             const string &nivellEstudis, int anyNaixement,
             int codiNacionalitat, const string &nomNacionalitat);
  // CONTENIDOR obtenirNumHabitantsPerDistricte() const;
  // CONTENIDOR resumEdat() const;
  // CONTENIDOR resumEstudis() const;
  // CONTENIDOR edatNacioPerDistricte(int edat, int codiNacionalitat) const;
  // CONTENIDOR diferentsNacionalitats(int districte1, int districte2) const;

private:
};

#endif // PADRO_H
