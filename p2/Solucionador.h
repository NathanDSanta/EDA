// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Solucionador.h
/// @brief Classe Solucionador
#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"

/**
  @class Solucionador
  @brief Solucionador de l'horari 

  Classe que s'encarrega dels esquemes recursius i de seleccionar l'algoritme
  desitjat de les 3 opcions. Tambe s'encarrega de guardar la solucio optima i
  la seva desviacio estandard mitjana i torns
*/
class Solucionador {
public:
  /// Constructor per defecte
  Solucionador() {};

  /**
    @return Solucio
    @param inicial solucio inicial de l'algoritme que es vol executar 
    @param algoritme nom del algoritme que es vol executar
    @pre algoritme == "PRIMER" || "MILLOR" || "RAPID"
    @brief metode que guarda la solucio del problema a aOptima i la retorna
    per si s'escau el seu us, utiltiza l'algoritme que s'especifica amb 
    l'string "algoritme"
  */
  Solucio solucionar(const Solucio& inicial, string algoritme);

  /**
    @param actual solucio sobre la que s'esta executant l'algoritme 
    @pre cert
    @brief metode que executa l'algoritme vorac per intentar trobar una solucio 
  */
  void trobarRapid(Solucio& actual);

  /**
    @param actual solucio sobre la que s'esta executant l'algoritme recursiu
    @pre cert
    @brief metode que executa l'algoritme vorac per trobar una solucio (la primera)
  */
  void trobarPrimera(Solucio& actual);

  /**
    @param actual solucio sobre la que s'esta executant l'algoritme recursiu
    @pre cert
    @brief metode que executa l'algoritme vorac per trobar la millor solucio
  */
  void trobarMillor(Solucio& actual);

  /**
    @param temps temps que ha tardat l'execucio en segons
    @pre cert
    @brief metode que mostra la solucio
  */
  void mostrarSolucio(double temps) const;

private:
  /// Solucio final (optima si s'executa trobarMillor())
  Solucio aOptima;  

  /// Desviacio de la solucio final
  double aDesviacioOptima;

  /// Torns de la solucio final
  int aTornsOptima;

  /// boolea que indica si s'ha trobat solucio
  bool aEncertat;

};

#endif // !SOLUCIONADOR_H
