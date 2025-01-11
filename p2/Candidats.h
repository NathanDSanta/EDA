// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Candidats.h
/// @brief Classe Candidats
#ifndef CANDIDATS_H
#define CANDIDATS_H
#include <limits>
#include <string>
using namespace std;

/**
  @class Candidats
  @brief Classe que guarda la informacio sobre els candidats 

  Classe que forma part del metode de backtracking necessaria
  per a gestionar els candidats
*/
class Candidats {
public:
  /// Constructor per defecte i parametres per defecte
  Candidats(int inici = 0, int final = numeric_limits<int>::max());


  /**
    @return bool
    @pre cert
    @brief retorna true si es el final dels candidats
  */
  bool esFi() const;

  /**
    @return int
    @pre cert
    @brief retorna el index del candidat actual
  */
  int actual() const;

  /**
    @pre cert
    @brief seguent candidat 
  */
  void operator++(int);

private:
  /// index del candidat actual
  int aActual;

  /// index del candidat final
  int aMax;
};

#endif // !CANDIDATS_H
