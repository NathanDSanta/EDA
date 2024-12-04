#include "Solucionador.h"
#include "Candidats.h"
#include "Solucio.h"
#include <iostream>

void Solucionador::solucionar(const Solucio &inicial, bool solucioOptima) {
  Solucio actual = inicial;
  bool trobat = false;
  if (solucioOptima)
    trobarOptima(actual);
  else
    trobarPrimera(actual, trobat);
  aSolucio = actual;
}

void Solucionador::trobarPrimera(Solucio &actual, bool &trobat) {
  Candidats iCand = actual.inicialitzarCandidats();
  while (!iCand.end() && !trobat) {
    if (actual.acceptable(iCand)) {
      actual.anotar(iCand);
      if (!actual.completa()) {
        trobarPrimera(actual, trobat);
        if (!trobat) {
          actual.desanotar(iCand);
        }
      } else
        trobat = true;
    }
    cout << iCand.actual();
    iCand++;
  }
}

void Solucionador::trobarOptima(Solucio &actual) {
  Candidats iCand = actual.inicialitzarCandidats();
  while (!iCand.end()) {
    if (actual.acceptable(iCand) && actual.esMillor(aSolucio.obtTorns())) {
      actual.anotar(iCand);
      if (!actual.completa()) {
        trobarOptima(actual);
      } else if (actual.esMillor(aSolucio.obtTorns())) {
        aSolucio = actual;
      }
      actual.desanotar(iCand);
    }
    iCand++;
  }
}

Solucio Solucionador::obtSolucio() { return aSolucio; }
