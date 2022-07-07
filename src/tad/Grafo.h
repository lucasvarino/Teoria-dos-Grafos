#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "No.h"

using namespace std;

class Grafo 
{
    private:
        int ordem;
        bool direcionado;
        No *primeiroNo;
        bool ponderadoArestas;
        bool ponderadoNos;

    public:
        Grafo(bool direcionado, bool ponderadoArestas, bool ponderadoNos);
        ~Grafo();

        int getOrdem();
        bool getDirecionado();
        No* getPrimeiroNo();
        bool getPonderadoArestas();
        bool getPonderadoNos();
        
};



#endif // GRAFO_H_INCLUDED
