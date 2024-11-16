#include <ios>
#include <iostream>

#include "Padro.h"
#include "mostra.h"
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
    case 3:
      mostrar3(padro.obtenirNumHabitantsPerAny());
      break;
    case 4: {
      int any = demanar_int();
      while (!padro.existeixAny(any)) {
        error("any " + to_string(any) + " inexistent");
        any = demanar_int();
      }
      mostrar4(any, padro.obtenirNumHabitantsPerDistricte(any));
      break;
    }
    case 5: {
      int any = demanar_int();
      while (!padro.existeixAny(any)) {
        error("any " + to_string(any) + " inexistent");
        any = demanar_int();
      }
      int districte = demanar_int();
      while (districte < 1 || districte > 6) {
        error("districte " + to_string(districte) + " inexistent");
        districte = demanar_int();
      }
      mostrar5(padro.obtenirNumHabitantsPerSeccio(any, districte), any, districte);
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

    case 8:
      mostrar8(padro.resumNivellEstudis());
      break;

    case 9:
      mostrar9(padro.resumNacionalitats());
      break;

    case 10: {
      int nacionalitat = demanar_int();
      mostrar10(padro.movimentsComunitat(nacionalitat), nacionalitat);
      break;
    }

    case 11:
      mostrar11(padro.resumEdat());
      break;

    case 12:
      mostrar12(padro.movimentVells());
      break;

    case 13: {
      int any1 = demanar_int();
      while (!padro.existeixAny(any1)) {
        error("any " + to_string(any1) + " inexistent");
        any1 = demanar_int();
      }
      int any2 = demanar_int();
      while (!padro.existeixAny(any2)) {
        error("any " + to_string(any2) + " inexistent");
        any2 = demanar_int();
      }
      mostrar13(padro.mesJoves(any1, any2), any1, any2);
      break;
    }
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
