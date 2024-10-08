#include "Conjunt.h"

template <class element> // linies separades per fer-ho més entenedor
Conjunt<element>::Conjunt() {
// pre: -
// post: crea un conjunt buit
	nDades = 0;
}


template <class element>
void Conjunt<element>::Afegir(const element &x) {
// pre: cert (error: x no existeix al conjunt i hi ha espai)
// post: afegeix x al conjunt, suposant que no hi sigui
	int i = cercar(x);
	if (i == 0) {
		if (nDades == MAX_DADES)
			throw("No hi ha espai per més elements");
		else {
			nDades++;
			dades[nDades] = x;
		}
	}
}


template <class element>
void Conjunt<element>::Treure(const element &x) {
// pre: cert
// post: elimina x del conjunt, suposant que hi sigui
	int i = cercar(x);
	if (i != 0) {
		dades[i] = dades[nDades];
		nDades--;
	}
}


template <class element>
bool Conjunt<element>::Existeix(const element &x) const {
// pre: cert
// post: retorna cert si x pertany al conjunt
	int i = cercar(x);
	return(i != 0);
}


template <class element>
bool Conjunt<element>::esBuit() const {
// pre: cert
// post: retorna cert si el conjunt es buit
	return(nDades == 0);
}


template <class element>
int Conjunt<element>::cercar(const element &x) const {
// pre: cert
// post: retorna la posicio on es troba x o 0 en cas de no trobar-lo.
	int i = nDades;
	((Conjunt *)this)->dades[0] = x;

	while (!x.esIgual(dades[i])) // o x!=dades[i], si existeix l’operador
		i--;
	return(i);
}
