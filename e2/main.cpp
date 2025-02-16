#include "Padro.h"
#include "mostra.h"
#include <ios>
#include <iostream>
using namespace std;

int demanar_int() {
  int aux;
  cin >> aux;
  return aux;
}

string demanar_string() {
  string aux;
  cin >> aux;
  return aux;
}

int main() {
  cout << fixed;
  Padro padro;
  int opcio = demanar_int();
  while (opcio != 0) {
    banner(opcio);
    switch (opcio) {
    case 1:
      mostrar1(padro.llegirDades(demanar_string()));
      break;
    case 2: {
      int any = demanar_int();
      mostrar2(any, padro.existeixAny(any));
      break;
    }
    case 4: {
      int any = demanar_int();
      while (!padro.existeixAny(any)) {
        error("any " + to_string(any) + " inexistent");
        any = demanar_int();
      }
      mostrar4(any, padro.obtenirNumHabitantsPerDistricte(any));
      break;
    }
    case 6:
      mostrar6(padro.resumEstudis());
      break;

    case 7: {
      int districte = demanar_int();
      mostrar7(districte, padro.nombreEstudisDistricte(districte));
      break;
    }

    case 11:
      mostrar11(padro.resumEdat());
      break;

    case 14: {
      int any = demanar_int();
      while (!padro.existeixAny(any)) {
        error("any " + to_string(any) + " inexistent");
        any = demanar_int();
      }
      int districte = demanar_int();
      int edat = demanar_int();
      int codiNacionalitat = demanar_int();
      mostrar14(any, districte, edat, codiNacionalitat, padro.estudisEdat(any, districte, edat, codiNacionalitat));
      break;
    }
    }
    opcio = demanar_int();
  }
  return 0;
}
