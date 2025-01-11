// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Solucio.h
/// @brief Classe Solucio
#ifndef SOLUCIO_H
#define SOLUCIO_H

#include "Assignatura.h"
#include "Candidats.h"
#include "Torn.h"
#include <map>
#include <ostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**
  @class Solucio
  @brief Solucio del Backtracking

  Classe que s'encarrega de tota la informacio necessaria per a la solucio i per
  a comprovar les operacions del Backtracking.
*/
class Solucio {
public:
  /// Constructor per defecte
  Solucio() {};

  
  /**
    @param assig vector de assignatures primer les grans i despres les reduides 
    @param restriccions estructura de dades amb les restriccions entre assignatures
    @param gc nombre d'aules de gran capacitat
    @param cr nombre d'aules de capacitat reduida
    @param d nombre de dies maxim
    @pre parametres valids
    @brief constructor d'una solucio inicial per a executar un dels metodes de backtracking
  */
  Solucio(vector<Assignatura>& assig, map<int, set<int>>& restriccions, int gc, int cr, int d);

  /**
    @return Candidats
    @pre cert
    @brief Inicialitza els candidats del nivell corresponent de l'arbre de backtracking 
  */
  Candidats inicialitzarCandidats();

  /**
    @return bool
    @param iCand candidats del nivell
    @pre cert
    @brief retorna true si el candidat actual es acceptable en la posicio d'aquest nivell
  */
  bool acceptable(const Candidats& iCand) const;

  /**
    @return bool
    @pre cert
    @brief retorna true si la solucio es completa
  */
  bool completa() const;

  /**
    @return bool
    @pre cert
    @brief retorna true si la solucio encara no ha sobrepassat el nombre de dies indicats com a limit 
  */
  bool completable() const; 

  /**
    @return bool
    @param tornsOptima nombre de torns de la solucio optima actual
    @param desviacioOptima valor de la desviacio mitjana de la solucio optima actual 
    @pre cert
    @brief retorna true si la solucio actual es millor que la solucio optima
  */
  bool esMillor(int tornsOptima, double desviacioOptima) const;

  /**
    @return bool
    @param tornsOptima nombre de torns de la solucio optima actual
    @pre cert
    @brief retorna true si la solucio actual pot ser millor que la solucio optima
  */
  bool esMillorable(int tornsOptima) const;

  /**
    @return double
    @pre cert
    @brief retorna la desviacio mitjana de la solucio actual
  */
  double obtDesviacioMitjana() const;

  /**
    @return int
    @pre cert
    @brief retorna el nombre de torns de la solucio actual
  */
  int obtTorns() const;

  /**
    @param iCand index dels candidats
    @pre cert
    @brief anota el candidat actual a la solucio
  */
  void anotar(const Candidats& iCand);

  /**
    @param iCand index dels candidats
    @pre cert
    @brief desanota el candidat actual a la solucio
  */
  void desanotar(const Candidats& iCand);


  /**
    @param o objecte ostream anterior
    @param s Solucio la qual es vol mostrar
    @pre cert
    @brief operator<< -> afegeix la solucio s al objecte o per a mostrar
  */
  friend ostream& operator<<(ostream& o, const Solucio& s);

  /**
    @param bool
    @pre cert
    @brief metode que executa un algoritme vorac i retorna true si ha trobat solucio
  */
  bool solucioRapida();

private:
  /// vector de totes les assignatures (grans primer i reduides al darrere)
  vector<Assignatura> aAssignatures;

  /// restriccions de les assignatures guardades en funcio de la posicio 
  /// del vector aAssignatures
  map<int, set<int>> aRestriccions;

  /// vector en mateix ordre que aAssignatures que guarda booleans per a saber si una
  /// assignatura ja s'ha escrit en algun torn
  vector<bool> aAssignaturesUtilitzada;

  /// llista de torns de la solucio actual
  list<Torn> aSolucioActual;

  /// nivell i torns de la solucio actual 
  int aNiv, aTorns;

  /// valors maxims de les aules de gran capacitat, capacitat reduida i dels dies del horari
  int aGcMax, aCrMax, aDiesMax;
  
  /**
    @return map<string,double>
    @pre cert
    @brief metode privat utilitzat per obtDesviacioMitjana que retorna
    la desviacio estandard de cada grau i curs
  */
  map<string, double> obtDesviacioGrauCurs() const;

  /**
    @return int
    @pre cert
    @brief metode privat necessari per solucioRapida que seleccionar
    un candidat prometedor
  */
  int seleccionarPrometedor() const;

  /**
    @return bool
    @pre cert
    @brief metode privat necessari per solucioRapida que retorna
    true si la solucio es completa
  */
  bool completaR() const;

  /**
    @return bool
    @param x codi de la assignatura prometedora  
    @pre cert
    @brief metode privat necessari per solucioRapida que retorna
    true si la solucio es completable amb la assignatura x
  */
  bool completableR(string x) const;

  /**
    @return bool
    @pre cert
    @brief metode privat necessari per solucioRapida que retorna
    true si queden candidats per a afegir
  */
  bool quedenCandidats() const;

  /**
    @param x index de la posicio de la assignatura que es vol afegir
    @pre cert
    @brief metode privat necessari per solucioRapida que afegeix
    una assignatura a la solucio
  */
  void afegirR(int x);
};

#endif // !SOLUCIO_H
