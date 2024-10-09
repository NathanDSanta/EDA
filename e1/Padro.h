// Darius Natan Santa
// u1994947
// Exercici 1
#ifndef PADRO_H
#define PADRO_H
#include "Districte.h"

using namespace std;

class Padro {
public:
  Padro();
  int afegir(int any, int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
  vector<long> obtenirNumHabitantsPerDistricte() const;
  vector<pair<string, double>> resumEdat() const;
  list<string> resumEstudis() const;
  vector<pair<string, long>> edatNacioPerDistricte(int edat, int codiNacionalitat) const;
  pair<list<string>, list<string>> diferentsNacionalitats(int districte1, int districte2) const;

private:
  const string DISTRICTES[7] = {"-", "Carme, Vila-roja", "Eixample, Montilivi", "Santa Eugenia, Mas Xirgu", "Casc Antic", "Montjuic, Pont major", "Sant Ponc, Domeny, Taiala"};

  vector<Districte> a_districtes;
};

#endif // PADRO_H
