#ifndef TORN_H
#define TORN_H
#include <list>
#include <ostream>
using namespace std;

class Torn {
public:
  Torn();
  bool ple();
  bool buit();
  void inserir();
  void eliminar();
  list<int> obtenirExamens() const;

  friend ostream& operator<<(ostream& o, const Torn& t);

private:
  list<int> aExamens;
  int aGcUsades, aCrUsades;
};

#endif // !TORN_H
