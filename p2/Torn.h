#ifndef TORN_H
#define TORN_H
#include <list>
#include <ostream>
#include <set>
#include <string>
using namespace std;

class Torn {
public:
  Torn();
  bool ple() const;
  bool buit() const;
  bool gcCompletes(int aGcMax) const;
  bool existeixGrauCurs(string codiGrauCurs) const;
  bool existeixAlgunaAssignatura(set<string> assignatures) const;

  list<string> obtExamens() const;

  void anotar(string codiGrauCurs, string assignatura);
  void desanotar(string CodiGrauCurs, string assignatura);

  friend ostream& operator<<(ostream& o, const Torn& t);

private:
  list<string> aExamens;
  set<string> grauCursos;
  int aGcUsades, aCrUsades;
};

#endif // !TORN_H
