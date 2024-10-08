#include <iostream>

using namespace std;

#include "ConjuntEnters.h"


int main()
{
    ConjuntEnters c;

    for (int i=1; i<100; i += 3) {
        c.Afegir(i);
        c.Afegir(-i);
    }

    for (int i=-50; i<50; i+=2)
        if (c.Existeix(i))
            cout << "El valor " << i << " existeix en el conjunt" << endl;
        else
            cout << "El valor " << i << " NO existeix en el conjunt" << endl;


    return 0;
}
