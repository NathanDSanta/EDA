#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"

class Solucionador {
public:
  Solucionador();
  void solucionar(const Solucio& inicial, int algoritme);
  void trobarRapid();
  void trobarPrimera();
  void trobarMillor();
  Solucio obtSolucio();

private:
  Solucio aOptima;  
};

#endif // !SOLUCIONADOR_H
