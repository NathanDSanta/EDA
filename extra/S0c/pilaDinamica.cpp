#include "pilaDinamica.h"
#include <cstddef>

pilaDinamica::pilaDinamica() {
  // Pre: --;
  // Post: objecte creat;
  inici = NULL;
}
void pilaDinamica::allibera() {
  // Pre: --;
  // Post: memòria alliberada
  while (inici != NULL) {
    node *p = inici;
    inici = inici->seguent;
    delete p;
  }
}

pilaDinamica::~pilaDinamica() {
  // Pre: --;
  // Post: objecte destruit;
  allibera();
}

void pilaDinamica::Empila(element e) {
  // Pre: --;
  // Post: element e empilat
  node *p = new node{e, inici};
  inici = p;
}

void pilaDinamica::Desempila() {
  // Pre: --;
  // Post: element desempilat;
  if (inici != NULL) {
    node *p = inici;
    inici = inici->seguent;
    delete p;
  }
}

element pilaDinamica::Cim() const {
  // Pre: --;
  // Post: retorna el cim de la pila
  return inici->dada;
}

bool pilaDinamica::Buida() const {
  // Pre: --;
  // Post: retorna true si la pila és buida
  return inici == NULL;
}