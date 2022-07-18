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

    public:
        Aresta(int targetId, int originId);
        ~Aresta();

        int getTargetId();
        int getOriginId();
        int getTotalArestas();
        float getPesoAresta();
        Aresta* getProx();

        void setProx(Aresta* proxAresta);
        void setPeso(float peso);

};


#endif // ARESTA_H_INCLUDED