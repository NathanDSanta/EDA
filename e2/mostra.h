// FUNCIONS DE MOSTRA
// Arxiu amb les funcions de mostra del exercici 2 + funcio de mostra
// format ==> 'mostra$()' on $ es el numero de l'opcio
#ifndef MOSTRA_H
#define MOSTRA_H
#include "Padro.h"
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <string>
#include <vector>

void banner(const int &opcio);
void error(const string &missatge);
void mostrar1(const int &linies);
void mostrar2(const int &any, const bool &existeix);
void mostrar4(const int &any, const vector<long> &dades);
void mostrar6(const ResumEstudis &dades);
void mostrar7(int districte, const map<int, int> &dades);
void mostrar11(const ResumEdats &dades);
void mostrar14(int any, int districte, int edat, int codiNacionalitat, const list<string> &dades);

#endif // !MOSTRA_H