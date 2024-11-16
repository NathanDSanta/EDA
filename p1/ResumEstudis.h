// Darius Natan Santa
// u1994947
// Practica 1
//
/// @file ResumEstudis.h
/// @brief Classe ResumEstudis
#include <list>
#include <map>
#include <set>
#include <string>

#include "Estudi.h"

using namespace std;

/**
  @class ResumEstudis
  @brief Aqusta classe guarda la informacio dels diferents estudis de cada any.
  La classe hereda la funcionalitat de map<int,set<Estudi>> cosa que facilita
  les operacions
*/
class ResumEstudis : public map<int, set<Estudi>> {};
