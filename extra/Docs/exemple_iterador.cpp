// Creat per jhg 24/25
// Exemple bàsic d'iteradors: busquem el punt d'un GPS en el que se supera una distància màxima donada

#include <iostream>
#include "PuntGPS.h"
#include <list>
using namespace std;

int main() {
    list<PuntGPS> punts;

    double lat,lon,ele,
            distancia=0.0;

    // Llegim els punts de l'entrada estàndar (teclat)
    cin >> lat>>lon>>ele;
    while (!cin.eof()){ // final entrada cin
        punts.push_back(PuntGPS(lat,lon,ele));
        cin >> lat>>lon>>ele;
    }

    double maxdist = 2000.0; // distància màxima (en metres)
    int comptador = 0;
    bool max_superat = false; // flag per aturar la cerca

    // recuperem l'iterador a l'inici de la llista
    list<PuntGPS>::iterator it_prev, it_act = punts.begin();
    it_prev=it_act;
    it_act++;

    // iterem mentre no arribem al final (iterador al final) i no superem el màxim
    while (it_act != punts.end() && not max_superat) {
        comptador++;
        distancia += *it_act - *it_prev;
        max_superat = (distancia > maxdist);
        it_prev=it_act;
        it_act++;
    }

    // comprovem si hem arribat o no al final
    // recordem que accedir al contingut de l'iterador .end() dona error!
    if (max_superat)
        cout << "Hem superat el límit en arribat al punt número " << comptador << ", situat a: " << *it_act << endl;
    else
        cout << "En aquest GPS no s'ha superat el màxim de " << maxdist << " metres de distància." << endl;

}

