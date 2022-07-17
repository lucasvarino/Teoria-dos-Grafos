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
        float peso;

    public:
        No();
        ~No();

        int getId();
        Aresta* getPrimeiraAresta();
        Aresta* getUltimaAresta();
        No* getProxNo();
        int getTotalArestas();
        void setPeso(float peso);
        void setProx(No *prox);

        void adicionarAresta(int targetId, int originId, float peso);
        Aresta* procurarAresta(int id);
        void removerAresta(int id);
        void removerTodasArestas();
};

#endif // NO_H_INCLUDED