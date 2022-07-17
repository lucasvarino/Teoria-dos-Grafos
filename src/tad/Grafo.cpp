#include <iostream>
#include "Grafo.h"

using namespace std;

Grafo::Grafo(bool direcionado, bool ponderadoArestas, bool ponderadoVertices)
{
    this->ordem = 0;
    this->direcionado = direcionado;
    this->ponderadoArestas = ponderadoArestas;
    this->ponderadoNos = ponderadoVertices;
    this->primeiroNo = nullptr;
    this->ultimoNo = nullptr;
}

Grafo::~Grafo()
{
    No *no = this->primeiroNo;

    while (no != nullptr)
    {
        no->removerTodasArestas();
        No *auxNo = no->getProxNo();
        delete no;
        no = auxNo;
    }
    
}

int Grafo::getOrdem()
{
    return this->ordem;
}

bool Grafo::getPonderadoArestas()
{
    return this->ponderadoArestas;
}

bool Grafo::getPonderadoNos()
{
    return this->ponderadoNos;
}

No* Grafo::getPrimeiroNo()
{
    return this->primeiroNo;
}

No* Grafo::getUltimoNo()
{
    return this->ultimoNo;
}

void Grafo::inserirNo(int id, float peso)
{
    No *no = new No();

    if(this->ponderadoNos)
    {
        no->setPeso(peso);
    }

    if(this->primeiroNo == nullptr)
    {
        this->primeiroNo = no;
        this->ultimoNo = no;
    } else 
    {
        this->ultimoNo->setProx(no);
        this->ultimoNo = no;
    }

    ordem++;
}

void Grafo::removerNo(int id)
{
    No *no = this->procurarNo(id);

    if(no == nullptr)
    {
        cout << "Não foi encontrado nenhum nó com o id " << id << endl;
        return;
    }

    No *aux = this->primeiroNo;

    if(this->primeiroNo->getId() == id)
    {
        this->primeiroNo = aux->getProxNo();
        delete aux;
        return;
    }

    no = no->getProxNo();

    while (no != nullptr)
    {
        if(no->getId() == id)
        {
            aux->setProx(no->getProxNo());

            if(no == this->ultimoNo)
            {
                ultimoNo = aux;
            }

            delete no;
            return;
        }
    }
    
}

No* Grafo::procurarNo(int id)
{
    No *aux = this->primeiroNo;

    while (aux != nullptr)
    {
        if(aux->getId() == id)
        {
            return aux;
        }
    }

    return nullptr;
    
}

