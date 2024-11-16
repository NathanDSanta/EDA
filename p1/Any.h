// Darius Natan, Santa
// u1994947
// Practica 1
//
/// @file Any.h
/// @brief Classe Any

#ifndef ANY_H
#define ANY_H

#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "Districte.h"
#include "Nacionalitat.h"
using namespace std;

/**
  @class Any
  @brief Padro d'un Any en concret

  En aquesta classe es guarden les dades d'un any en concret del Padro.
*/
class Any {
 public:
  /// Constructor per defecte amb paramaetre any com a inicialitzacio
  /// alternativa
  Any(int any = 0);

  /**
    @param any valor de la persona a afegir
    @param districte valor de la persona a afegir
    @param seccio valor de la persona a afegir
    @param codiNivellEstudis valor de la persona a afegir
    @param nivellEstudis valor de la persona a afegir
    @param anyNaixement valor de la persona a afegir
    @param codiNacionalitat valor de la persona a afegir
    @param nomNacionalitat valor de la persona a afegir
    @pre parametres correctes + any, districte i seccio existents
    @post persona afegida al registre d'aquest any
    @brief Aquest metode afegeix una persona al registre d'aquest any
  */
  void afegir(int any, int districte, int seccio, int codiNivellEstudis,
              string nivellEstudis, int anyNaixement, int codiNacionalitat,
              string nomNacionalitat);

  /**
    @return map<double,string>
    @pre cert
    @brief el metode consulta els districtes i retorna la seva edat mitjana
  */
  map<double, string> obtenirEdatsMitjanes() const;

  /**
    @return long
    @pre cert
    @brief retorna el nombre d'habitants total del registre d'aquest any
  */
  long obtenirNumHabitants() const;

  /**
    @return vector<long>
    @pre cert
    @brief retorna el nombre d'habitants per cada districte
  */
  vector<long> obtenirNumHabitantsPerDistricte() const;

  /**
    @return map<int,long>
    @param districte el districte del qual es consulten les seccions
    @pre districte existent
    @brief retorna el nombre d'habitants per cada seccio del districte indicat
  */
  map<int, long> obtenirNumHabitantsPerSeccio(int districte) const;

  /**
    @return map<int, pair<double,int>>
    @pre cert
    @brief retorna el promig del nivell d'estudis per cada districte, el promig
    amb valor mes gran retorna el int amb 1, el menor amb -1, els altres en 0
  */
  map<int, pair<double, int>> resumNivellEstudis() const;

  /**
    @return list<pair<long,Nacionalitat>>
    @pre cert
    @brief retorna totes les nacionalitats d'aquest any amb el nombre
    d'habitants per cada nacionalitat ordenades per nombre d'habitants i codi de
    nacionalitat
  */
  list<pair<long, Nacionalitat>> resumNacionalitats() const;

  /**
    @return string
    @param codiNacionalitat el codi de la nacionalitat que s'analitza
    @brief retorna el nom del districte amb mes habitants de la nacionalitat
    indicada
  */
  string movimentsComunitat(int codiNacionalitat) const;

  /**
    @return set<Estudi>
    @param districte (valor per defecte = 0) districte del qual es vol saber els
    estudis
    @pre districte existent (si s'especifica)
    @brief Aquest metode, quan districte = 0 (comportament per defecte) retorna
    tots els diferents estudis del padro d'aquest any, en canvi, quan un
    districte es especificat, els estudis retornats son nomes del districte
    donat
  */
  set<Estudi> resumEstudis(int districte = 0) const;

  /**
    @return string
    @pre cert
    @brief retorna el nom del districte mes envellit
  */
  string movimentVells() const;

  /**
    @return vector<long>
    @pre cert
    @brief retorna un vetor amb la poblacio de Joves de cada districte
  */
  vector<long> poblacioJovesDistricte() const;

  /**
    @return list<string>
    @param districte determinacio de poblacio per experimentar
    @param edat valor de l'edat dels individus a analitzar
    @param codiNacionalitat codi de la nacionalitat dels individus
    @pre districte i codiNacionalitat existent
    @brief aquest metode retorna una llista amb els estudis que tenen una
    poblacio d'una determinada edat i nacionalitat d'un districte concret
  */
  list<string> estudisEdatNacio(int districte, int edat,
                                int codiNacionalitat) const;

  /// Numero de Districtes
  static const int N_DISTRICTES = 6;

  /// Nom dels districtes
  static const string DISTRICTES[N_DISTRICTES + 1];

 private:
  /// any del padro
  int a_any;

  /// vector amb les dades dels diferents districtes
  vector<Districte> a_districtes;
};

#endif  // !ANY_H
