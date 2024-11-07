// Jerónimo Hernández González
// Exercici 3 - Laboratoris EDA 24/25

#include "GrafEtiquetat.h"
#include <list>
#include <map>
#include <ostream>

GrafEtiquetat::GrafEtiquetat(bool dirigit) : _dirigit(dirigit) { _numArestes = 0; }

bool GrafEtiquetat::esDirigit() const { return _dirigit; }

int GrafEtiquetat::nVertexs() const { return _representacio.size(); }

int GrafEtiquetat::nArestes() const { return _numArestes; }

bool GrafEtiquetat::existeixAresta(int v1, int v2) const {
  bool existeix = false;

  if (esValid(v1) and esValid(v2)) {
    v1--;
    v2--;
    existeix = _representacio[v1].find(v2)->first;
  }

  return existeix;
}

Etiqueta GrafEtiquetat::etiquetaAresta(int v1, int v2) {
  Etiqueta e;

  if (existeixAresta(v1, v2)) {
    v1--;
    v2--;
    e = _representacio[v1].find(v2)->second;
  } else
    throw "GrafEtiquetat::etiquetaAresta: L'aresta que es vol consultar no existeix";

  return e;
}

int GrafEtiquetat::afegirVertex(const Districte &districte) {
  _vertexs.push_back(districte);
  _representacio.push_back(map<int, Etiqueta>());
  return _vertexs.size() - 1;
}

void GrafEtiquetat::afegirAresta(int v1, int v2, const Etiqueta &e) {
  if (esValid(v1) and esValid(v2)) {
    v1--;
    v2--;
    _representacio[v1].insert(pair<int, Etiqueta>(v2, e));
    _numArestes++;

    if (not _dirigit) {
      _representacio[v2].insert(pair<int, Etiqueta>(v1, e));
      _numArestes++;
    }
  } else
    throw "GrafEtiquetat::afegirAresta: Algun dels vèrtexs no és vàlid";
}

void GrafEtiquetat::esborrarAresta(int v1, int v2) {
  if (existeixAresta(v1, v2)) {
    v1--;
    v2--;
    _representacio[v1].erase(v2);
    _numArestes--;

    if (not _dirigit) {
      _representacio[v2].erase(v1);
      _numArestes--;
    }
  } else
    throw "GrafEtiquetat::esborrarAresta: L'aresta que es vol esborrar no existeix";
}

void GrafEtiquetat::esborrarVertex(int v) {
  if (esValid(v)) {
    v--;
    Vertexs::iterator pos = _vertexs.begin() + v;
    _vertexs.erase(pos);
  } else
    throw "GrafEtiquetat::esborrarVertex: El vèrtex no existeix";
}

bool GrafEtiquetat::esValid(int v) const { return v >= 1 and v <= _representacio.size(); }

ostream &operator<<(ostream &os, const GrafEtiquetat &g) {
  os << "Vèrtexs:" << endl;

  for (int i = 0; i < g.nVertexs(); i++)
    os << i + 1 << ", " << g._vertexs[i].obtenirNom() << ": color " << g._vertexs[i].obtenirColor() << endl;

  os << endl << "Arestes:" << endl;

  for (int i = 0; i < g.nVertexs(); i++) {
    for (map<int, Etiqueta>::const_iterator j = g._representacio[i].begin(); j != g._representacio[i].end(); j++)
      os << i + 1 << "-" << j->first + 1 << ": " << j->second << endl;
  }

  return os;
}

int GrafEtiquetat::coloreja() { throw "GrafEtiquetat::coloreja: No implementat"; }
