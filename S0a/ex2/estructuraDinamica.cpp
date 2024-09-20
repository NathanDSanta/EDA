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
