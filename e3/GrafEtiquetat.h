// Jerónimo Hernández González
// Exercici 3 - Laboratoris EDA 24/25

#ifndef GRAF_H
#define GRAF_H

#include "Districte.h"
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Definim el tipus de dada darrera de "Etiqueta"
typedef double Etiqueta;
// Definim el tipus de dada darrera de "Representacio"
typedef vector<map<int, Etiqueta>> Representacio;
// Definim el tipus de dada darrera de "Vertexs"
typedef vector<Districte> Vertexs;

/**
 @class GrafEtiquetat
 @brief Guarda un graf etiquetat
 */
class GrafEtiquetat {

  public:
	/**
	 @param dirigit Boolea que determina si el graf construit es dirigit o no;
	 @post Constructor per defecte (graf no dirigit)
	*/
	GrafEtiquetat(bool dirigit = false);

	/**
	 @return Si es el graf es dirigit
	*/
	bool esDirigit() const;
	/**
	 @return nombre de Vertex del graf
	*/
	int nVertexs() const;
	/**
	 @return nombre d'arestes
	*/
	int nArestes() const;
	/**
	 @return si existeix la Aresta
	 @param v1 enter que determina l'origen de l'aresta
	 @param v2 enter que determina el desti de l'aresta
	 @pre v1 i v2 valid
	*/
	bool existeixAresta(int v1, int v2) const;

	/**
	 @return Etiqueta de la aresta {v1,v2}
	 @param v1 enter que determina l'origen de l'aresta
	 @param v2 enter que determina el desti de l'aresta
	 @pre aresta {v1,v2} existeix
	*/
	Etiqueta etiquetaAresta(int v1, int v2);

	// Afegeix un vèrtex amb el districte donat
	// Torna un nombre (índex) donat al nou vèrtex
	int afegirVertex(const Districte &districte);
	// Afegeix una aresta amb l'etiqueta donada
	// entre els vèrtexs indicats. Si no son correctes,
	// llença excepció
	void afegirAresta(int v1, int v2, const Etiqueta &e);
	// Esborra l'aresta entre v1 i v2
	// si no existeix l'aresta, llença excepció
	void esborrarAresta(int v1, int v2);
	// Esborra el vèrtex
	// si no existeix, llença excepció
	void esborrarVertex(int v);

	// Coloreja el graf
	// No implementada! Llença excepció incondicional
	int coloreja();

	// Implementem l'operador << per a GrafEtiquetat
	friend ostream &operator<<(ostream &os, const GrafEtiquetat &g);

  private:
	bool _dirigit; // Indica si el graf és o no dirigit
	int _numArestes; // guarda el nombre d'arestes del graf
	Representacio _representacio; // representació del graf
	Vertexs _vertexs;

	// Comprova si és un índex vàlid per a un vèrtex
	// És valid si està entre 1 i el nombre total de
	// vèrtexs (ambdos inclosos)
	bool esValid(int v) const;
};

#endif // GRAF_H
