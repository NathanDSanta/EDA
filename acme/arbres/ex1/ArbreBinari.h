#ifndef ARBRE_BINARI_CAR_H
#define ARBRE_BINARI_CAR_H
#include <iostream>
#include <memory>
using namespace std;

class ArbreBinari { // Arbre Binari
public:
  ArbreBinari();
  ArbreBinari(const char t[]);
  bool esBuit() const;
  ArbreBinari FillDret() const;
  ArbreBinari FillEsquerre() const;
  char Contingut() const;
  // no té destructor.
private:
  struct node {
    char dada;
    shared_ptr<node> fe, fd;

    node(const shared_ptr<node> &p1, const shared_ptr<node> &p2, const char &c) {
      // Pre: --; Post: constructor per inicialitzar node amb valors {c, p1, p2}
      dada = c;
      fe = p1;
      fd = p2;
    };
  };

  shared_ptr<node> arrel;

  shared_ptr<ArbreBinari::node> iArbreBinari(const char t[], int &i); // mètode auxiliar del constructor

  ArbreBinari(const shared_ptr<ArbreBinari::node> &p);
  // Pre: --; Post: objecte creat a partir de p;
};

#endif
