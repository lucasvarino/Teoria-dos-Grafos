#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta 
{
    private:
        int targetId;
        int originId;
        Aresta* prox;
        int totalArestas;
        float pesoAresta;
        bool marcado; // Para funções de caminhamento

    public:
        Aresta(int targetId, int originId);
        ~Aresta();

        int getTargetId();
        int getOriginId();
        int getTotalArestas();
        float getPesoAresta();
        bool getMarcado();
        Aresta* getProx();

        void setProx(Aresta* proxAresta);
        void setPeso(float peso);
        void setMarcado(bool marcado);

};


#endif // ARESTA_H_INCLUDED