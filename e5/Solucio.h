#ifndef SOLUCIO_H
#define SOLUCIO_H
#include "Assignatura.h"
#include "Candidats.h"
#include "Torn.h"
#include <vector>

class Solucio {
public:
  Solucio() {};
  Solucio(const vector<Assignatura>& assignatures, int cr, int gc, int s);
  bool acceptable(const Candidats& iCand) const;
  bool esMillor(int nTornsOptim) const;
  bool completa() const;
  int obtTorns() const;
  void anotar(const Candidats& iCand);
  void desanotar(const Candidats& iCand);
  Candidats inicialitzarCandidats();

  friend ostream& operator<<(ostream& o, const Solucio& s);

private:
  vector<Assignatura> aDades;
  vector<bool> aAssignaturaAgafada;
  vector<Torn> aSolParcial;
  int aNTorns;
  int aNiv;
  int aCapacitatReduida, aGranCapacitat, aSemestre;
};

#endif // !SOLUCIO_H
