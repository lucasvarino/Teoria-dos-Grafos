#include <iostream>
#include "No.h"

using namespace std;

No::No(int id)
{
    this->primeiraAresta = nullptr;
    this->ultimaAresta = nullptr;
    this->totalArestas = 0;
    this->marcado = false;
    this->id = id;
    this->grauEntrada = 0;
    this->grauSaida = 0;
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

bool No::getMarcado()
{
    return this->marcado;
}

unsigned int No::getGrauEntrada()
{
    return this->grauEntrada;
}

unsigned int No::getGrauSaida()
{
    return this->grauSaida;
}

void No::setPeso(float peso)
{
    this->peso = peso;
}

void No::setProx(No *prox)
{
    this->proxNo = prox;
}

void No::setMarcado(bool marcado)
{
    this->marcado = marcado;
}

void No::incrementarEntrada()
{
    this->grauEntrada++;
}

void No::incrementarSaida()
{
    this->grauSaida++;
}

void No::decrementarEntrada()
{
    this->grauEntrada--;
}

void No::decrementarSaida()
{
    this->grauSaida--;
}

/**
 * @brief Adiciona uma aresta no No
 * 
 * @param id 
 * @param peso 
 */
void No::adicionarAresta(int targetId, float peso)
{
    Aresta *aresta = new Aresta(targetId, this->id);
    aresta->setPeso(peso);

    if (this->primeiraAresta != nullptr)
    {
        this->ultimaAresta->setProx(aresta);
        this->ultimaAresta = aresta;
        this->totalArestas++;

        return;
    }

    this->primeiraAresta = aresta;
    this->ultimaAresta = aresta;
    this->totalArestas++;
    
}

/**
 * @brief Procura No nó se existe uma aresta com o parametro id
 * 
 * @param id 
 * @return NULL caso a aresta não seja encontrada ou Aresta*
 */
bool No::procurarAresta(int id)
{
    if(this->primeiraAresta != nullptr)
    {
        for (Aresta *aux = this->primeiraAresta; aux != nullptr; aux = aux->getProx())
        {
            if(aux->getTargetId() == id)
                return true;
        }
        
    }

    return false;

    
}

/**
 * @brief Remove a aresta com o id recebido como parâmetro
 * 
 * @param id 
 */
void No::removerAresta(int id)
{

    if (!this->procurarAresta(id))
    {
        //TODO: Tratar erro: retornar um int? um bool? lançar uma exception?

        cout << "Não foi possível remover a aresta" << endl;
        exit(1);
    }

    Aresta *aux = this->primeiraAresta;
    Aresta *arestaAnterior = nullptr;

    while (aux->getTargetId() != id)
    {
        arestaAnterior = aux;
        aux = aux->getProx();
    }

    if(arestaAnterior != nullptr)
    {
        arestaAnterior->setProx(aux->getProx()); 
    } else {
        this->primeiraAresta = aux->getProx();
    }

    if(this->ultimaAresta == aux)
    {
        this->ultimaAresta = arestaAnterior;
    }

    if (aux->getProx() == this->ultimaAresta)
    {
        this->ultimaAresta = aux->getProx();
    }
    

    delete aux;
    this->totalArestas--;
    
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

Aresta* No::arestasEntre(int id)
{
    for(Aresta *aux = this->primeiraAresta; aux != nullptr; aux = aux->getProx())
    {
        if(aux->getTargetId() == id)
            return aux;
    }

    return nullptr;
}