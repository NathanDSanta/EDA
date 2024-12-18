// Creat per jhg
// EDA (laboratori): Exercici 6
// Curs 2024/25

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <random>
#include <string>
#include <vector>

const int MIN_COORDINATE_VAL = -1000;
const int MAX_COORDINATE_VAL = 1000;

const int COMPLEXITY_MIN = 3;
const int COMPLEXITY_MAX = 16;

struct Punt {
  Punt() : _x(0), _y(0) {};
  Punt(double x, double y) : _x(x), _y(y) {};

  bool operator<(const Punt &b) {
    return _x < b._x;
  }

  int _x;
  int _y;
};

using namespace std;

default_random_engine generador;
uniform_int_distribution<int> distribucio(MIN_COORDINATE_VAL,
                                          MAX_COORDINATE_VAL);

double distPunts(const Punt &a, const Punt &b) {
  return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
}

// Genera n punts de manera aleatoria i els guarda en el vector
void generarDades(vector<Punt> &v, unsigned int n) {
  chrono::system_clock::time_point timepoint = chrono::system_clock::now();
  unsigned long seed = timepoint.time_since_epoch().count();
  generador.seed(seed);
  for (unsigned int i = 0; i < n; i++) {
    v.emplace_back(distribucio(generador), distribucio(generador));
  }

}

// Mètode que calcula en temps quadràctic la distància mínima entre
// qualsevol parell d'elements a l'interval [esq,dreta) del vector
double distMinQuadratica(const vector<Punt> &punts, int esq, int dreta) {
  double minim = numeric_limits<double>::max();
  for (int i = esq; i < dreta; i++) {
    for (int j = esq; j < dreta; j++) {
      double dist = distPunts(punts[i], punts[j]);
      if (dist < minim && i != j) {
        minim = dist;
      }
    }
  }
  return minim;
};

double combinarSolucions(const vector<Punt> &punts, int esq, int dreta,
                         double minimAB) {
  double minim = minimAB;
  int mig = (dreta - esq) / 2;
  int i = esq;
  while (i < mig) {
    bool iElegible = punts[mig]._x - punts[i]._x < minimAB;
    int j = mig;
    while (j < dreta && iElegible) {
      if (punts[j]._x - punts[mig]._x < minimAB) {
        double dist = distPunts(punts[i], punts[j]);
        if (dist < minimAB) {
          minim = dist;
        }
      }
      j++;
    }
    i++;
  }
  return minim;
}
// Mètode que implementa DiV (recursivitat) i calcula la distància mínima
// entre qualsevol parell d'elements a l'interval [esq,dreta) del vector
double distMinDiVRec(const vector<Punt> &punts, int esq, int dreta) {
  if (dreta - esq < 3) {
    return distMinQuadratica(punts, esq, dreta);
  } else {
    int mig = (dreta + esq) / 2;
    double distA = distMinDiVRec(punts, esq, mig);
    double distB = distMinDiVRec(punts, mig, dreta);
    double minimAB = min(distA, distB);
    return combinarSolucions(punts, esq, dreta, minimAB);
  }
}
// Comparacio (temps i resultat) de l'execució dels dos algoritmes
// amb un vector aleatori de mida n
void compararAlgoritmes(int n, bool opcioC = false) {
  vector<Punt> vec;
  generarDades(vec, n);

  auto startQuadratic = chrono::high_resolution_clock::now();
  double distQuadratica = distMinQuadratica(vec, 0, vec.size());
  auto endQuadratic = chrono::high_resolution_clock::now();

  sort(vec.begin(), vec.end());
  auto startDiv = chrono::high_resolution_clock::now();
  double distDiv = distMinDiVRec(vec, 0, vec.size());
  auto endDiv = chrono::high_resolution_clock::now();

  if (opcioC) {
    cout << setprecision(10);
    cout << setw(10) << left << n << setw(23) << left 
         << chrono::duration<double>(endQuadratic - startQuadratic).count();
    cout << setw(23)
         << chrono::duration<double>(endDiv - startDiv).count() << endl;
  } else {
    cout << "Metode de cost quadratic: " << distQuadratica << " (temps: "
         << chrono::duration<double>(endQuadratic - startQuadratic).count()
         << "s)" << endl;
    cout << "Metode Divideix i Venc: " << distDiv
         << " (temps: " << chrono::duration<double>(endDiv - startDiv).count()
         << "s)" << endl;
  }
}

// Comparacio (temps) de l'execució dels dos algoritmes a mesura que
// s'incrementa la mida del vector aleatori
void estudiComplexitat() {
  cout << setw(10) << left << "n" << setw(23) << left << "Quadratic (segons)" << setw(23)
       << left << "Divideix i venc (segons)\n";
  cout << setw(58)  << right << setfill('-') << "\n";
  cout << setfill(' ');

  for (int i = COMPLEXITY_MIN; i <= COMPLEXITY_MAX; i++) {
    int n = 1 << i;
    compararAlgoritmes(n, true);
  }
}

int main(int argc, char **argv) {
  int punts = 0;
  bool opcioC = false;
  bool parametreDesconegut = false;
  if (argc < 2) {
    cout << "Error: Nombre d'arguments invalid \nUs: ./e6 [-c | -r <int>]\n";
  } else {
    int i = 1;
    while (i < argc && !parametreDesconegut) {
      string param = string(argv[i]);
      if (param == "-r") {
        punts = stoi(argv[i + 1]);
        i++;
      } else if (param == "-c") {
        opcioC = true;
      } else {
        cout << "Error: Argument desconegut \nUs: ./e6 [-c | -r <int>]\n";
        parametreDesconegut = true;
      }
      i++;
    }
  }

  if (opcioC && !parametreDesconegut) {
    estudiComplexitat();
  } else if (punts != 0 && !parametreDesconegut) {
    compararAlgoritmes(punts);
  }
  return 0;
}
