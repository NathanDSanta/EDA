#ifndef HORARI_H
#define HORARI_H
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "Assignatura.h"
using namespace std;

class Horari {
public:
  Horari(int gc = 1, int cr = 1, int s = 1, int d = numeric_limits<int>::max());
  void llegirAssignatures(string fitxer);
  void generarIMostrarHorari(string algoritme = "PRIMER");

  friend ostream& operator<<(ostream& o, const Horari& h);

private:
  set<Assignatura> aAssignatures;
  map<string,set<string>> aRestriccions;
  vector<string> aAssignaturesOrdenades;
  int aGranCapacitat, aCapacitatReduida, aSemestre, aDiesMaxims;
};

#endif // !HORARI_H
