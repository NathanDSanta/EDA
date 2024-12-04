#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Graf.h"

Graf::Graf() {
  nVers = nArs = 0;
  dirigit = false;
  vertexs.resize(nVers + 1); // casella 0 no ocupada
}

Graf::Graf(int nVertexs, bool dirigit) {
  nVers = nVertexs;
  nArs = 0;
  this->dirigit = dirigit;
  vertexs.resize(nVers + 1); // casella 0 no ocupada
}

Graf::Graf(char nom_fitxer[], bool dirigit) {
  ifstream f(nom_fitxer);
  string linia;

  nVers = 0;
  nArs = 0;
  this->dirigit = dirigit;

  if (f.is_open()) {
    getline(f, linia);
    while (linia != "#") {
      nVers++;
      getline(f, linia);
    }
    vertexs.resize(nVers + 1);

    int v1, v2;
    f >> v1 >> v2;
    while (not f.eof()) {
      vertexs[v1].push_back(v2); // no es valida
      if (not dirigit)
        vertexs[v2].push_back(v1);
      nArs++;
      f >> v1 >> v2;
    }
    f.close();
  }
}

int Graf::nVertexs() const { return nVers; }

int Graf::nArestes() const { return nArs; }

bool Graf::esDirigit() const { return dirigit; }

void Graf::ordreAssignatures() const {
  if (not dirigit)
    cout << "Nomes per grafs dirigits" << endl;
  else {
    vector<int> res; // per guardar la sortida
    vector<bool> visitat(nVers + 1, false);
    vector<list<int>> requisits(nVers + 1, list<int>());
    for (int i = 1; i <= nVers; i++) {
      for (list<int>::const_iterator j = vertexs[i].begin(); j != vertexs[i].end(); j++) {
        requisits[*j].push_back(i);  
      } 
    }

    while (res.size() < nVers) {
      int x = seleccionarPrometedor(requisits, visitat);
      visitat[x] = true;
      res.push_back(x);
      eliminarRequisit(requisits, x);
    }

    cout << res[0];
    for (int i = 1; i < nVers; i++)
      cout << ", " << res[i];
    cout << endl;
  }
}

int Graf::seleccionarPrometedor(const vector<list<int>> &requisits, const vector<bool> &visitats) const {
  int res = 0;
  for (int i = 1; i <= nVers; i++) {
    if (!visitats[i]){
      if (res == 0)
        res = i;
      if(requisits[i].empty() && vertexs[i].size() > vertexs[res].size())
        res = i;
    }
  }
  return res;
}

void Graf::eliminarRequisit(vector<list<int>> &requisits, int x) const {
  for (int i = 1; i <= nVers; i++) {
    if (!requisits[i].empty()) {
      bool erase = false;
      list<int>::iterator j = requisits[i].begin(); 
      while (!erase && j != requisits[i].end()) {
        if (*j == x) erase = true;
        else j++;
      }
      if (erase) 
        requisits[i].erase(j);
    }
  }
}
