#include "pilaDinamica.h"

bool ben_parentitzada(pilaDinamica &p, char elem) {
  // Pre: elem =

  bool oki = true;
  if (elem == '(' || elem == '{' || elem == '[')
    p.Empila(elem);
  else if (elem == p.Cim() + 2 || // Codi ASCII: '{' + 2 = '}' i '[' + 2 = ']'
           elem == p.Cim() + 1)   // i '(' + 1 = ')'
    p.Desempila();
  else
    oki = false;
  return oki;
}

int main() {
  pilaDinamica p;
  char c;
  bool OK = true;

  cin >> c;
  while (OK && (c != '.')) {
    OK = ben_parentitzada(p, c);
    cin >> c;
  }

  if (OK && p.Buida())
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
  return 0;
}