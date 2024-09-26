#include <iostream>
#include "PuntGPS.h"
#include <vector>
using namespace std;

int main() {
    vector<PuntGPS> punts;
    double lat, lon, ele, distancia=0.0;
    cin >> lat >> lon >> ele;
    while (!cin.eof()){ // final fitxer cin
        punts.push_back(PuntGPS(lat,lon,ele));
        cin >> lat >> lon >> ele;
    }
    for (int i=1;i<punts.size();i++) {
        double d = punts[i - 1]-punts[i];
//        cerr << i << " " << punts[i-1] << "--" << punts[i] << ": " << d << endl;
        distancia += d;
    }
    cout << punts.size() << " punts, distancia = " << distancia << " m" << endl;
    cout << "distancia línia recta entre primer i últim: " <<
        punts.front()-punts.back() << " m" << endl;
}
