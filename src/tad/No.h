#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Aresta.h"

class No
{
    private:
        int id;
        Aresta* primeiraAresta;
        Aresta* ultimaAresta;
        No* proxNo;
        int totalArestas;

    public:
        No();
        ~No();

        Aresta* getPrimeiraAresta();
        Aresta* getUltimaAresta();
        No* getPoxNo();
        int getTotalArestas();

        void adicionarAresta(int id, double peso);
        Aresta* procurarAresta(int id);
        void removerAresta(int id);
};

#endif // NO_H_INCLUDED