// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Assignatura.h
/// @brief Classe Assignatura
#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H

#include <ostream>
#include <set>
#include <string>
using namespace std;

/**
  @class Assignatura
  @brief Informacio de una Assignatura

  En aquesta classe es guarden totes les dades d'una assignatura
*/
class Assignatura {
public:
  /// Constructor amb tots els parametres amb la posibiltat de deixar-ne per defecte algun
  Assignatura(string codi = "", string nom = "", string grau = "", bool esTipusGran = false, double credits = 0, int semestre = 0, int curs = 0);

  /**
    @return bool
    @pre cert
    @brief retorna true si la assignatura necessita una aula de Gran Capacitat 
  */
  bool obtEsGran() const;

  /**
    @return string
    @pre cert
    @brief retorna el codi de la assignatura
  */
  string obtCodi() const;

  /**
    @return string
    @pre cert
    @brief retorna el grau de la assignatura
  */
  string obtGrau() const;

  /**
    @return string
    @pre cert
    @brief retorna el curs de la assignatura
  */
  string obtCurs() const;

  /**
    @return bool
    @param a assignatura que es compara amb "this" 
    @pre cert
    @brief operador == -> retorna true si els codis de les assignatures comparades son iguals 
  */
  bool operator==(const Assignatura &a) const;

  /**
    @return bool
    @param a assignatura que es compara amb "this" 
    @pre cert
    @brief operador < -> retorna true si el codis de la assignatura esquerra es mes petit que el de la dreta
  */
  bool operator<(const Assignatura &a) const;

  /**
    @return ostream&
    @param o objecte ostream anterior 
    @param a assignatura que es vol afegir al objecte ostream per mostrar 
    @pre cert
    @brief operador << -> utiltizat per a mostrar l'examen d'una assignatura 
  */
  friend ostream& operator<<(ostream& o, const Assignatura& a);

private:
  /// Grau de la assignatura (GEINF, GDDV, ...)
  string aGrau;

  /// Nom de la assignatura (EDA, MTP1, ....)
  string aNom;

  /// Codi de la assignatura
  string aCodi; 

  /// Mida de la aula necessaria per a la assignatura
  bool aEsTipusGran;

  /// Credits de la assignatura
  double aCredits;

  /// Semestre de la assignatura
  int aSemestre;

  /// Curs del grau de la assignatura
  int aCurs;
};

#endif // !ASSIGNATURA_H
