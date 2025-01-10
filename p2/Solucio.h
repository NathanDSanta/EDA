#ifndef SOLUCIO_H
#define SOLUCIO_H

#include "Assignatura.h"
#include "Candidats.h"
#include "Torn.h"
#include <map>
#include <ostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solucio {
public:
  Solucio() {};
  Solucio(set<Assignatura>& assig, map<string, set<string>>& restriccions, vector<string> &assigOrd, int gc, int cr, int d);
  Candidats inicialitzarCandidats();

  bool acceptable(const Candidats& iCand) const;
  bool completa() const;
  bool completable() const; // sobrepassa el nombre de dies?
  bool esMillor(int tornsOptima, double dseviacioOptima) const;

  double obtDesviacioMitjana() const;
  int obtTorns() const;

  void anotar(const Candidats& iCand);
  void desanotar(const Candidats& iCand);

  friend ostream& operator<<(ostream& o, const Solucio& s);

private:
  set<Assignatura> aAssignatures;
  map<string, set<string>> aRestriccions;
  vector<string> aAssignaturesOrdenades;

  list<Torn> aSolucioActual;
  map<string, list<int>> aTornsGrauCurs;
  int aNiv, aTorns;
  int aGcMax, aCrMax, aDiesMax;
  
  map<string, double> obtDesviacioGrauCurs() const;
};

#endif // !SOLUCIO_H
