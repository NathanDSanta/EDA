#include <iostream>
#include <list>
using namespace std;

ostream &operator<<(ostream &o, list<int> &l) {
  list<int>::iterator it = l.begin();
  o << "[ ";
  while (it != l.end()) {
    o << *it << " ";
    it++;
  }
  o << "]";
  return o;
}

int main(int argc, const char **argv) {
  int valor = 0;
  list<int> taula(0);

  cout << taula << endl;
  cin >> valor;
  while (valor != -1) {
    taula.push_back(valor);
    cin >> valor;
  }
  cout << taula << endl;
  return 0;
}