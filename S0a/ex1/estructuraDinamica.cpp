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

estructuraDinamica::~estructuraDinamica() {}

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