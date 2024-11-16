// Darius Natan Santa
// u1994947
// Practica 1
//
// @file ResumEdats.h
// @brief Classe ResumEdats
#include <map>
#include <string>
#include <vector>

/**
  @class ResumEdats
  @brief Aquesta classe guarda la informacio de l'edat promig dels habitants per
  cada districte i per cada any, la classe hereda la funcionalitat de
  map<int,map<double,string>> de manera similar a un typedef
*/
class ResumEdats : public std::map<int, std::map<double, std::string>> {};
