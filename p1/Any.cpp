#include "Any.h"

#include <algorithm>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "Districte.h"
#include "Nacionalitat.h"

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

map<double, string> Any::obtenirEdatsMitjanes() const {
  map<double, string> aux;
  for (int i = 1; i < N_DISTRICTES + 1; i++) {
    aux.emplace(a_districtes[i].obtenirEdatMitjana(), DISTRICTES[i]);
  }
  return aux;
}

long Any::obtenirNumHabitants() const {
  long habitants = 0;
  vector<long> habitantsPerDistricte = obtenirNumHabitantsPerDistricte();
  for (int i = 1; i <= N_DISTRICTES; i++) {
    habitants += habitantsPerDistricte[i];
  }
  return habitants;
}

vector<long> Any::obtenirNumHabitantsPerDistricte() const {
  vector<long> habitantsPerDistricte;
  habitantsPerDistricte.reserve(7);

  for (int i = 1; i < N_DISTRICTES + 1; i++)
    habitantsPerDistricte[i] = a_districtes[i].obtenirNumHabitants();

  return habitantsPerDistricte;
}

map<int, long> Any::obtenirNumHabitantsPerSeccio(int districte) const { return a_districtes[districte].obtenirNumHabitantsPerSeccio(); }

map<int, pair<double, int>> Any::resumNivellEstudis() const {
  map<int, pair<double, int>> resultat;
  double max = 0;
  int districte_max = 0;
  double min = numeric_limits<double>::max();
  int districte_min = 0;
  for (int i = 1; i <= N_DISTRICTES; i++) {
    double promig = a_districtes[i].obtenirPromigNivellEstudis();
    resultat.emplace(i, make_pair(promig, 0));
    if (promig > max) {
      max = promig;
      districte_max = i;
    } else if (promig < min) {
      min = promig;
      districte_min = i;
    }
  }
  resultat[districte_max].second = 1;
  resultat[districte_min].second = -1;
  return resultat;
}

map<long, string> Any::resumNacionalitats() const {
  map<string, long> habitantsNacionalitat;
  for (int i = 1; i <= N_DISTRICTES; i++) {
    set<Nacionalitat> nacionalitats = a_districtes[i].resumNacionalitats();
    for (set<Nacionalitat>::const_iterator j = nacionalitats.begin(); j != nacionalitats.end(); j++) {
      map<string, long>::iterator pos = habitantsNacionalitat.find(j->obtenirNom());
      if (pos != habitantsNacionalitat.end()) {
        pos->second += a_districtes[i].obtenirNumHabitantsNacio(j->obtenirId());
      } else {
        habitantsNacionalitat.emplace(j->obtenirNom() + " (" + to_string(j->obtenirId()) + ")", a_districtes[i].obtenirNumHabitantsNacio(j->obtenirId()));
      }
    }
  }

  map<long, string> resultat;
  for (map<string, long>::const_iterator i = habitantsNacionalitat.begin(); i != habitantsNacionalitat.end(); i++) {
    resultat.emplace(i->second, i->first);
  }
  return resultat;
}

string Any::movimentsComunitat(int codiNacionalitat) const {
  int max = 1;
  long v_max = a_districtes[1].obtenirNumHabitantsNacio(codiNacionalitat);
  for (int i = 2; i <= N_DISTRICTES; i++) {
    long new_max = a_districtes[i].obtenirNumHabitantsNacio(codiNacionalitat);
    if (new_max >= v_max) {
      max = i;
      v_max = new_max;
    }
  }
  return v_max == 0 ? "No té habitants" : DISTRICTES[max];
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

string Any::movimentVells() const {
  int max = 1;
  long v_max = a_districtes[1].obtenirNumHabitantsEdatEntre(a_any, 31, numeric_limits<int>::max());
  for (int i = 2; i <= N_DISTRICTES; i++) {
    long new_max = a_districtes[i].obtenirNumHabitantsEdatEntre(a_any, 31, numeric_limits<int>::max());
    if (new_max > v_max) {
      max = i;
      v_max = new_max;
    }
  }
  return DISTRICTES[max];
}

vector<long> Any::poblacioJovesDistricte() const {
  vector<long> resultat(7, 0);
  for (int i = 1; i <= N_DISTRICTES; i++) {
    resultat[i] = a_districtes[i].obtenirNumHabitantsEdatEntre(a_any, 20, 30);
  }
  return resultat;
}

list<string> Any::estudisEdatNacio(int districte, int edat, int codiNacionalitat) const { return a_districtes[districte].estudisEdatNacio(a_any, edat, codiNacionalitat); }
