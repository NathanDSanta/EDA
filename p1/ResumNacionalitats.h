// Darius Natan Santa
// u1994947
// Practica 1
//
// @file ResumNacionalitats.h
// @brief Classe ResumNacionalitats
#ifndef RESUMNACIONALITATS_H
#define RESUMNACIONALITATS_H
#include <map>
#include <string>
using namespace std;

/**
  @class ResumNacionalitats
  @brief Aquesta classe guarda la informacio dels nombre d'habitants amb la
  nacionalitat indicada per un any en concret. La classe hereda la funcionalitat
  de map<int,map<long,string>> cosa que en facilita l'us
*/

class ResumNacionalitats : public map<int, map<long, string>> {};

#endif // !RESUMNACIONALITATS_H
