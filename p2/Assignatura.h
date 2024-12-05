#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H

#include <ostream>
#include <string>
using namespace std;

class Assignatura {
public:
  friend ostream& operator<<(ostream& o, const Assignatura& a);

  Assignatura(string grau = "", string nom = "", string codi = "", bool esTipusGran = false, double credits = 0, int semestre = 0, int curs = 0);
  bool operator==(const Assignatura &a) const;
  bool operator<(const Assignatura &a) const;

  bool obtEsGran() const;
  string obtenirGrau() const;

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
