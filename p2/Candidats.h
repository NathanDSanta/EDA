#ifndef CANDIDATS_H
#define CANDIDATS_H
#include <limits>
#include <string>
using namespace std;

class Candidats {
public:
  Candidats(int inici = 0, int final = numeric_limits<int>::max());
  bool esFi() const;
  int actual() const;
  string seleccionarPrometedor() const;
  void eliminar();
  void operator++(int);

private:
  int aActual;
  int aMax;
};

#endif // !CANDIDATS_H
