// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef PERSONA_H
#define PERSONA_H
#include "Estudi.h"
#include "Nacionalitat.h"

class Persona {
public:
  Persona(int codiNivellEstudis = 0, const string &nivellEstudis = "", int anyNaixement = 0, int codiPaisNaixement = 0, const string &paisNaixement = "");
  int obtenirAnyNaixement() const;
  string obtenirNivellEstudis() const;
  int obtenirCodiPaisNaixement() const;

  string obtenirNomPaisNaixement() const;
  // Ho he afegit perquè no sé com aconseguir el nom d'altra manera

private:
  Estudi a_est;
  Nacionalitat a_nac;
  int a_anyNaix;
};

#endif // PERSONA_H
