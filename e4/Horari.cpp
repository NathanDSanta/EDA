#include "Horari.h"

#include <fstream>
#include <list>
#include <ostream>
#include <string>
#include <vector>

#include "Assignatura.h"
#include "eines.h"

Horari::Horari(string path) {
  if (path.length() != 0) {
    ifstream fin(path);

    if (fin.fail()) {
      throw "Invalid Path";
    }

    while (!fin.eof()) {
      string linia;
      getline(fin, linia);
      vector<string> elements = tokens(linia, '\t');
      Assignatura afegir(elements[0], elements[1], stringToInt(elements[2]), elements[3] == "g", stringToInt(elements[4]), stringToInt(elements[5]),stringToInt(elements[6]));
      a_assignatures.push_back(afegir);
    }
  }
}

int Horari::stringToInt(string s) {
  if (s.length() == 0)
    return -1;

  for (char c : s) {
    if (c < '0' || c > '9')
      return -1;
  }

  return stoi(s);
}

//Debugging
ostream &operator<<(ostream &o, const Horari &h){
  o << "Assignatures: \n";
  for(list<Assignatura>::const_iterator i = h.a_assignatures.begin(); i != h.a_assignatures.end(); i++){
    o << *i << endl;
  }
  return o;
}
