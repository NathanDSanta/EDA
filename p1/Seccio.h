#include <list>

#include "Persona.h"
using namespace std;

class Seccio {
public:
  Seccio();
  void afegir(int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat);
  long obtenirNumHabitants() const;
  long obtenirNumHabitantsEdatEntre(int any, int edat1, int edat2) const;
  list<string> estudisEdatNacio(int any, int edat, int nacionalitat) const;

private:
  list<Persona> a_hab;
};
