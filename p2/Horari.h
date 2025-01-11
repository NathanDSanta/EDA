// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Horari.h
/// @brief Classe Horari
#ifndef HORARI_H
#define HORARI_H
#include "Assignatura.h"
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

/**
  @class Horari
  @brief Horari d'examens

  Classe que guarda tota la informacio sobre les assignatures, restriccions
  capacitats, etc... i la que genera i mostra el horari d'examens
*/
class Horari {
public:
  /// Constructor per defecte amb valors per defecte segons el enunciat, tot i
  /// que no son exclusivament necessaris
  Horari(int gc = 1, int cr = 1, int s = 1, int d = numeric_limits<int>::max());

  /**
    @param fitxer nom del fitxer que es vol llegir on es guarden les assignatures
    @pre cert
    @brief Guarda totes les assignatures en les estructures corresponents
  */
  void llegirAssignatures(string fitxer);

  /**
    @param algoritme nom arbitrari del algoritme que es vol executar
    @pre cert
    @brief executa l'algoritme demanat, genera l'horari i el mostra
  */
  void generarIMostrarHorari(string algoritme = "PRIMER");

  /**
    @param o objecte ostream anterior
    @param h horari el qual es vol mostrar
    @pre cert
    @brief metode de debugging per mostrar tota la informacio que guarda 
    horari en un determinat moment
  */
  friend ostream &operator<<(ostream &o, const Horari &h);

private:
  /// totes les assignatures amb la seva informacio
  vector<Assignatura> aAssignatures;

  /// les restriccions de cada assignatura, indetificades per la posicio
  /// en la estructura aAssignatures
  map<int, set<int>> aRestriccions;

  /// informacio general sobre els parametres entrats per l'usuari
  int aGranCapacitat, aCapacitatReduida, aSemestre, aDiesMaxims;

  /// metode privat utilitzat en llegirAssignatures() per a buscar una 
  /// assignatura amb el codi i retornar la seva posicio en aAssignatures
  int trobarAssignatura(string codiAssignatura) const;
};

#endif // !HORARI_H
