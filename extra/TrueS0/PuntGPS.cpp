//
// Created by jordir on 06/7/21.
//
#include "PuntGPS.h"
#include <cmath>

const double PI = acos(-1.0);

PuntGPS::PuntGPS() { _latitud = _longitud = _elevacio = 0.0; }
PuntGPS::PuntGPS(double latitud, double longitud, double elevacio) {
  _latitud = latitud;
  _longitud = longitud;
  _elevacio = elevacio;
}

double PuntGPS::latitud() const { return _latitud; }

double PuntGPS::longitud() const { return _longitud; }

double PuntGPS::elevacio() const { return _elevacio; }

double PuntGPS::operator-(const PuntGPS &p1) const {
  // versió simple prescindint de l'elevació i suposant que la terra és una
  // esfera perfecta però que les distàncies són prou petites per suposar que és
  // plana. 111319.9 són els metres que fa un grau sobre un meridià
  return sqrt(pow(_latitud - p1._latitud, 2.0) +
              pow(_longitud * cos(_latitud / 180 * PI) -
                      p1._longitud * cos(p1._latitud / 180 * PI),
                  2.0)) *
         111319.9;
}

ostream &operator<<(ostream &o, const PuntGPS &p) {
  o << "[" << p._latitud << "," << p._longitud << " (" << p._elevacio << ")]";
  return o;
}