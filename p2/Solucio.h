#ifndef SOLUCIO_H
#define SOLUCIO_H

#include "Assignatura.h"
#include <ostream>
#include <vector>
using namespace std;

class Solucio {
public:
  Solucio();

  friend ostream& operator<<(ostream& o, const Solucio& s);

private:
  vector<Assignatura> dades;
  
};

#endif // !SOLUCIO_H
