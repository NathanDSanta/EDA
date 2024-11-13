#include "Any.h"

#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "Districte.h"

using namespace std;

Any::Any(int any) {
  a_any = any;
  a_districtes.assign(7, Districte());
}

const string Any::DISTRICTES[7] = {"-", "Carme, Vila-roja", "Eixample, Montilivi", "Santa Eugenia, Mas Xirgu", "Casc Antic", "Montjuic, Pont major", "Sant Ponc, Domeny, Taiala"};

void Any::afegir(int any, int districte, int seccio, int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat) {
  if (a_any != any)
    a_any = any;

  a_districtes[districte].afegir(any, seccio, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
}

vector<long> Any::obtenirNumHabitants() const {
  vector<long> habitantsPerDistricte;
  habitantsPerDistricte.reserve(7);

  for (int i = 1; i < N_DISTRICTES + 1; i++)
    habitantsPerDistricte[i] = a_districtes[i].obtenirNumHabitants();

  return habitantsPerDistricte;
}

set<Estudi> Any::resumEstudis(int districte) const {
  set<Estudi> res;

  if (districte == 0) {
    for (vector<Districte>::const_iterator i = a_districtes.begin(); i != a_districtes.end(); i++)
      res.merge(i->resumEstudis());
  } else {
    res = a_districtes[districte].resumEstudis();
  }

  return res;
}

list<string> Any::estudisEdatNacio(int districte, int edat, int codiNacionalitat) const {
  return a_districtes[districte].estudisEdatNacio(a_any, edat, codiNacionalitat);
}

map<double, string> Any::obtenirEdatsMitjanes() const {
  map<double, string> aux;
  for (int i = 1; i < N_DISTRICTES + 1; i++) {
    aux.emplace(a_districtes[i].obtenirEdatMitjana(), DISTRICTES[i]);
  }
  return aux;
}
