#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona
{
    public:
        Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement);
        int obtenirAnyNaixement() const;
        string obtenirNivellEstudis() const;
        int obtenirCodiPaisNaixement() const;

    private:

};

#endif // PERSONA_H
