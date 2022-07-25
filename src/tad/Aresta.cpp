#include <iostream>
#include "Aresta.h"

using namespace std;

Aresta::Aresta(int targetId, int originId)
{
    this->targetId = targetId;
    this->originId = originId;

    this->prox = nullptr;
    this->pesoAresta = 0;
    this->marcado = false;
}

Aresta::~Aresta()
{
    if(this->prox != nullptr)
    {
        delete this->prox;
        this->prox = nullptr;
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

bool Aresta::getMarcado()
{
    return this->marcado;
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

void Aresta::setMarcado(bool marcado)
{
    this->marcado = marcado;
}