#include "ArbreBinari.h"
#include <memory>

ArbreBinari::ArbreBinari() {
  // Pre: --; Post: objecte creat per defecte
  arrel = NULL;
}

ArbreBinari::ArbreBinari(const char t[]) {
  // Pre: t = cadena en prordre; Post: objecte creat a partir de la cadena t[]
  int i = 0;
  arrel = iArbreBinari(t, i);
}

shared_ptr<ArbreBinari::node> ArbreBinari::iArbreBinari(const char t[], int &i) {
  // Pre: --; Post: immersió del constructor ArbreBinari(const char t[])
  shared_ptr<node> aux1, aux2;
  char c = t[i];
  i++;
  if (t[i] != '(')
    aux1 = aux2 = NULL;
  else {
    i++;
    if (t[i] != ' ') {
      aux1 = iArbreBinari(t, i);
    } else
      aux1 = NULL;
    if (t[i] == ' ') {
      i++;
      aux2 = iArbreBinari(t, i);
    } else
      aux2 = NULL;
    i++;
  }
  return shared_ptr<node>(new node(aux1, aux2, c));
}

ArbreBinari::ArbreBinari(const shared_ptr<ArbreBinari::node> &p) {
  // Pre: --; Post: objecte creat a partir de p
  arrel = p;
}

bool ArbreBinari::esBuit() const {
  // Pre: --; Post: retorna si l'arbre es buit
  return arrel == NULL;
}

ArbreBinari ArbreBinari::FillDret() const {
  // Pre: --; Post: retorna el fill dret
  return ArbreBinari(arrel->fd);
}

ArbreBinari ArbreBinari::FillEsquerre() const {
  // Pre: --; Post: retorna el fill esquerre
  return ArbreBinari(arrel->fe);
}

char ArbreBinari::Contingut() const {
  // Pre: --; Post: retorna l'arrel
  return arrel->dada;
}