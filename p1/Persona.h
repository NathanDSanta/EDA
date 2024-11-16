// Darius Natan Santa
// u1994947
// Practica 1
//
// @file Persona.h
// @brief Classe Persona
#ifndef PERSONA_H
#define PERSONA_H
#include "Estudi.h"
#include "Nacionalitat.h"

/**
@class Persona
@brief Dades d'una Persona

Aquest classe guarda les dades d'un sol habitant
*/
class Persona {
public:
  /**
    @param codiNivellEstudis codi dels estudis de la Persona
    @param nivellEstudis nom dels estudis de la Persona
    @param anyNaixement any de naixement de la Persona
    @param codiNacionalitat codi de la Nacionalitat de la Persona
    @param nomNacionalitat nom de la Nacionalitat de la Persona
    @brief Constructor per defecte d'una persona, amb posibilitat de passar els
    parametres de manera explicita
    */
  Persona(int codiNivellEstudis = 0, const string &nivellEstudis = "", int anyNaixement = 0, int codiNacionalitat = 0, const string &nomNacionalitat = "");

  /**
    @return int
    @pre cert
    @brief Getter de l'any de naixement
  */
  int obtenirAnyNaixement() const;

  /**
    @return string
    @pre cert
    @brief Getter del nom del nivell d'estudis
  */
  string obtenirNivellEstudis() const;

  /**
    @return int
    @pre cert
    @brief Getter del codi del pais de naixement (nacionalitat)
  */
  int obtenirCodiPaisNaixement() const;

private:
  /// Estudi de la persona
  Estudi a_est;

  /// Nacionalitat de la persona
  Nacionalitat a_nac;

  /// Any de naixement de la persona
  int a_anyNaix;
};

#endif // PERSONA_H
