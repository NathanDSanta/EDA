/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Joan Surrell on Wed Oct 06 2004.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 *
 * JSS - 2008
 *    cal afegir-hi els metodes a implementar
 *
 * JSS - 2022
 *    es obligatori implementar el destructor
 */

#include "estructuraDinamica.h"
#include <iostream>

using namespace std;

estructuraDinamica::estructuraDinamica() {
  // aquest constructor es dona fet i no es pot canviar
  inici = NULL;
}

estructuraDinamica::~estructuraDinamica() {
  // Pre: --;
  // Post: objecte destruit
  allibera();
}

void estructuraDinamica::allibera() {
  // Pre: --;
  // Post: memòria alliberada
  node *p = inici->seguent;
  while (p != inici) {
    node *aux = p;
    p = p->seguent;
    delete aux;
  }
  delete p;
  inici = NULL;
}

void estructuraDinamica::AfegirFinal(int i) {
  // Pre: --;
  // Post: element afegit al final
  node *p = inici;
  if (p == NULL) {
    inici = new node{i, NULL};
    inici->seguent = inici;
  } else {
    while (p->seguent != inici)
      p = p->seguent;
    p->seguent = new node{i, inici};
  }
}

void estructuraDinamica::Llistar() const {
  // aquest metode es dona fet i no es pot canviar
  if (inici != NULL) {
    node *p = inici->seguent;
    cout << inici->dada << " ";
    while (p != inici) {
      cout << p->dada << " ";
      p = p->seguent;
    }
  }
  cout << endl;
}

void estructuraDinamica::OmplirFinal(int n) {
  // Pre: --;
  // Post: omple am nombres de 1 a n al final de l'estructura
  for (int i = 1; i <= n; i++) {
    AfegirFinal(i);
  }
}

int estructuraDinamica::nElements() const {
  // Pre:--;
  // Post: retorna el nombre d'elements a l'estructura
  int nelements = 0;
  node *p = inici;
  while (p != NULL && p->seguent != inici) {
    p = p->seguent;
    nelements++;
  }
  if (inici != NULL)
    nelements++;
  return nelements;
}