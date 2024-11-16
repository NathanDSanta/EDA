// Darius Natan Santa
// u1994947
// Practica 1
//
// @file ResumNivellEstudis.h
// @brief Classe ResumNivellEstudis
#ifndef RESUMNIVELLESTUDIS_H
#define RESUMNIVELLESTUDIS_H

#include <map>
#include <utility>
#include <vector>
using namespace std;

/**
  @class ResumNivellEstudis
  @brief Aquesta classe guarda la informacio del nivell d'estudis promig de cada
  districte, quin es el major i quin es el menor, per cada any del padro. La
  classe hereda la funcionalitat de map<int,map<int,pair<double,int>>> cosa que
  en "facilita" l'us
*/

class ResumNivellEstudis : public map<int, map<int, pair<double, int>>> {};

#endif // !RESUMNIVELLESTUDIS_H
