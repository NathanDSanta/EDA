// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef PERSONA_H
#define PERSONA_H
#include "Estudi.h"
#include "Nacionalitat.h"

class Persona {
public:
  Persona(int codiNivellEstudis = 0, const string &nivellEstudis = "", int anyNaixement = 0, int codiNacionalitat = 0, const string &nomNacionalitat = "");
  int obtenirAnyNaixement() const;
  string obtenirNivellEstudis() const;
  int obtenirCodiPaisNaixement() const;

private:
  Estudi a_est;
  Nacionalitat a_nac;
  int a_anyNaix;
};

#endif // PERSONA_H
