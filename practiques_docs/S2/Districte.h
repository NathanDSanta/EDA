#ifndef DISTRICTE_H
#define DISTRICTE_H

#include <string>

using namespace std;

class Districte
{
    public:
        Districte() {};
        void afegir(int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
        long obtenirNumHabitants() const;
        double obtenirEdatMitjana() const;
        CONTENIDOR resumEstudis() const;
        CONTENIDOR resumNacionalitats() const;
        long comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const;

    private:
    
};

#endif // DISTRICTE_H
