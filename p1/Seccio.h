// Darius Natan Santa
// u1994947
// Practica 1
//
/// @file Seccio.h
/// @brief Classe Seccio
#include <list>

#include "Persona.h"
using namespace std;

/**
  @class Seccio
  @brief Seccio d'un Districte

  Aquest classe guarda la informacio dels habitants d'una seccio d'un districte.
*/
class Seccio {
public:
  /// Constructor per defecte
  Seccio();

  /**
    @param codiNivellEstudis valor de la persona a afegir
    @param nivellEstudis valor de la persona a afegir
    @param anyNaixement valor de la persona a afegir
    @param codiNacionalitat valor de la persona a afegir
    @param nomNacionalitat valor de la persona a afegir
    @pre parametres valids
    @brief metode que afegeix a la llista d'habitants la persona amb les dades
    indicades
  */
  void afegir(int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat);

  /**
    @return long
    @pre cert
    @brief retorna el nombre d'habitants de la seccio
  */
  long obtenirNumHabitants() const;

  /**
    @return long
    @param any any actual
    @param edat1 edat llindar inferior
    @param edat2 edat llindar superior
    @pre any existent
    @brief retorna el nombre d'habitants amb edat entre edat1 i edat2
  */
  long obtenirNumHabitantsEdatEntre(int any, int edat1, int edat2) const;

  /**
    @return list<string>
    @param any any actual
    @param edat filtre d'edat
    @param nacionalitat filtre de nacionalitat
    @pre any i nacionalitat existent
    @brief retorna una llista d'estudis dels habitants amb una edat i
    nacionalitat concreta
  */
  list<string> estudisEdatNacio(int any, int edat, int nacionalitat) const;

private:
  /// llista dels habitants de la seccio
  list<Persona> a_hab;
};
