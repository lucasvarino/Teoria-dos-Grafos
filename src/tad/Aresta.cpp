#include <iostream>
#include "Aresta.h"

using namespace std;

Aresta::Aresta(int targetId, int originId)
{
    this->targetId = targetId;
    this->originId = originId;

    this->prox = nullptr;
    this->pesoAresta = 0;
}

Aresta::~Aresta()
{
    Aresta *aux = this->prox;

    while (aux != nullptr)
    {
        delete aux;
        aux = nullptr;
    }
    
    
}

/* Getters */

int Aresta::getTargetId()
{
    return this->targetId;
}

int Aresta::getOriginId()
{
    return this->originId;
}

int Aresta::getTotalArestas()
{
    return this->totalArestas;
}

float Aresta::getPesoAresta()
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

void Aresta::setPeso(float peso)
{
    this->pesoAresta = peso;
}