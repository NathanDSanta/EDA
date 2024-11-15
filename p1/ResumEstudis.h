#include <list>
#include <map>
#include <set>
#include <string>

#include "Estudi.h"

using namespace std;

class ResumEstudis : public map<int, set<Estudi>> {};
