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
        bool marcado; // Usado em caminhamento em largura

    public:
        No(int id);
        ~No();

        int getId();
        Aresta* getPrimeiraAresta();
        Aresta* getUltimaAresta();
        No* getProxNo();
        int getTotalArestas();
        bool getMarcado();
        void setPeso(float peso);
        void setProx(No *prox);
        void setMarcado(bool marcado);

        void adicionarAresta(int targetId, float peso);
        Aresta* procurarAresta(int id);
        void removerAresta(int id);
        void removerTodasArestas();
};

#endif // NO_H_INCLUDED