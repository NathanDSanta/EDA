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
#include <iostream>

estructuraDinamica::estructuraDinamica() {
  // aquest constructor es dona fet i no es pot canviar
  final = NULL;
}

estructuraDinamica::~estructuraDinamica() {
  // Pre: --;
  // Post: objecte destruit;
  allibera();
}

void estructuraDinamica::allibera() {
  // Pre: --;
  // Post: memòria alliberada;
  node *p = final->seguent;
  while (final != NULL && p != final) {
    node *aux = p;
    p = p->seguent;
    delete aux;
  }
  delete p;
  final = NULL;
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
  // Post: element afegit a l'inici;
  if (final == NULL) {
    final = new node{i};
    final->seguent = final;
  } else {
    node *aux = final->seguent;
    final->seguent = new node{i, aux};
  }
}

void estructuraDinamica::AfegirAbans(int i, int ref) {
  // Pre: ref existeix a l'estructura
  // Post: i inserit abans de ref
  if (final == NULL || final->seguent->dada == ref)
    AfegirInici(i);
  else {
    node *ant = final->seguent;
    while (ant->seguent->dada != ref) {
      ant = ant->seguent;
    }
    node *aux = new node{i, ant->seguent};
    ant->seguent = aux;
  }
}