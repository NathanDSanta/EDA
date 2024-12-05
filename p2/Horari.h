#ifndef HORARI_H
#define HORARI_H
#include <string>
#include <vector>
#include "Assignatura.h"
using namespace std;

class Horari {
public:
  Horari();
  void llegirDades(string fitxer);
  void generarIMostrarHorari(int cr, int gc, int s, int algoritme) const;

private:
  vector<Assignatura> aAssignatures;
};

#endif // !HORARI_H
