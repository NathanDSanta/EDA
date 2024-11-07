#include "estructuraDinamica.h"
#include <iostream>
using namespace std;

/////// Programa 7
/*
 * Exemples d'execucio
 *
 * entrada:
   3 4 2 -4 0
 * sortida:
   2 3
 *
 * entrada:
   9 7 5 -5 0
 * sortida:
   7 9
 */
int main() {
  int n;
  estructuraDinamica e;

  cin >> n;
  while (n != 0) {
    if (n > 0)
      e.AfegirInici(n);
    else
      e.Esborrar(-n);

    cin >> n;
  }
  e.Llistar();

  return 0;
}
