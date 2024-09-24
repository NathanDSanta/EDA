#include <iostream>
using namespace std;

template <class elem> class Llista {

private:
  struct node {
    elem dada;
    node *seg;
  };
  node *a_inici;

public:
  Llista();
  ~Llista();
};

template <class elem> Llista<elem>::Llista() { a_inici = NULL; }

template <class elem> Llista<elem>::~Llista() {
  while (a_inici != NULL) {
    node *aux = a_inici;
    a_inici = a_inici->seg;
    delete aux;
  }
}
int main() {
  Llista<int> llista;
  return 0;
}