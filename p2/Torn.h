#ifndef TORN_H
#define TORN_H
#include <list>
#include <ostream>
#include <set>
#include <string>
using namespace std;

class Torn {
public:
  Torn(int gc = 1, int cr = 1);
  bool ple() const;
  bool buit() const;
  bool gcCompletes(int aGcMax) const;
  bool existeixGrauCurs(string codiGrauCurs) const;
  bool existeixAlgunaAssignatura(set<string> assignatures) const;

  list<string> obtExamens() const;
  set<string> obtGrauCursos() const;

  void anotar(string codiGrauCurs, string assignatura, bool esGran);
  void desanotar(string CodiGrauCurs, string assignatura, bool esGran);

  friend ostream& operator<<(ostream& o, const Torn& t);

private:
  list<string> aExamens;
  set<string> aGrauCursos;
  int aGcUsades, aCrUsades;
  int aGcMax, aCrMax;
};

#endif // !TORN_H
