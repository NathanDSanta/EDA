/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Didac Barragan & Joan Surrell.
 *  Copyright (c) 2004-2021 IMAE-UdG.
 *
 */

#include "estructuraDinamica.h"
#include <iostream>

using namespace std;

estructuraDinamica::estructuraDinamica() {
  // aquest constructor es dona fet i no es pot canviar
  inici = final = NULL;
}

estructuraDinamica::~estructuraDinamica() {
  // Pre: --;
  // Post: objecte destruit
  alliberar();
}

void estructuraDinamica::alliberar() {
  // Pre: --;
  // Post: allibera la memòria
  while (inici != NULL) {
    final = inici;
    inici = inici->seguent;
    delete final;
  }
  final = NULL;
}

void estructuraDinamica::AfegirFinal(int i) {
  // Pre: --
  // Post: i afegit al final
  node *p = new node{i, NULL};
  if (final != NULL) {
    final->seguent = p;
    final = final->seguent;
  } else {
    final = p;
    inici = p;
  }
}

void estructuraDinamica::Llistar() const {
  // aquest metode es dona fet i no es pot canviar
  node *p = inici;
  while (p != final) {
    cout << p->dada << " ";
    p = p->seguent;
  }
  if (p != NULL)
    cout << p->dada << endl;
  else
    cout << endl;
}
