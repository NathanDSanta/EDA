// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Torn.h
/// @brief Classe Torn
#ifndef TORN_H
#define TORN_H
#include <list>
#include <ostream>
#include <set>
#include <string>
using namespace std;

/**
  @class Torn
  @brief Torn de examen
  
  Classe que guarda la informacio d'un torn d'examen, tambe s'encarrega de
  tenir un nombre correcte de aules de gran capacitat i capacitat reduida utilitzades
*/

class Torn {
public:
  /// Constructor amb parametres per defecte
  Torn(int gc = 1, int cr = 1);

  /**
    @return bool
    @pre cert
    @brief retorna true si el torn esta ple
  */
  bool ple() const;

  /**
    @return bool
    @pre cert
    @brief retorna true si el torn esta buit
  */
  bool buit() const;

  /**
    @return bool
    @pre cert
    @brief retorna true si s'han utilitzat totes les aules de gran capacitat
  */
  bool gcCompletes() const;

  /**
    @return bool
    @param codiGrauCurs codi del Grau i Curs que es vol tractar
    @pre cert
    @brief retorna true si ja hi ha un examen del mateix grau i curs
  */
  bool existeixGrauCurs(string codiGrauCurs) const;

  /**
    @return bool
    @param assignatures llista de assignatures restringides
    @pre cert
    @brief retorna true si existeix una assignatura de les restriccions
  */
  bool existeixAlgunaAssignatura(set<int> assignatures) const;

  /**
    @return list<int>
    @pre cert
    @brief retorna els examens d'aquest torn
  */
  list<int> obtExamens() const;

  /**
    @return set<string>
    @pre cert
    @brief retorna els codis de les parelles Grau-Curs d'aquest torn
  */
  set<string> obtGrauCursos() const;

  /**
    @param codiGrauCurs codi del grau i curs de la assignatura que es vol anotar
    @param assignatura index de la assignatura que es vol anotar
    @param esGran boolea que indica si la assignatura necessita una aula de gran capacitat
    @pre cert
    @brief anota l'examen d'aquesta assignatura al torn actual
  */
  void anotar(string codiGrauCurs, int assignatura, bool esGran);

  /**
    @param codiGrauCurs codi del grau i curs de la assignatura que es vol desanotar
    @param assignatura index de la assignatura que es vol desanotar
    @param esGran boolea que indica si la assignatura necessita una aula de gran capacitat
    @pre cert
    @brief desanota l'examen d'aquesta assignatura al torn actual
  */
  void desanotar(string CodiGrauCurs, int assignatura, bool esGran);

  /**
    @param o objecte ostream anterior
    @param t torn el qual es vol mostrar
    @pre cert
    @brief metode de debugging que mostra la informacio que guarda un torn
  */
  friend ostream& operator<<(ostream& o, const Torn& t);

private:
  ///llista d'examens del torn
  list<int> aExamens;

  /// llista dels Grau-Cursos que tenen examen en aquest torn
  set<string> aGrauCursos;

  /// aules de cada tipus utilitzades en aquest torn
  int aGcUsades, aCrUsades;

  /// maxim d'aules de cada tipus que es pot utilitzar en aquest torn
  int aGcMax, aCrMax;
};

#endif // !TORN_H
