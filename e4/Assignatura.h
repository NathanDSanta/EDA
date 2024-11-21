#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H

#include <ostream>
#include <string>
using namespace std;

class Assignatura {
public:
  friend ostream& operator<<(ostream& o, const Assignatura& a);

  Assignatura(string grau = "", string nom = "", string codi = "", bool esTipusGran = false, int credits = 0, int semestre = 0, int curs = 0);
  bool operator==(const Assignatura &a) const;

  bool obtEsGran() const;

private:
  string a_grau;
  string a_nom;
  string a_codi; 
  bool a_esTipusGran;
  int a_credits;
  int a_semestre;
  int a_curs;
};

#endif // !ASSIGNATURA_H
