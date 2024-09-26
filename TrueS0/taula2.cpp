#include <iostream>
#include "PuntGPS.h"
using namespace std;

int main() {
    int numPunts;
    PuntGPS *punts;
    double lat, lon, ele, distancia=0.0;
    cerr << "num punts? "; cin >> numPunts;
    punts = new PuntGPS[numPunts];
    for(int i=0;i<numPunts;i++){
        cin >> lat >> lon >> ele;
        punts[i] = PuntGPS(lat,lon,ele);
    }
    for (int i=1;i<numPunts;i++) {
        double d = punts[i - 1] - punts[i];
//        cerr << i << " " << punts[i-1] << "--" << punts[i] << ": " << d << endl;
        distancia += d;
    }
    cout << numPunts << " punts, distancia = " << distancia << " m" << endl;
    cout << "distancia línia recta entre primer i últim: " <<
         punts[0]-punts[numPunts-1] << " m" << endl;
    delete [] punts;
}
