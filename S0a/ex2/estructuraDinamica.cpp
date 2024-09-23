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
#include <cstddef>
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

void estructuraDinamica::AfegirInici(int i) {
  // Pre: --;
  // Post: element afegit al principi
  if (inici == NULL) {
    inici = new node{i, NULL};
    inici->seguent = inici;
  } else {
    node *final = inici->seguent;
    while (final->seguent != inici)
      final = final->seguent;
    final->seguent = new node{i, inici};
    inici = final->seguent;
  }
}

bool estructuraDinamica::Existeix(int i) const {
  // Pre: --;
  // Post: retorna si i existeix a la estructura
  bool existeix = false;
  node *p = inici->seguent;
  if (inici != NULL)
    existeix = inici->dada == i;
  while (inici != NULL && !existeix && p != inici) {
    existeix = p->dada == i;
    p = p->seguent;
  }
  return existeix;
}