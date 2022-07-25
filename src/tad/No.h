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
        unsigned int grauEntrada;
        unsigned int grauSaida;
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
        unsigned int getGrauEntrada();
        unsigned int getGrauSaida();

        void setPeso(float peso);
        void setProx(No *prox);
        void setMarcado(bool marcado);

        void incrementarEntrada();
        void incrementarSaida();
        void decrementarEntrada();
        void decrementarSaida();

        void adicionarAresta(int targetId, float peso);
        bool procurarAresta(int id);
        void removerAresta(int id);
        void removerTodasArestas();

        Aresta* arestasEntre(int id);
};

#endif // NO_H_INCLUDED