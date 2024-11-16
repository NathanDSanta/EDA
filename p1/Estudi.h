// Darius Natan Santa
// u1994947
// Practica 1
//
/// @file Estudi.h
/// @brief Classe Estudi
#ifndef ESTUDI_H
#define ESTUDI_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <vector>
using namespace std;

/**
  @class Estudi
  @brief Guarda les dades d'un Estudi
*/
class Estudi {
public:
  /// Constructor amb parametres inicialitzats per defecte
  Estudi(int id = 0, string nom = "");

  /// Getter del codi de l'estudi
  int obtenirId() const;

  /// Getter del nom de l'estudi
  string obtenirNom() const;

  /// Operador igual segons el codi
  bool operator==(const Estudi &estudi) const;

  /// Operador mes petit segons el nom
  bool operator<(const Estudi &estudi) const;

private:
  /// Codi de l'estudi
  int a_id;

  /// Nom de l'estudi
  string a_nom;
};

#endif // ESTUDI_H
