#ifndef HORARI_H
#define HORARI_H

#include "Assignatura.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Horari {
public:
  Horari() {};
  void llegirDades(string fitxer);
  void generarIMostrarHorari(int cr, int gc, int s, bool m) const;

private:
  vector<Assignatura> aAssignatures; 
};

#endif // !HORARI_H
