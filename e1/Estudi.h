// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef ESTUDI_H
#define ESTUDI_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <vector>
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
