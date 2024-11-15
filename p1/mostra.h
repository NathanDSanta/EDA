// FUNCIONS DE MOSTRA
// Arxiu amb les funcions de mostra del exercici 2 + funcio de mostra
// format ==> 'mostra$()' on $ es el numero de l'opcio
#ifndef MOSTRA_H
#define MOSTRA_H
#include <algorithm>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Padro.h"
#include "ResumNacionalitats.h"

void banner(const int &opcio);
void error(const string &missatge);
void mostrar1(const int &linies);
void mostrar2(const int &any, const bool &existeix);
void mostrar3(const map<int, long> &dades);
void mostrar4(const int &any, const vector<long> &dades);
void mostrar5(const map<int, long> &dades, const int &any, const int &districte);
void mostrar6(const ResumEstudis &dades);
void mostrar7(int districte, const map<int, int> &dades);
void mostrar8(const ResumNivellEstudis &dades);
void mostrar9(const ResumNacionalitats &dades);
void mostrar10(const map<int, string> &dades, const int &nacionalitat);
void mostrar11(const ResumEdats &dades);
void mostrar12(const map<int, string> &dades);
void mostrar13(const pair<string, long> &dades, const int &anyInici, const int &anyFinal);
void mostrar14(int any, int districte, int edat, int codiNacionalitat, const list<string> &dades);

#endif // !MOSTRA_H
