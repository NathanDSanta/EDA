// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef NACIONALITAT_H
#define NACIONALITAT_H
#include <iostream>
using namespace std;

class Nacionalitat {
public:
  Nacionalitat(int id = 0, string nom = "");
  int obtenirId() const;
  string obtenirNom() const;
  bool operator==(const Nacionalitat &nacio) const;

private:
  int a_id;
  string a_nom;
};

#endif // NACIONALITAT_H
