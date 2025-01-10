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
  double desviacioOptima;
  int tornsOptima;
  bool aEncertat;
};

#endif // !SOLUCIONADOR_H
