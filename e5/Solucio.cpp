#include "Solucio.h"
#include "Candidats.h"
#include "Torn.h"
#include <vector>

Solucio::Solucio(const vector<Assignatura> &assignatures, int cr, int gc, int s) {
  aDades = assignatures;
  aAssignaturaAgafada.resize(aDades.size(), false);
  aSolParcial.resize(1, Torn());
  aNTorns = 0;
  aNiv = 1;
  aCapacitatReduida = cr;
  aGranCapacitat = gc;
  aSemestre = s;
}

bool Solucio::acceptable(const Candidats &iCand) const {
  bool acceptable = true;
  int candidat = iCand.actual();
  Assignatura assig = aDades[candidat];
  acceptable = !(assig.obtEsGran() && aSolParcial[aNTorns].pleGrans(aGranCapacitat)
                 // aSolParcial[aNTorns].existeixCurs(assig.obtenirGrau())
  );
  return acceptable;
}

bool Solucio::esMillor(int nTornsOptim) const { return aNTorns < nTornsOptim; }

bool Solucio::completa() const { return aDades.empty(); }

int Solucio::obtTorns() const { return aNTorns; }

void Solucio::anotar(const Candidats &iCand) {
  aSolParcial[aNTorns].inserir(aDades, iCand.actual());
  if (aSolParcial[aNTorns].ple(aCapacitatReduida + aGranCapacitat))
    aNTorns++;
  aNiv++;
}

void Solucio::desanotar(const Candidats &iCand) {
  aSolParcial[aNTorns].eliminar(aDades);
  if (aSolParcial[aNTorns].buit())
    aNTorns--;
  aNiv--;
}

Candidats Solucio::inicialitzarCandidats() { return Candidats(0, aDades.size()); }

ostream &operator<<(ostream &o, const Solucio &s) {
  for (int i = 1; i < s.aSolParcial.size(); i++) {
    o << s.aSolParcial[i] << endl;
  }
  return o;
}
