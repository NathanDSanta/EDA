// Darius Natan Santa
// u1994947
// Practica 1
//
/// @file Nacionalitat.h
/// @brief Classe Nacionalitat
#ifndef NACIONALITAT_H
#define NACIONALITAT_H
#include <cstdlib>
#include <iostream>
using namespace std;

/**
  @class Nacionalitat
  @brief Guarda les dades d'una Nacionalitat
*/

class Nacionalitat {
public:
  /// Constructor amb parametres inicialitzats per defecte
  Nacionalitat(int id = 0, string nom = "");

  /// Geter del codi de l'estudi
  int obtenirId() const;

  /// Getter del nom de l'estudi
  string obtenirNom() const;

  /// Operador igual segons el codi
  bool operator==(const Nacionalitat &nacio) const;

  /// Operador mes petit segons el nom
  bool operator<(const Nacionalitat &nacio) const;

private:
  /// Codi de l'estudi
  int a_id;

  /// Nom de l'estudi
  string a_nom;
};

#endif // NACIONALITAT_H
