#include "ResumNacionalitats.h"
#include "Nacionalitat.h"

#include <list>
#include <utility>
#include <map>
#include <string>

template class std::map<int, std::list<std::pair<long, Nacionalitat>>>;
