#include "Padro.h"
#include "Districte.h"
#include "Estudi.h"
#include "eines.h"
#include <fstream>
#include <ios>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

const string Padro::DISTRICTES[7] = {"-", "Carme, Vila-roja", "Eixample, Montilivi", "Santa Eugenia, Mas Xirgu", "Casc Antic", "Montjuic, Pont major", "Sant Ponc, Domeny, Taiala"};

Padro::Padro() {}

int Padro::llegirDades(const string &path) {
  // Pre: path = ruta de l'arxiu csv; Post: padro amb les dades llegides;
  ifstream fin;
  fin.open(path.c_str());

  if (fin.fail()) {
    fin.close();
    fin.clear();
    return 0;
  }

  int linies = 0;
  string linia;
  vector<string> items;
  fin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(fin, linia);
  while (!fin.eof()) {
    items = tokens(linia, ',', true);
    int any = stringToInt(items[0]);
    int districte = stringToInt(items[1]);
    int seccio = stringToInt(items[2]);
    int codiNivellEstudis = stringToInt(items[4]);
    string nivellEstudis = items[5];
    int anyNaixement = stringToInt(items[6]);
    int codiNacionalitat = stringToInt(items[11]);
    string nomNacionalitat = items[12];

    if (any != -1 && districte != -1 && seccio != -1 && codiNivellEstudis != -1 && anyNaixement != -1 && codiNacionalitat != -1) {
      map<int, vector<Districte>>::iterator pos = a_districtes.find(any);
      if (pos == a_districtes.end()) {
        vector<Districte> aux;
        aux.assign(7, Districte());
        pos = a_districtes.emplace(any, aux).first;
      }
      pos->second[districte].afegir(any, seccio, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
      linies++;
    }
    getline(fin, linia);
  }
  fin.close();
  return linies;
}

bool Padro::existeixAny(int any) const {
  // Pre: cert; Post: retorna si existeix any al Padro
  bool existeix = false;
  if (a_districtes.find(any) != a_districtes.end())
    existeix = true;
  return existeix;
}

vector<long> Padro::obtenirNumHabitantsPerDistricte(int any) const {
  // Pre: cert; Post: retorna un vector amb el numero d'habitants per districte
  vector<long> habitantsPerDistricte;
  habitantsPerDistricte.reserve(7);
  map<int, vector<Districte>>::const_iterator pos = a_districtes.find(any);
  for (int i = 1; i < NUM_DISTRICTES + 1; i++) {
    habitantsPerDistricte[i] = pos->second[i].obtenirNumHabitants();
  }
  return habitantsPerDistricte;
}

map<int, int> Padro::nombreEstudisDistricte(int districte) const {
  // Pre: 1 <= districte <= 6; Post: retorna un map el districte amb el nombre d'estudis
  map<int, int> aux;
  for (map<int, vector<Districte>>::const_iterator i = a_districtes.begin(); i != a_districtes.end(); i++) {
    aux.emplace(i->first, i->second[districte].resumEstudis().size());
  }
  return aux;
}

list<string> Padro::estudisEdat(int any, int districte, int edat, int codiNacionalitat) const {
  // Pre: 1 <= districte <= 6; Post: retorna els diferents estudis dels habitats amb els parametres indicats;
  map<int, vector<Districte>>::const_iterator pos = a_districtes.find(any);
  list<string> aux = list<string>(pos->second[districte].estudisEdatNacio(edat, codiNacionalitat));
  return aux;
}

ResumEstudis Padro::resumEstudis() const {
  // Pre: cert; Post: retorna un Resum que conte, tots els nivells d'estudis
  ResumEstudis res;

  for (map<int, vector<Districte>>::const_iterator i = a_districtes.begin(); i != a_districtes.end(); i++) {
    set<Estudi> total;
    for (vector<Districte>::const_iterator ii = i->second.begin(); ii != i->second.end(); ii++) {
      total.merge(ii->resumEstudis());
    }
    res.emplace(i->first, total);
  }
  return res;
}

ResumEdats Padro::resumEdat() const {
  // Pre: cert; Post: retorna per cada any, tots els districtes amb la seva edat promig
  ResumEdats res;
  for (map<int, vector<Districte>>::const_iterator i = a_districtes.begin(); i != a_districtes.end(); i++) {
    map<double, string> total;
    for (int ii = 1; ii < NUM_DISTRICTES + 1; ii++) {
      total.emplace(i->second[ii].obtenirEdatMitjana(), DISTRICTES[ii]);
    }
    res.emplace(i->first, total);
  }
  return res;
}

int Padro::stringToInt(string s) const {
  if (s.length() == 0)
    return -1;
  for (char c : s) {
    if (c < '0' || c > '9')
      return -1;
  }
  return stoi(s);
}
