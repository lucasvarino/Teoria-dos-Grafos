#include <iostream>
#include "No.h"

using namespace std;

No::No()
{
    this->primeiraAresta = nullptr;
    this->ultimaAresta = nullptr;
    this->totalArestas = 0;
}

No::~No()
{
    Aresta *aresta = this->primeiraAresta;

    while (aresta != nullptr)
    {
        Aresta *aux = aresta->getProx();
        delete aresta;
        aresta = aux;
    }
    
}

int No::getId()
{
    return this->id;
}

Aresta* No::getPrimeiraAresta()
{
    return this->primeiraAresta;
}

Aresta* No::getUltimaAresta()
{
    return this->ultimaAresta;
}

No* No::getProxNo()
{
    return this->proxNo;
}

int No::getTotalArestas()
{
    return this->totalArestas;
}

void No::setPeso(float peso)
{
    this->peso = peso;
}

void No::setProx(No *prox)
{
    this->proxNo = prox;
}

/**
 * @brief Adiciona uma aresta no No
 * 
 * @param id 
 * @param peso 
 */
void No::adicionarAresta(int targetId, int originId, float peso)
{
    Aresta *aresta = new Aresta(targetId, originId);
    aresta->setPeso(peso);

    if (this->primeiraAresta != nullptr)
    {
        this->ultimaAresta->setProx(aresta);
        this->ultimaAresta = aresta;
        this->totalArestas++;

        return;
    }

    this->primeiraAresta = aresta;
    this->totalArestas++;
    
}

/**
 * @brief Procura No nó se existe uma aresta com o parametro id
 * 
 * @param id 
 * @return NULL caso a aresta não seja encontrada ou Aresta*
 */
Aresta* No::procurarAresta(int id)
{
    if (this->primeiraAresta == nullptr)
    {
        return nullptr;
    }

    Aresta *aux = primeiraAresta;

    for (aux; aux != nullptr; aux = aux->getProx())
    {
        if(aux->getTargetId() == id)
        {
            return aux;
        }
    }

    return nullptr;
}

/**
 * @brief Remove a aresta com o id recebido como parâmetro
 * 
 * @param id 
 */
void No::removerAresta(int id)
{
    Aresta* arestaRemover = this->procurarAresta(id);

    if (arestaRemover == nullptr)
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

    if(arestaAnterior != nullptr)
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

/**
 * @brief Remove todas as arestas do No
 * 
 */
void No::removerTodasArestas()
{
    if (this->primeiraAresta != nullptr)
    {
        Aresta *aux = this->primeiraAresta;
        Aresta *prox = this->primeiraAresta->getProx();

        while (aux != nullptr)
        {
            delete aux;
            aux = prox;
            prox = prox->getProx();
        }

    }

    this->totalArestas = 0;
    this->primeiraAresta = nullptr;
    this->ultimaAresta = nullptr;
    
}