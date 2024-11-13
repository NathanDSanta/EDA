#ifndef ANY_H
#define ANY_H

#include "Districte.h"
#include <list>
#include <set>
#include <vector>
using namespace std;
class Any {
public:
  Any(int any = 0);

  void afegir(int any, int districte, int seccio, int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat);
  vector<long> obtenirNumHabitants() const;
  set<Estudi> resumEstudis(int districte = 0) const;
  list<string> estudisEdatNacio(int districte, int edat, int codiNacionlitat) const;
  map<double, string> obtenirEdatsMitjanes() const;

private:
  static const int N_DISTRICTES = 6;
  static const string DISTRICTES[N_DISTRICTES + 1];

  int a_any;
  vector<Districte> a_districtes;
};

#endif // !ANY_H
