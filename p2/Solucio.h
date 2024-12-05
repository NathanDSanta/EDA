#ifndef SOLUCIO_H
#define SOLUCIO_H

#include <ostream>
using namespace std;

class Solucio {
public:
  Solucio();

  friend ostream& operator<<(ostream& o, const Solucio& s);

private:
  
};

#endif // !SOLUCIO_H
