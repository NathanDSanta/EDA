#include "Candidats.h"

Candidats::Candidats(int inici, int final) {
  aICand = inici;
  aMax = final;
}

void Candidats::operator++(int) {
  if (end())
    throw "It's the end";
  aICand++;
}

int Candidats::actual() const { return aICand; }

bool Candidats::end() const { return aICand >= aMax; }
