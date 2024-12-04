#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <list>

using namespace std;
class Graf
{
    public:
        Graf();
        Graf(int nVertexs, bool dirigit = false);
        Graf(char nom_fitxer[], bool dirigit = false);

        void afegirVertex(int v1, int v2);
        void esborrarAresta(int v1, int v2);

        bool existeixAresta(int v1, int v2) const;
        int nVertexs() const;
        int nArestes() const;
        bool esDirigit() const;

        void ordreAssignatures() const;

    private:
        int nVers, nArs;
        bool dirigit;
        vector<list<int> > vertexs;

        int seleccionarPrometedor(const vector<list<int>> &requisits, const vector<bool>& visitats) const;
        void eliminarRequisit(vector<list<int>> &requisits, int x) const;
};

#endif // GRAF_H
