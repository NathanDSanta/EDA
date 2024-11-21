#ifndef HORARI_H
#define HORARI_H

#include <list>
#include <map>
#include <string>
#include <vector>

#include "Assignatura.h"
using namespace std;

class Horari {
 public:
  Horari(string path = "");

  void repartirExamens();

 private:
  const int N_AULES_G = 2;
  const int N_AULES_R = 3;
  const int N_AULES_TOTALS = 5;

  list<Assignatura> a_assignatures;
  list<string> a_grau;

  static int stringToInt(string s);
  list<Assignatura>::iterator seleccionarPrometedor(list<Assignatura> &l);
  bool solucioCompletable(const list<Assignatura> &a, const Assignatura& prometedor) const;


  void mostrar_solucio(const vector<list<Assignatura>>& s) const ;
};

#endif  // !HORARI_H
