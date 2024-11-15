#ifndef PADRO_H
#define PADRO_H

#include <list>
#include <map>
#include <string>
#include <vector>

#include "Any.h"
#include "ResumEdats.h"
#include "ResumEstudis.h"
#include "ResumNacionalitats.h"
#include "ResumNivellEstudis.h"

using namespace std;

class Padro {
public:
  Padro() {}

  int llegirDades(const string &path);
  bool existeixAny(int any) const;
  map<int, long> obtenirNumHabitantsPerAny() const;
  vector<long> obtenirNumHabitantsPerDistricte(int any) const;
  map<int, long> obtenirNumHabitantsPerSeccio(int any, int districte) const;
  ResumEstudis resumEstudis() const;
  map<int, int> nombreEstudisDistricte(int districte) const;
  ResumNivellEstudis resumNivellEstudis() const;
  ResumNacionalitats resumNacionalitats() const;
  map<int, string> movimentsComunitat(int codiNacionalitat) const;
  ResumEdats resumEdat() const;
  map<int, string> movimentVells() const;
  pair<string, long> mesJoves(int anyInicial, int anyFinal) const;
  list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;

private:
  map<int, Any> a_anys;

  int stringToInt(string s) const;

  static bool validarDades(int any, int districte, int seccio, int codiNivellsEstudis, int anyNaixement, int codiNacionalitat);
};

#endif // PADRO_H
