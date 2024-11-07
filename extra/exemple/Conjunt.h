#ifndef CONJUNT_H
#define CONJUNT_H

const int MAX_DADES = 1000;

template <class element> // linies separades per fer-ho més entenedor
class Conjunt {          // definicio d'un conjunt d'elements
public:
  Conjunt();
  void Afegir(const element &x);
  void Treure(const element &x);
  bool Existeix(const element &x) const;
  bool esBuit() const;

private:
  int cercar(const element &x) const;

  // inv: 0≤nDades≤MAX_DADES ^ no hi ha repetits dades[1]..dades[nDades]
  element dades[MAX_DADES + 1];
  int nDades;
};

#endif // CONJUNT_H
