#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "No.h"
#include <list>
#include <vector>
#include <string>

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
        int totalArestas;

    public:
        Grafo(int ordem, bool direcionado, bool ponderadoArestas, bool ponderadoNos);
        ~Grafo();

        int getOrdem();
        bool getDirecionado();
        No* getPrimeiroNo();
        No* getUltimoNo();
        int getTotalArestas();
        bool getPonderadoArestas();
        bool getPonderadoNos();

        void inserirNo(int id, float peso);
        void removerNo(int id);
        No* procurarNo(int id);
        void adicionarAresta(int idOrigem, int idDestino, float peso);
        int mapeamentoIndice(int *vet, int id);
        void desmarcar();

        void caminhamentoLargura(int id);
        void fechoTransitivoDireto(int );
        void caminhamentoProfundidade(No *);

        string djkstra();
        void retirarElementoLista(list<int> *listaDisponiveis, int verticeMenorCaminho);
        int extrairIdMenorCustoDisponivel(float *custos, list<int> *listaDisponiveis);
        bool inList(int id, list<int> *listaDisponiveis);

        string floyd(int idInicial, int idFinal);

        string arvoreGeradoraMinimaPrim();  
        int distMinima(bool visitados[], float dist[]);
        Grafo* subgrafo(int vertices[], int tamanho);
        bool existeNoPorIdAux(int id);
        bool auxBuscaVetor(int vertices[], int tamanho, int id_aux);
};



#endif // GRAFO_H_INCLUDED
