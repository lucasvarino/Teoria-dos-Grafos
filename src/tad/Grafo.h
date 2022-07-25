#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "No.h"
#include <list>

using namespace std;

class Grafo 
{
    private:
        int ordem;
        bool direcionado;
        No *primeiroNo;
        No *ultimoNo;
        bool ponderadoArestas;
        bool ponderadoNos;

    public:
        Grafo(int ordem, bool direcionado, bool ponderadoArestas, bool ponderadoNos);
        ~Grafo();

        int getOrdem();
        bool getDirecionado();
        No* getPrimeiroNo();
        No* getUltimoNo();
        bool getPonderadoArestas();
        bool getPonderadoNos();

        void inserirNo(int id, float peso);
        void removerNo(int id);
        No* procurarNo(int id);
        void adicionarAresta(int idOrigem, int idDestino, float peso);
        int mapeamentoIndice(int *vet, int id);
        void desmarcar();

        void caminhamentoLargura(int id);

        string djkstra(ofstream &file);
        void retirarElementoLista(list<int> *listaDisponiveis, int verticeMenorCaminho);
        
};



#endif // GRAFO_H_INCLUDED
