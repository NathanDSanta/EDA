//
// Created by jordir on 06/7/21.
//

#ifndef EXEMPLE_PUNTGPS_H
#define EXEMPLE_PUNTGPS_H
#include <iostream>
using namespace std;

class PuntGPS {
public:
    PuntGPS(double latitud, double longitud, double elevacio);
    PuntGPS();

    double latitud() const ; // retorna latitud en graus
    double longitud() const; // retorna longitud en graus
    double elevacio() const; // retorna elevacio en metres

    // distancia entre this i p1
    double operator - (const PuntGPS &p1) const;
    friend ostream &operator<<(ostream &o, const PuntGPS &p); 
private:
    double _latitud; // latitud en graus
    double _longitud; // latitud en graus
    double _elevacio; // elevació en metres
};
#endif //EXEMPLE_PUNTGPS_H
