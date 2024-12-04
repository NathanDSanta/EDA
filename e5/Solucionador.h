#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "Solucio.h"
#include "Candidats.h"
#include "Torn.h"
#include <vector>
using namespace std;

class Solucionador {
public:
  Solucionador() {};
  void solucionar(const Solucio& inicial, bool solucioOptima);
  void trobarOptima(Solucio& actual);
  void trobarPrimera(Solucio& actual, bool& trobat);
  Solucio obtSolucio();

private:
  Solucio aSolucio;
};
#endif // !SOLUCIONADOR_H
