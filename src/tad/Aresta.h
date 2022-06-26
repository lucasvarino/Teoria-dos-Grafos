#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta 
{
    private:
        int arestaId;
        Aresta* prox;
        int totalArestas;
        double pesoAresta;

    public:
        Aresta(int arestaId);
        ~Aresta();

        int getArestaId();
        int getTotalArestas();
        double getPesoAresta();
        Aresta* getProx();

        void setProx(Aresta* proxAresta);
        void setPeso(double peso);

};


#endif // ARESTA_H_INCLUDED