
#include "Horari.h"
#include <iostream>
#include <string>
using namespace std;

string demanar_path(string missatge = ""){
  cout << missatge << endl;
  string aux;
  cin >> aux;
  return aux;
}

int main () {
  Horari dades(demanar_path());
  dades.repartirExamens();
  return 0;
}
