#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H

#include <ostream>
#include <set>
#include <string>
using namespace std;

class Assignatura {
public:

  Assignatura(string codi = "", string nom = "", string grau = "", bool esTipusGran = false, double credits = 0, int semestre = 0, int curs = 0);

  bool obtEsGran() const;
  string obtCodi() const;
  string obtCurs() const;
  string obtGrau() const;

  bool operator==(const Assignatura &a) const;
  bool operator<(const Assignatura &a) const;
  friend ostream& operator<<(ostream& o, const Assignatura& a);

private:
  string aGrau;
  string aNom;
  string aCodi; 
  bool aEsTipusGran;
  double aCredits;
  int aSemestre;
  int aCurs;
};

#endif // !ASSIGNATURA_H
