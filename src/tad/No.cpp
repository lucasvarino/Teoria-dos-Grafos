#include <iostream>
#include "No.h"

using namespace std;

No::No()
{
    this->primeiraAresta = NULL;
    this->ultimaAresta = NULL;
}

No::~No()
{
    Aresta *aresta = this->primeiraAresta;

    while (aresta != NULL)
    {
        Aresta *aux = aresta->getProx();
        delete aresta;
        aresta = aux;
    }
    
}

Aresta* No::getPrimeiraAresta()
{
    return this->primeiraAresta;
}

Aresta* No::getUltimaAresta()
{
    return this->ultimaAresta;
}

No* No::getPoxNo()
{
    return this->proxNo;
}