#include "Padro.h"

#include <fstream>
#include <ios>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "Any.h"
#include "ResumNacionalitats.h"
#include "ResumNivellEstudis.h"
#include "eines.h"

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

    if (validarDades(any, districte, seccio, codiNivellEstudis, anyNaixement, codiNacionalitat)) {
      map<int, Any>::iterator pos = a_anys.find(any);

      if (pos == a_anys.end())
        pos = a_anys.insert(pair<int, Any>(any, Any(any))).first;

      pos->second.afegir(any, districte, seccio, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
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

  if (a_anys.find(any) != a_anys.end())
    existeix = true;

  return existeix;
}

map<int, long> Padro::obtenirNumHabitantsPerAny() const {
  map<int, long> aux;

  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++) {
    aux.emplace(i->first, i->second.obtenirNumHabitants());
  }

  return aux;
}

vector<long> Padro::obtenirNumHabitantsPerDistricte(int any) const {
  // Pre: cert; Post: retorna un vector amb el numero d'habitants per districte
  vector<long> habitantsPerDistricte;
  map<int, Any>::const_iterator pos = a_anys.find(any);

  if (pos != a_anys.end())
    habitantsPerDistricte = pos->second.obtenirNumHabitantsPerDistricte();

  return habitantsPerDistricte;
}

map<int, long> Padro::obtenirNumHabitantsPerSeccio(int any, int districte) const { return a_anys.find(any)->second.obtenirNumHabitantsPerSeccio(districte); }

ResumEstudis Padro::resumEstudis() const {
  // Pre: cert; Post: retorna un Resum que conte, tots els nivells d'estudis
  ResumEstudis res;

  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++) {
    res.emplace(i->first, i->second.resumEstudis());
  }

  return res;
}

map<int, int> Padro::nombreEstudisDistricte(int districte) const {
  // Pre: 1 <= districte <= 6; Post: retorna un map el districte amb el nombre
  // d'estudis
  map<int, int> aux;

  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++)
    aux.emplace(i->first, i->second.resumEstudis(districte).size());

  return aux;
}

ResumNivellEstudis Padro::resumNivellEstudis() const {
  ResumNivellEstudis resultat;
  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++) {
    resultat.emplace(i->first, i->second.resumNivellEstudis());
  }
  return resultat;
}

ResumNacionalitats Padro::resumNacionalitats() const {
  ResumNacionalitats resultat;
  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++) {
    resultat.emplace(i->first, i->second.resumNacionalitats());
  }
  return resultat;
}

map<int, string> Padro::movimentsComunitat(int codiNacionalitat) const {
  map<int, string> resultat;
  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++) {
    resultat.emplace(i->first, i->second.movimentsComunitat(codiNacionalitat));
  }
  return resultat;
}

ResumEdats Padro::resumEdat() const {
  // Pre: cert; Post: retorna per cada any, tots els districtes amb la seva edat
  // promig
  ResumEdats res;

  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++) {
    res.emplace(i->first, i->second.obtenirEdatsMitjanes());
  }

  return res;
}

map<int, string> Padro::movimentVells() const {
  map<int, string> resultat;
  for (map<int, Any>::const_iterator i = a_anys.begin(); i != a_anys.end(); i++) {
    resultat.emplace(i->first, i->second.movimentVells());
  }
  return resultat;
}

pair<string, long> Padro::mesJoves(int anyInicial, int anyFinal) const {
  vector<long> final = a_anys.find(anyFinal)->second.poblacioJovesDistricte();
  vector<long> inici = a_anys.find(anyInicial)->second.poblacioJovesDistricte();

  int max = 1;
  long v_max = final[1] - inici[1];
  for (int i = 2; i < final.size(); i++) {
    long new_max = final[i] - inici[i];
    if (new_max > v_max) {
      max = i;
      v_max = new_max;
    }
  }

  return make_pair(Any::DISTRICTES[max], v_max);
}

list<string> Padro::estudisEdat(int any, int districte, int edat, int codiNacionalitat) const {
  // Pre: 1 <= districte <= 6; Post: retorna els diferents estudis dels habitats
  // amb els parametres indicats;
  map<int, Any>::const_iterator pos = a_anys.find(any);
  list<string> aux = pos->second.estudisEdatNacio(districte, edat, codiNacionalitat);
  return aux;
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

bool Padro::validarDades(int any, int districte, int seccio, int codiNivellEstudis, int anyNaixement, int codiNacionalitat) { return any != -1 && districte != -1 && seccio != -1 && codiNivellEstudis != -1 && anyNaixement != -1 && codiNacionalitat != -1; }
