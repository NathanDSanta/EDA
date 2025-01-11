#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"

class Solucionador {
public:
  Solucionador() {};
  Solucio solucionar(const Solucio& inicial, string algoritme);
  void trobarRapid(Solucio& actual);
  void trobarPrimera(Solucio& actual);
  void trobarMillor(Solucio& actual);
  void mostrarSolucio() const;

private:
  Solucio aOptima;  
  double aDesviacioOptima;
  int aTornsOptima;
  bool aEncertat;
  bool aRapid;
};

#endif // !SOLUCIONADOR_H
