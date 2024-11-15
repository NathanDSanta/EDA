#ifndef ANY_H
#define ANY_H

#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "Districte.h"
using namespace std;
class Any {
public:
  Any(int any = 0);

  void afegir(int any, int districte, int seccio, int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat);
  map<double, string> obtenirEdatsMitjanes() const;
  long obtenirNumHabitants() const;
  vector<long> obtenirNumHabitantsPerDistricte() const;
  map<int, long> obtenirNumHabitantsPerSeccio(int districte) const;
  map<int, pair<double, int>> resumNivellEstudis() const;
  map<long, string> resumNacionalitats() const;
  string movimentsComunitat(int codiNacionalitat) const;
  set<Estudi> resumEstudis(int districte = 0) const;
  string movimentVells() const;
  vector<long> poblacioJovesDistricte() const;
  list<string> estudisEdatNacio(int districte, int edat, int codiNacionlitat) const;

  static const int N_DISTRICTES = 6;
  static const string DISTRICTES[N_DISTRICTES + 1];

private:
  int a_any;
  vector<Districte> a_districtes;
};

#endif // !ANY_H
