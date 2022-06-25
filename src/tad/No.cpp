#include <iostream>
#include "No.h"

using namespace std;

No::No()
{
    this->primeiraAresta = NULL;
    this->ultimaAresta = NULL;
    this->totalArestas = 0;
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

int No::getTotalArestas()
{
    return this->totalArestas;
}

void No::adicionarAresta(int id, double peso)
{
    Aresta *aresta = new Aresta(id);
    aresta->setPeso(peso);

    if (this->primeiraAresta != NULL)
    {
        this->ultimaAresta->setProx(aresta);
        this->ultimaAresta = aresta;
        this->totalArestas++;

        return;
    }

    this->primeiraAresta = aresta;
    this->totalArestas++;
    
}

Aresta* No::procurarAresta(int id)
{
    if (this->primeiraAresta == NULL)
    {
        return NULL;
    }

    Aresta *aux = primeiraAresta;

    for (aux; aux != NULL; aux = aux->getProx())
    {
        if(aux->getArestaId() == id)
        {
            return aux;
        }
    }

    return NULL;
}

void No::removerAresta(int id)
{
    Aresta* arestaRemover = this->procurarAresta(id);

    if (arestaRemover == NULL)
    {
        //TODO: Tratar erro: retornar um int? um bool? lançar uma exception?

        cout << "Não foi possível remover a aresta" << endl;
        exit(1);
    }

    Aresta *arestaAnterior = this->primeiraAresta;

    while (arestaAnterior->getProx() != arestaRemover)
    {
        arestaAnterior = arestaAnterior->getProx();
    }

    Aresta *proxAresta = arestaRemover->getProx();

    if(arestaAnterior != NULL)
    {
        arestaAnterior->setProx(proxAresta); 
    } else {
        this->primeiraAresta->setProx(proxAresta);
    }

    if(this->ultimaAresta == arestaRemover)
    {
        this->ultimaAresta = arestaAnterior;
    }

    if (proxAresta == this->ultimaAresta)
    {
        this->ultimaAresta = proxAresta;
    }
    

    this->totalArestas--;
    delete arestaRemover;
    
}