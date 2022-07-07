#include "Grafo.h"

using namespace std;

Grafo::Grafo(bool direcionado, bool ponderadoArestas, bool ponderadoVertices)
{
    this->ordem = 0;
    this->direcionado = direcionado;
    this->ponderadoArestas = ponderadoArestas;
    this->ponderadoNos = ponderadoVertices;
}

