#include "Solucionador.h"
#include "Solucio.h"
#include <iostream>
#include <limits>
using namespace std;

Solucio Solucionador::solucionar(const Solucio &inicial, string algoritme) {
  Solucio actual = inicial;
  aEncertat = false;
  tornsOptima = numeric_limits<int>::max();
  desviacioOptima = 0;
  aOptima = inicial;
  if (algoritme == "RAPID")
    trobarRapid(actual);
  else if(algoritme == "PRIMER")
    trobarPrimera(actual);
  else //algoritme == "MILLOR" 
    trobarMillor(actual);
  return aOptima;
}

void Solucionador::trobarRapid(Solucio &actual) {}

void Solucionador::trobarPrimera(Solucio &actual) {
  Candidats iCand = actual.inicialitzarCandidats();
  while (!iCand.esFi() && !aEncertat) {
    if (actual.acceptable(iCand) && actual.completable()) {
      actual.anotar(iCand);
      if (!actual.completa()) {
        trobarPrimera(actual);
        if (!aEncertat) {
          actual.desanotar(iCand);
        }
      } else {
        aEncertat = true;
      }
    }
    iCand++;
  }
}

void Solucionador::trobarMillor(Solucio &actual) {
  Candidats iCand = actual.inicialitzarCandidats();
  while (!iCand.esFi()) {
    if (actual.completable() && actual.acceptable(iCand)) {
      actual.anotar(iCand);
      if (!actual.completa()) {
        trobarPrimera(actual);
      } else {
        if (actual.esMillor(tornsOptima, desviacioOptima)) {
          aOptima = actual;
          desviacioOptima = actual.obtDesviacioMitjana();
          tornsOptima = actual.obtTorns();
        }
      }
      actual.desanotar(iCand);
    }
    iCand++;
  }
}

void Solucionador::mostrarSolucio() const{
  cout << "Solucio: \n" << aOptima << endl
  << "Desviacio: " << desviacioOptima << endl
  << "Torns: " << tornsOptima << endl;
}
