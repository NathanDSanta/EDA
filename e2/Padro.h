#ifndef PADRO_H
#define PADRO_H

#include "Districte.h"
#include "ResumEdats.h"
#include "ResumEstudis.h"
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Padro {
public:
  Padro();
  int llegirDades(const string &path);
  bool existeixAny(int any) const;
  vector<long> obtenirNumHabitantsPerDistricte(int any) const;
  map<int, int> nombreEstudisDistricte(int districte) const;
  list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;
  ResumEstudis resumEstudis() const;
  ResumEdats resumEdat() const;

private:
  map<int, vector<Districte>> a_districtes;

  static const int NUM_DISTRICTES = 6;
  static const string DISTRICTES[7];

  int stringToInt(string s) const;
};

#endif // PADRO_H
