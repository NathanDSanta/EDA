/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * JSS - 2009
 *    cal afegir-hi els metodes a implementar
 * JSS - 2022
 *    es obligatori implementar el destructor
 */

#include "estructuraDinamica.h"
#include <cstddef>
#include <iostream>

estructuraDinamica::estructuraDinamica() {
  // aquest constructor es dona fet i no es pot canviar
  final = NULL;
}

estructuraDinamica::estructuraDinamica(const estructuraDinamica &e) {
  // Pre: --;
  // Post: *this = *e;
  final = NULL;
  if (e.final != NULL) {
    node *p = e.final->seguent, *q = final;
    while (p != e.final) {
      AfegirFinal(p->dada);
      p = p->seguent;
    }
    AfegirFinal(p->dada);
  }
}

estructuraDinamica::~estructuraDinamica() {
  // Pre: --;
  // Post: objecte destruit;
  allibera();
}

void estructuraDinamica::allibera() {
  // Pre: --;
  // Post: memòria alliberada
  if (final != NULL) {
    node *p = final->seguent;
    while (p != final) {
      node *aux = p;
      p = p->seguent;
      delete aux;
    }
    delete p;
    final = NULL;
  }
}

void estructuraDinamica::Llistar() const {
  // aquest metode es dona fet i no es pot canviar
  node *p;

  if (final != NULL) {
    p = final->seguent;
    while (p != final) {
      cout << p->dada << " ";
      p = p->seguent;
    }
    cout << final->dada;
  }
  cout << endl;
}

void estructuraDinamica::AfegirInici(int i) {
  // Pre: --;
  // Post: i afegit a l'inici de l'estructura
  if (final == NULL) {
    final = new node{i, NULL};
    final->seguent = final;
  } else {
    node *aux = final->seguent;
    final->seguent = new node{i, aux};
  }
}

void estructuraDinamica::AfegirFinal(int i) {
  // Pre: --;
  // Post: element i afegit al final de l'estructura;
  if (final == NULL) {
    final = new node{i, NULL};
    final->seguent = final;
  } else {
    node *aux = final->seguent;
    final->seguent = new node{i, aux};
    final = final->seguent;
  }
}