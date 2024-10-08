#include "PuntGPS.h"
#include <iostream>

using namespace std;
const int MAX_PUNTS = 100;

int main() {
  PuntGPS punts[MAX_PUNTS];
  double lat, lon, ele, distancia = 0.0;
  int numPunts = 0;
  cin >> lat >> lon >> ele;
  // while(numPunts<MAX_PUNTS && !cin.eof()){ // així controlem no passar-nos
  while (!cin.eof()) { // així error si ens passem de MAX_PUNTS
    punts[numPunts++] = PuntGPS(lat, lon, ele);
    cin >> lat >> lon >> ele;
  }
  if (numPunts == MAX_PUNTS && !cin.eof())
    cout << "ERROR: masses punts" << endl;
  for (int i = 1; i < numPunts; i++) {
    double d = punts[i - 1] - punts[i];
    //        cerr << i << " " << punts[i-1] << "--" << punts[i] << ": " << d <<
    //        endl;
    distancia += d;
  }
  cout << numPunts << " punts, distancia = " << distancia << " m" << endl;
  cout << "distancia línia recta entre primer i últim: "
       << punts[0] - punts[numPunts - 1] << " m" << endl;
}
