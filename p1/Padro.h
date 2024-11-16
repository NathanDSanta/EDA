// Darius Natan, Santa
// u1994947
// Practica 1

/// @file Padro.h
/// @brief Classe Padro

#ifndef PADRO_H
#define PADRO_H

#include <list>
#include <map>
#include <string>
#include <vector>

#include "Any.h"
#include "ResumEdats.h"
#include "ResumEstudis.h"
#include "ResumNacionalitats.h"
#include "ResumNivellEstudis.h"

using namespace std;

/** @class Padro
    @brief Padro d'habitants

    En aquesta classe guardem totes les microdades i és el fonament de tota la
   pràctica. Des d'aquesta classe s'executen tots els mètodes principals del
   programa
*/
class Padro {
public:
  /// Constructor per defecte buit
  Padro() {}

  /**
    @return int
    @param path Adreca de l'arxiu csv del Padro
    @pre path = Adreca de l'arxiu csv
    @post dades llegides i inserides al Padro
    @brief Llegeix les dades d'un fitxer csv i les guarda al Padro
  */
  int llegirDades(const string &path);

  /**
    @return bool
    @param any Any del qual es vol consultar l'existencia
    @pre cert
    @brief Consulta el Padro i retorna si un any hi existeix
  */
  bool existeixAny(int any) const;

  /**
    @return map<int,long>
    @pre cert
    @brief Consulta el Padro i indica el nombre d'habitants que hi estan
    registrats a cada any
  */
  map<int, long> obtenirNumHabitantsPerAny() const;

  /**
    @return vector<long>
    @param any l'any del qual es vol consultar els habitants
    @pre existeixAny(any) = true
    @brief Consulta el Padro i indica el nombre d'habitants registrats en
    determinat Districte l'any indicat
   */
  vector<long> obtenirNumHabitantsPerDistricte(int any) const;

  /**
    @return map<int.long>
    @param any l'any del qual es vol consultar els habitants
    @param districte el districte del qual es vol consultar els habitants
    @pre any i districte existents
    @brief Consulta el Padro i indica el nombre d'habitants registrats per cada
    seccio en un determinat any i districte.
  */
  map<int, long> obtenirNumHabitantsPerSeccio(int any, int districte) const;

  /**
    @return ResumEstudis
    @pre cert
    @brief Consulta el Padro i indica tots els diferents Estudis dels habitants
    registrats per cada any del Padro
  */
  ResumEstudis resumEstudis() const;

  /**
    @return map<int,int>
    @param districte el districte que es desitja consultar
    @pre districte existent
    @brief Consulta el Padro i indica el nombre de diferents estudis que tenen
    els habitants del districte indicat
   */
  map<int, int> nombreEstudisDistricte(int districte) const;

  /**
    @return ResumNivellEstudis
    @brief Consulta el padro i per cada any de padro, indica el nivell d'estudis
    promig de cada districte, el districte mes estudios esta marcat amb un +, i
    el menys estudios amb un -
  */
  ResumNivellEstudis resumNivellEstudis() const;

  /**
    @return ResumNacionalitats
    @brief Es consulta el Padro i el programa indica el nom del es diferents
    nacionalitats (i el seu codi entre parentesis) i el nombre de persones
    d'aquella nacionalitat que formen part del padro de cada any.
  */
  ResumNacionalitats resumNacionalitats() const;

  /**
    @return map<int,string>
    @param codiNacionalitat codi de la nacionalitat la qual es desitja consultar
    @pre codiNacionalitat existent
    @brief El programa consulta el Padro i indica, per cada any, el nom del
    districte que conte mes habitants d'una determinada nacionalitat indicada
    per l'usuari
  */
  map<int, string> movimentsComunitat(int codiNacionalitat) const;

  /**
    @return ResumEdat
    seva edat promig
    @brief Es mostra el promig d'habitants de cada districte per cada any en
    ordre ascendent
  */
  ResumEdats resumEdat() const;

  /**
    @return map<int,string>
    @brief Per cada any, s'indica quin districte te els habitants mes vells
  */
  map<int, string> movimentVells() const;

  /**
    @return pair<string,long>
    @param anyInicial any d'inici del mostreig
    @param anyFinal any de fi del mostreig
    @pre anyInicial i anyFinal existents
    @brief Es retorna el nombre de districte amb un increment de poblacio jove
    mes alt durant un periode determinat
  */
  pair<string, long> mesJoves(int anyInicial, int anyFinal) const;

  /**
    @return list<string>
    @param any any de la mesura
    @param districte districte de filtreig
    @param edat edat de mostreig
    @param codiNacionalitat codi de la nacionalitat desitjada per evaluar
    @pre any districte i codiNacionalitat existents
    @brief S'indica els diferents estudis que els habitants d'una edat i nacio,
    localitzats en un districte determinat i en un any en concret
  */
  list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;

private:
  /// map on es guarda la informacio de cada any
  map<int, Any> a_anys;

  /**
    @return int
    @param s cadena de caracters que es vol convertir a enter
    @pre cert
    @brief El metode retorna l'enter generat de la cadena, o -1 en cas de que
    aquesta no sigui un enter valid
  */
  int stringToInt(string s) const;

  /**
    @return bool
    @param any valor a validar
    @param districte valor a validar
    @param seccio valor a validar
    @param codiNivellEstudis valor a validar
    @param anyNaixement valor a validar
    @param codiNacionalitat valor a validar
    @pre cert
    @brief petita funcio privada per a validar les dades d'una persona del
    padro, si alguna no es valida, la insercio s'anula
  */
  static bool validarDades(int any, int districte, int seccio, int codiNivellsEstudis, int anyNaixement, int codiNacionalitat);
};

#endif // PADRO_H
