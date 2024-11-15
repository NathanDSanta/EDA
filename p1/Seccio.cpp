#include "Seccio.h"
#include "Persona.h"

#include <list>
#include <string>
using namespace std;

Seccio::Seccio() {};

void Seccio::afegir(int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat) {
  a_hab.push_back(Persona(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat));
}

long Seccio::obtenirNumHabitants() const {
  return a_hab.size();
}

long Seccio::obtenirNumHabitantsEdatEntre(int any, int edat1, int edat2) const{
  long comptador = 0;
  for (list<Persona>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    int edatPersona = any - i->obtenirAnyNaixement();
    if (edatPersona >= edat1 && edatPersona <= edat2) {
      comptador++; 
    }
  }
  return comptador;
}

list<string> Seccio::estudisEdatNacio(int any, int edat, int nacionalitat) const {
  list<string> aux;
  for (list<Persona>::const_iterator i = a_hab.begin(); i != a_hab.end(); i++) {
    int edatPersona = any - i->obtenirAnyNaixement();
    if (edatPersona == edat && i->obtenirCodiPaisNaixement() == nacionalitat) {
      aux.push_back(i->obtenirNivellEstudis());
    }
  }
  return aux;
}
