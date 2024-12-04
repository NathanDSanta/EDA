#ifndef TORN_H
#define TORN_H

#include "Assignatura.h"
#include <list>
#include <ostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Torn {
public:
  Torn();
  bool existeixCurs(string curs) const;
  bool pleGrans(int gc) const;
  bool ple(int totals) const;
  bool buit() const;
  list<int> obtenirExamens() const;
  void inserir(const vector<Assignatura> &assignatura, int candidat);
  void eliminar(const vector<Assignatura> &assignatura);
  
  friend ostream& operator<<(ostream& o, const Torn& t);

private:
  list<int> aExamens;
  set<string> aCursExisteix;
  int aGcUsades, aCrUsades;

};
#endif // !TORN_H
