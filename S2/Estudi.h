#ifndef ESTUDI_H
#define ESTUDI_H
#include <iostream>
using namespace std;

class Estudi {
public:
  Estudi(int id = 0, string nom = "");
  int obtenirId() const;
  string obtenirNom() const;
  bool operator==(const Estudi &estudi) const;

private:
  int a_id;
  string a_nom;
};

#endif // ESTUDI_H
