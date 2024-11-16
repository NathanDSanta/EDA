// Darius Natan Santa
// u1994947
// Practica 1
//
/// @file Districte.h
/// @brief Classe Districte

#ifndef DISTRICTE_H
#define DISTRICTE_H
#include <list>
#include <map>
#include <set>

#include "Estudi.h"
#include "Nacionalitat.h"
#include "Seccio.h"

/**
  @class Districte
  @brief Districte del Padro

  Aquesta classe guarda les dades d'un determinat Districte del Padro, tambe es
  guarden algunes estructures auxiliars per a la eficiencia del programa
*/

class Districte {
public:
  /// Constructor per defecte
  Districte();

  /**
    @param any valor de la persona a afegir
    @param seccio valor de la persona a afegir
    @param codiNivellEstudis valor de la persona a afegir
    @param nivellEstudis valor de la persona a afegir
    @param anyNaixement valor de la persona a afegir
    @param codiNacionalitat valor de la persona a afegir
    @param nomNacionalitat valor de la persona a afegir
    @pre parametres valida
    @brief metode que afegeix en una seccio determinada la persona amb les dades
    indicades
  */
  void afegir(int any, int seccio, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);

  /**
    @return long
    @pre cert
    @brief Retorna el nombre d'habitants del districte
  */
  long obtenirNumHabitants() const;

  /**
    @return map<int,long>
    @pre cert
    @brief retorna el nombre d'habitants per cada seccio del districte
  */
  map<int, long> obtenirNumHabitantsPerSeccio() const;

  /**
    @return double
    @pre cert
    @brief retorna el promig del nivell d'estudis del districte
  */
  double obtenirPromigNivellEstudis() const;

  /**
    @return set<Nacionalitat>
    @pre cert
    @brief retorna les diferents nacionalitats del districte
  */
  set<Nacionalitat> resumNacionalitats() const;

  /**
    @return long
    @param codiNacionalitat codi de la nacionalitat a filtrar
    @pre codiNacionalitat existent
    @brief retorna el nombre d'habitants amb nacionalitat indicada
  */
  long obtenirNumHabitantsNacio(int codiNacionalitat) const;

  /**
    @return double
    @pre cer
    @brief retorna la edat mitjana dels habitants del districte
  */
  double obtenirEdatMitjana() const;

  /**
    @return set<Estudi>
    @pre cert
    @brief retorna els diferents estudis dels habitants del districte
  */
  set<Estudi> resumEstudis() const;

  /**
    @return long
    @param any any actual
    @param edat1 limit inferior d'edat
    @param edat2 limit superior d'edat
    @pre any existent
    @brief retonra el nombre d'habitants compresos entre les dues edats limit
    edat1 i edat2
  */
  long obtenirNumHabitantsEdatEntre(int any, int edat1, int edat2) const;

  /**
    @return list<string>
    @param any any actual
    @param edat edat de filtreig
    @param nacioanlitat nacionalitat de mostreig
    @pre any i nacionalitat existents
    @brief retorna una llista amb els estudis dels habitants del districte amb
    una edat i nacionalitat determianda
  */
  list<string> estudisEdatNacio(int any, int edat, int nacionalitat) const;

private:
  /// map que guarda les dades de les diferents seccions del districte
  map<int, Seccio> a_seccions;

  // set que guarda els diferents estudis del districte
  set<Estudi> a_resumEstudis;

  // set que guarda les diferents nacionalitats del districte
  set<Nacionalitat> a_resumNacionalitats;

  // map on es guarda el nombre d'habitants d'una nacionalitat
  map<int, long> a_resumHabitantsNacio;

  // la suma d'edats dels habitants preparada per a calcular la mitjana
  double sumaEdats;

  // la suma del nivell d'estudis preparada per a calcular el promig
  double sumaPromigEstudis;
};

#endif // DISTRICTE_H
