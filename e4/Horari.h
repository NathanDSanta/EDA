#ifndef HORARI_H
#define HORARI_H

#include <list>
#include <string>

#include "Assignatura.h"
using namespace std;

class Horari {
 public:
  friend ostream &operator<<(ostream &o, const Horari &h);

  Horari(string path = "");

 private:
  const int N_AULES_G = 2;
  const int N_AULES_R = 3;

  list<Assignatura> a_assignatures;

  static int stringToInt(string s);
};

#endif  // !HORARI_H
