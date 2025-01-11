// Darius Natan Santa
// u1994947
// Practica 2
//
/// @file Solucionador.cpp
/// @brief Implementacio de la classe Solucionador
#include "Solucionador.h"
#include "Solucio.h"
#include <iostream>
#include <limits>
using namespace std;

Solucio Solucionador::solucionar(const Solucio &inicial, string algoritme) {
  Solucio actual = inicial;
  aEncertat = false;
  aTornsOptima = numeric_limits<int>::max();
  aDesviacioOptima = 0;
  aOptima = inicial;
  if (algoritme == "RAPID") {
    trobarRapid(actual);
    aOptima = actual;
  } else if (algoritme == "PRIMER") {
    trobarPrimera(actual);
    aOptima = actual;
  } else // algoritme == "MILLOR"
    trobarMillor(actual);
  return actual;
}

void Solucionador::trobarRapid(Solucio &actual) {
  aEncertat = actual.solucioRapida();   
  if (aEncertat) {
    aOptima = actual;
    aDesviacioOptima = actual.obtDesviacioMitjana();
    aTornsOptima = aOptima.obtTorns();
  }
}

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
        aOptima = actual;
        aDesviacioOptima = actual.obtDesviacioMitjana();
        aTornsOptima = actual.obtTorns();
      }
    }
    iCand++;
  }
}

void Solucionador::trobarMillor(Solucio &actual) {
  Candidats iCand = actual.inicialitzarCandidats();
  while (!iCand.esFi()) {
    if (actual.acceptable(iCand) && actual.completable() && actual.esMillorable(aTornsOptima)) {
      actual.anotar(iCand);
      if (!actual.completa()) {
        trobarMillor(actual);
      } else {
        if (actual.esMillor(aTornsOptima, aDesviacioOptima)) {
          aEncertat = true;
          aOptima = actual;
          aDesviacioOptima = actual.obtDesviacioMitjana();
          aTornsOptima = actual.obtTorns();
        }
      }
      actual.desanotar(iCand);
    }
    iCand++;
  }
}

void Solucionador::mostrarSolucio(double temps) const { 
  if (aEncertat) {
    cout << aOptima << endl 
      << "Num. torns: " << aTornsOptima - 1 << endl 
      << "Num. dies: " << (aTornsOptima-1)/2 << endl
      << "Desviacio: " << aDesviacioOptima << endl;
  } else {
    cout << "\n\nNo hi ha solucio per la configuracio indicada\n";
  }
  cout << "Temps: " << temps << " segons" << endl;
}
