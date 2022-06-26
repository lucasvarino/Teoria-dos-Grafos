#include <iostream>
#include "Aresta.h"

using namespace std;

Aresta::Aresta(int arestaId)
{
    
}

Aresta::~Aresta()
{
    Aresta *aux = this->prox;

    while (aux != NULL)
    {
        delete aux;
        aux = NULL;
    }
    
    
}

/* Getters */

int Aresta::getArestaId()
{
    return this->arestaId;
}

int Aresta::getTotalArestas()
{
    return this->totalArestas;
}

double Aresta::getPesoAresta()
{
    return this->pesoAresta;
}

Aresta* Aresta::getProx()
{
    return this->prox;
}

/* Setters */

void Aresta::setProx(Aresta* proxAresta)
{
    this->prox = proxAresta;
}

void Aresta::setPeso(double peso)
{
    this->pesoAresta = peso;
}