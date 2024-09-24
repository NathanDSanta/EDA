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
  // Post: memòria alliberada;
  if (inici != NULL) {
    node *p = inici->seguent;
    while (p != inici) {
      node *aux = p;
      p = p->seguent;
      delete aux;
    }
    delete p;
    inici = NULL;
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

void estructuraDinamica::AfegirInici(int i) {
  // Pre: --;
  // Post: i afegit al inici
  if (inici == NULL) {
    inici = new node{i, NULL};
    inici->seguent = inici;
  } else {
    node *p = inici;
    while (p->seguent != inici)
      p = p->seguent;
    p->seguent = new node{i, inici};
    inici = p->seguent;
  }
}

void estructuraDinamica::Esborrar(int i) {
  // Pre: --;
  // Post: esborra l'element i de l'estructura

  // Mètode existeix
  bool existeix = false;
  if (inici != NULL) {
    node *ant = inici;
    node *p = inici->seguent;
    while (!existeix && p != inici) {
      if (p->dada == i)
        existeix = true;
      else {
        ant = p;
        p = p->seguent;
      }
    }
    existeix = p->dada == i;

    // Mètode esborrar
    if (existeix) {
      if (p == inici)
        inici = p->seguent;
      ant->seguent = p->seguent;
      if (ant == p)
        inici = NULL;
      delete p;
    }
  }
}