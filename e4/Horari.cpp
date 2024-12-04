#include "Horari.h"

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <ostream>
#include <string>
#include <vector>

#include "Assignatura.h"
#include "eines.h"
using namespace std;

Horari::Horari(string path) {
  if (path.length() != 0) {
    ifstream fin(path);

    if (fin.fail()) {
      throw "Invalid Path";
    }

    string linia;
    getline(fin, linia);

    while (!fin.eof()) {
      getline(fin, linia);
      vector<string> elements = tokens(linia, '\t');
      if (elements.size() > 0) {
        Assignatura afegir(elements[0], elements[1], elements[2], elements[3] == "g", stod(elements[4]), stringToInt(elements[5]), stringToInt(elements[6]));
        a_assignatures.push_back(afegir);
        a_grau.push_back(elements[0]);
      }
    }
  }
}

int Horari::stringToInt(string s) {
  if (s.length() == 0)
    return -1;

  for (char c : s) {
    if (c < '0' || c > '9')
      return -1;
  }

  return stoi(s);
}

void Horari::repartirExamens() {
  vector<list<Assignatura>> solucio;
  bool hiHaSolucio = true;
  while (!a_assignatures.empty() && hiHaSolucio) {
    list<Assignatura> entrada = a_assignatures;
    list<Assignatura> solucio_torn;
    while (solucio_torn.size() < N_AULES_TOTALS && !entrada.empty()) {
      list<Assignatura>::iterator prometedor = seleccionarPrometedor(entrada);
      entrada.erase(prometedor);
      if (solucioCompletable(solucio_torn, *prometedor))
        solucio_torn.push_back(*prometedor);
    }
    if (solucio_torn.size() == N_AULES_TOTALS) {
      for (list<Assignatura>::const_iterator i = solucio_torn.begin(); i != solucio_torn.end(); i++) {
        a_assignatures.remove(*i);
      }
    } else {
      cout << "No hi ha solucio" << endl;
      hiHaSolucio = false;
    }
    solucio.push_back(solucio_torn);
  }
  if (hiHaSolucio)
    mostrar_solucio(solucio);
}

list<Assignatura>::iterator Horari::seleccionarPrometedor(list<Assignatura> &l) {
  list<Assignatura>::iterator i = l.begin();
  bool trobat = false;
  while (i != l.end() && !trobat) {
    trobat = i->obtEsGran();
    i++;
  }
  if (!trobat) {
    i = l.begin();
  }
  return i;
}

bool Horari::solucioCompletable(const list<Assignatura> &a, const Assignatura &prometedor) const {
  bool completable = true;
  int grans = 0;
  int totals = 1;
  list<Assignatura>::const_iterator i = a.begin();
  if (prometedor.obtEsGran())
    grans++;
  while (completable && i != a.end()) {
    if (i->obtEsGran())
      grans++;
    totals++;
    if (grans > 2 || totals > 5)
      completable = false;
    else
      i++;
  }

  return completable;
}

void Horari::mostrar_solucio(const vector<list<Assignatura>> &s) const {
  for (int i = 0; i < s.size(); i++) {
    cout << "Torn: " << i + 1 << endl;
    for (list<Assignatura>::const_iterator j = s[i].begin(); j != s[i].end(); j++) {
      cout << "\t" << *j;
    }
  }
}
