#ifndef ESTUDI_H
#define ESTUDI_H

#include <string>

using namespace std;

class Estudi
{
    public:
        Estudi(int id, string nom);
        int obtenirId() const;
        string obtenirNom() const;
        bool operator==(const Estudi &estudi) const;

    private:
    
};

#endif // ESTUDI_H
