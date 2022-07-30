#include <iostream>
#include <queue>
#include <cmath>
#include <list>
#include <string>
#include <limits>
#include "Grafo.h"

using namespace std;

Grafo::Grafo(int ordem, bool direcionado, bool ponderadoArestas, bool ponderadoVertices)
{
    this->ordem = ordem;
    this->direcionado = direcionado;
    this->ponderadoArestas = ponderadoArestas;
    this->ponderadoNos = ponderadoVertices;
    this->primeiroNo = nullptr;
    this->ultimoNo = nullptr;
    this->totalArestas = 0;
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

int Grafo::getTotalArestas()
{
    return this->totalArestas;
}

bool Grafo::getPonderadoArestas()
{
    return this->ponderadoArestas;
}

bool Grafo::getPonderadoNos()
{
    return this->ponderadoNos;
}

No *Grafo::getPrimeiroNo()
{
    return this->primeiroNo;
}

No *Grafo::getUltimoNo()
{
    return this->ultimoNo;
}

/**
 * @brief Insere um nó no Grafo
 *
 * @param id
 * @param peso
 */
void Grafo::inserirNo(int id, float peso = 0)
{
    No *no = new No(id);

    if (this->ponderadoNos)
    {
        no->setPeso(peso);
    }

    if (this->primeiroNo == nullptr)
    {
        this->primeiroNo = no;
        this->ultimoNo = no;
    }
    else
    {
        this->ultimoNo->setProx(no);
        this->ultimoNo = no;
    }
}

/**
 * @brief Remove o nó com id recebido por parâmetro
 *
 * @param id
 */
void Grafo::removerNo(int id)
{
    No *no = this->procurarNo(id);

    if (no == nullptr)
    {
        cout << "Não foi encontrado nenhum nó com o id " << id << endl;
        return;
    }

    No *aux = this->primeiroNo;

    if (this->primeiroNo->getId() == id)
    {
        this->primeiroNo = aux->getProxNo();
        delete aux;
        return;
    }

    no = no->getProxNo();

    while (no != nullptr)
    {
        if (no->getId() == id)
        {
            aux->setProx(no->getProxNo());

            if (no == this->ultimoNo)
            {
                ultimoNo = aux;
            }

            delete no;
            this->ordem--;
            return;
        }

        no = no->getProxNo();
        aux = aux->getProxNo();
    }
}

/**
 * @brief Procura pelo nó com o id recebido por parâmetro
 *
 * @param id
 * @return No* ou nullptr caso não seja encontrado
 */
No *Grafo::procurarNo(int id)
{
    No *aux = this->primeiroNo;

    while (aux != nullptr)
    {
        if (aux->getId() == id)
        {
            return aux;
        }

        aux = aux->getProxNo();
    }

    return nullptr;
}

/**
 * @brief Adiciona uma aresta no Grafo
 *
 * @param idOrigem
 * @param idDestino
 * @param peso
 */
void Grafo::adicionarAresta(int idOrigem, int idDestino, float peso)
{
    // TODO: Verificar se está funcionando corretamente.

    No *origem = this->procurarNo(idOrigem);
    No *destino = this->procurarNo(idDestino);

    if (origem == nullptr)
    {
        this->inserirNo(idOrigem);
        origem = this->procurarNo(idOrigem);
    }

    if (destino == nullptr)
    {
        this->inserirNo(idDestino);
        destino = this->procurarNo(idDestino);
    }

    if (origem != nullptr && destino != nullptr)
    {
        if (!origem->procurarAresta(idDestino))
        {
            origem->adicionarAresta(idDestino, peso);
            this->totalArestas++;
        }
    }
}

/**
 * @brief Função auxiliar para o mapeamento de índices, utilizada em funções de caminhamento
 *
 * @param vet
 * @param id
 * @return int
 */
int Grafo::mapeamentoIndice(int *vet, int id)
{
    for (int i = 0; i < this->ordem; i++)
    {
        if (vet[i] == id)
            return id;
    }

    cout << "Não foi encontrado nenhum vértice com esse id" << endl;
    exit(1); // Para de executar o programa pois há um erro nos vértices
}

/**
 * @brief Desmarca todos os nós do Grafo, utilizada principalmente em funções de
 * caminhamento
 *
 */
void Grafo::desmarcar()
{
    No *no = this->primeiroNo;

    while (no != nullptr)
    {
        Aresta *aresta = no->getPrimeiraAresta();
        no->setMarcado(false);

        while (aresta != nullptr)
        {
            aresta->setMarcado(false);
            aresta = aresta->getProx();
        }

        no = no->getProxNo();
    }
}

// Funcionalidades do Trabalho -

// Caminhamento em Largura - a função deve receber como parâmetro o Id de um nó e imprimir o conjunto de arestas visitadas a
// partir do mesmo em um percurso em largura indicando, para cada uma, se trata-se ou não de uma aresta
// de retorno

/**
 * @brief Realiza o caminhamento em largura no grafo e imprime o conjunto de arestas do percurso,
 * indicando se são ou não arestas de retorno
 *
 * @param id
 */
void Grafo::caminhamentoLargura(int id) // Verificar se está certo
{
    No *no = this->procurarNo(id);

    if (no == nullptr)
    {
        cout << "Nó inválido!" << endl;
        return;
    }

    queue<int> fila; // Estrutura de Fila para realizar o Caminhamento em Largura
    fila.push(id);
    no->setMarcado(true); // Marcando o primeiro nó pois foi o primeiro a ser visitado

    Aresta *aresta;
    No *noDestino;

    int idAtual, idDestino;

    while (!fila.empty())
    {
        aresta = no->getPrimeiraAresta();

        while (aresta != nullptr)
        {
            noDestino = this->procurarNo(aresta->getTargetId());
            idAtual = no->getId();
            idDestino = no->getId();

            if (!noDestino->getMarcado())
            {
                // TODO: String a ser impressa

                no->setMarcado(true);
                fila.push(idDestino); // Coloca na fila o próximo nó, pois ele foi visitado
            }

            // TODO: Verificar arestas de retorno.
            aresta = aresta->getProx();
        }

        fila.pop();
        no = this->procurarNo(fila.front());
    }

    this->desmarcar();
}

void Grafo::caminhamentoProfundidade(No *no)
{
    no->setMarcado(true);
    for (Aresta *aux = no->getPrimeiraAresta(); aux != nullptr; aux = aux->getProx())
    {
        if (!this->procurarNo(aux->getTargetId())->getMarcado())
        {
            caminhamentoProfundidade(this->procurarNo(aux->getTargetId()));
        }
    }
}

// Fecho transitivo direto grafo direcionado

void Grafo::fechoTransitivoDireto(int id)
{
    No *no = this->procurarNo(id);
    this->desmarcar();
    if (no == nullptr)
        cout << "ID inexistente!!" << endl;
    else
    {
        this->caminhamentoProfundidade(no);
        cout << "Fecho transitivo direto: [ ";
        for (no = this->primeiroNo; no != nullptr; no = no->getProxNo())
        {
            Aresta *aresta = no->getPrimeiraAresta();
            if (no->getMarcado())
            {
                cout << no->getId() << " - ";
            }
        }
    }
    cout << " ]" << endl;
}

void Grafo::fechoTransitivoIndireto(int id)
{
    No *alvo = this->procurarNo(id);
    No *verf = this->getPrimeiroNo();
    cout << "Fecho transitivo indireto: [";
    if (alvo != nullptr)
    {
        while (verf != nullptr)
        {
            this->desmarcar();
            this->caminhamentoProfundidade(verf);

            if (alvo->getMarcado())
                if (verf->getId() == id)
                    cout << "";
                else
                    cout << verf->getId() << " - ";

            verf = verf->getProxNo();
        }
    }
    cout << "]" << endl;
}
// Parâmetro: dois IDs de vértices do grafo; (1 ponto)
// Saída: o caminho mínimo entre estes dois vértices usando algoritmo de Djkstra;

string Grafo::djkstra()
{
    int idOrigem, idDestino;
    No *noOrigem, *noDestino;

    string idO, idD;

    try
    {
        cout << "Nó de Origem: " << endl;
        cin >> idO;
        cout << "Nó de Destino: " << endl;
        cin >> idD;

        idOrigem = stoi(idO);
        idDestino = stoi(idD);
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao processar os parâmetros da função" << endl;
        return 0;
    }

    if(idOrigem == idDestino)
    {
        cout << "\nA distância é: 0" << endl;
        return 0;
    }

    noOrigem = this->procurarNo(idOrigem);
    noDestino = this->procurarNo(idDestino);

    if(noOrigem == nullptr || noDestino == nullptr)
    {
        cout << "Não foram encontrados nós com os ids escolhidos" << endl;
        return 0;
    }

    No *noAtual = this->primeiroNo;

    float custos[this->ordem], menorCustoCaminho = INFINITY, menorCustoCaminhoAux;

    No *vPais[this->ordem];

    list<int> listaDisponiveis;
    Aresta *arestaAtual;

    int idMenorCustoCaminho, idMenorCustoCaminhoAux;

    while (noAtual != nullptr)
    {
        if(noAtual != noOrigem)
        {
            listaDisponiveis.push_back(noAtual->getId());
        }

        arestaAtual = noOrigem->arestasEntre(noAtual->getId());

        if(arestaAtual != nullptr && arestaAtual->getPesoAresta() < 0)
        {
            cout << "Não é possível executar o algoritmo com arestas com peso negativo" << endl;
            return "";
        }

        if(arestaAtual != nullptr)
        {
            vPais[noAtual->getId() - 1] = noOrigem;
            custos[noAtual->getId() - 1] = arestaAtual->getPesoAresta();

            if(arestaAtual->getPesoAresta() < menorCustoCaminho)
            {
                menorCustoCaminho = arestaAtual->getPesoAresta();
                idMenorCustoCaminho = noAtual->getId();
            }
        } else {
            custos[noAtual->getId() - 1] = INFINITY;
            vPais[noAtual->getId() - 1] = nullptr;
        }

        noAtual = noAtual->getProxNo();
    }

    custos[noOrigem->getId() - 1] = 0;

    noAtual = this->procurarNo(idMenorCustoCaminho);
    retirarElementoLista(&listaDisponiveis, idMenorCustoCaminho);

    bool atualizouAuxiliaresMenorCusto;

    while (!listaDisponiveis.empty())
    {
        // Verificar grau de saída
        
        if(noAtual->getGrauSaida() < 1)
        {
            idMenorCustoCaminho = this->extrairIdMenorCustoDisponivel(custos, &listaDisponiveis);

            if(idMenorCustoCaminho < 1)
                break;

            menorCustoCaminho = custos[idMenorCustoCaminho - 1];
        } else {
            atualizouAuxiliaresMenorCusto = false;
            menorCustoCaminhoAux = INFINITY;
            arestaAtual = noAtual->getPrimeiraAresta();

            while (arestaAtual != nullptr)
            {
                if(arestaAtual->getPesoAresta() < 0)
                {
                    cout << "Erro: Aresta com peso negativo no Grafo!" << endl;
                    return "";
                }

                noDestino = this->procurarNo(arestaAtual->getTargetId());

                if(this->inList(noDestino->getId(), &listaDisponiveis))
                {
                    if(custos[noDestino->getId() - 1] > arestaAtual->getPesoAresta() + menorCustoCaminho)
                    {
                        custos[noDestino->getId() - 1] = arestaAtual->getPesoAresta() + menorCustoCaminho;
                        vPais[noDestino->getId() - 1] = noAtual;

                        if(custos[noDestino->getId() - 1] < menorCustoCaminhoAux)
                        {
                            menorCustoCaminhoAux = custos[noDestino->getId() - 1];
                            idMenorCustoCaminhoAux = noDestino->getId();
                            atualizouAuxiliaresMenorCusto = true;
                        }
                    }
                }

                arestaAtual = arestaAtual->getProx();
            }

            if(atualizouAuxiliaresMenorCusto)
            {
                menorCustoCaminho = menorCustoCaminhoAux;
                idMenorCustoCaminho = idMenorCustoCaminhoAux;
            } else {
                idMenorCustoCaminho = this->extrairIdMenorCustoDisponivel(custos, &listaDisponiveis);
                menorCustoCaminho = custos[idMenorCustoCaminho - 1];
            }
            
        }

        noAtual = this->procurarNo(idMenorCustoCaminho);
        this->retirarElementoLista(&listaDisponiveis, idMenorCustoCaminho);

    }

    cout << "\n O caminho mínimo entre os vértices é: " << custos[noDestino->getId() - 1] << endl;

    // Gerar o caminho mínimo

    return "";
    
    
}

void Grafo::retirarElementoLista(list<int> *listaVerticesDisponiveis, int verticeMenorCaminhoAtual){
    //percorre a lista de vertices disponiveis
    for(auto it = listaVerticesDisponiveis->begin(); it!=listaVerticesDisponiveis->end();it++){
        if(*it == verticeMenorCaminhoAtual)
        {
            listaVerticesDisponiveis->erase(it);
            break;
        }
    }
}

int Grafo::extrairIdMenorCustoDisponivel(float *custos, list<int> *listaDisponiveis)
{
    int idMenorCusto = 0;
    float menorCusto = INFINITY;

    for (int i = 0; i < this->ordem; i++)
    {
        if(this->inList(i + 1, listaDisponiveis))
        {
            if(custos[i] < menorCusto)
            {
                menorCusto = custos[i];
                idMenorCusto = i + 1;
            }
        }
    }
    
    return idMenorCusto;
}

bool Grafo::inList(int id, list<int> *listaDisponiveis)
{
    for (auto item = listaDisponiveis->begin(); item != listaDisponiveis->end(); item++)
    {
        if(*item == id)
            return true;
    }

    return false;
}

string Grafo::floyd(int idInicial, int idFinal)
{
    float matriz[this->ordem][this->ordem];

    No *noAtual, *noAlvo, *noInicial = this->procurarNo(idInicial), *noFinal = this->procurarNo(idFinal);
    Aresta *arestaAtual;
    int linha, coluna;
    int idInicio = noInicial->getId();
    int idFim = noFinal->getId();

    list<int> caminho;
    list<int>::iterator it;

    if(!this->getPonderadoArestas())
    {
        cout << "O grafo precisa ser ponderado nas arestas!" << endl;
        return "";
    }

    if(noInicial == nullptr || noFinal == nullptr)
    {
        cout << "Erro ao buscar o nó no grafo" << endl;
        return "";
    }

    if(noInicial->getGrauSaida() < 1)
    {
        cout << "O nó selecionado possui grau de saída 0!" << endl;
        return "";
    }

    for (linha = 0; linha < this->ordem; linha++)
    {
        noAtual = this->procurarNo(linha + 1);

        for (coluna = 0; coluna < this->ordem; coluna++)
        {
            noAlvo = this->procurarNo(coluna + 1);

            if(linha == coluna)
            {
                matriz[linha][coluna] = 0;
            } else if(noAtual->procurarAresta(noAlvo->getId())) {
                arestaAtual = noAtual->arestasEntre(noAlvo->getId());

                if(arestaAtual->getPesoAresta() < 0)
                {
                    cout << "Erro: Aresta com peso negativo!" << endl;
                    return "";
                }

                matriz[linha][coluna] = arestaAtual->getPesoAresta();

                if(linha == idInicio - 1 && coluna == idFim - 1)
                {
                    caminho.push_front(idInicio);
                    caminho.push_back(idFim);
                }
            } else {
                matriz[linha][coluna] = INFINITY;
            }

        }
        
    }

    for (int k = 0; k < this->ordem; k++)
    {
        for ( linha = 0; linha < this->ordem; linha++)
        {
            noAtual = this->procurarNo(linha + 1);

            for (coluna = 0; coluna < this->ordem; coluna++)
            {
                noAlvo = this->procurarNo(coluna + 1);

                if(linha != k && coluna != k && linha != coluna)
                {
                    if(matriz[linha][k] != INFINITY && matriz[k][coluna] != INFINITY)
                    {
                        if(matriz[linha][coluna] > matriz[linha][k] + matriz[k][coluna])
                        {
                            matriz[linha][coluna] = matriz[linha][k] + matriz[k][coluna];

                            if(linha == idInicio - 1 && coluna == idFim - 1)
                            {
                                if(caminho.empty())
                                {
                                    caminho.push_front(k + 1);
                                    caminho.push_back(idFim);
                                } else {
                                    it = caminho.end();
                                    it--;
                                    caminho.insert(it, k + 1);
                                }
                            }
                        }
                    }
                }
            }
            
        }
        
    }

    string grafo;

    if(!caminho.empty())
    {
        //Imprimir Caminho
    } else {
        cout << "Não foi possível encontrar um caminho entre os dois vertices!" << endl;
        return "";
    }
    
    return "";
}


string Grafo::arvoreGeradoraMinimaPrim()
{
    string retorno = "AGM por Prim";

    if(this->direcionado) {
        retorno += "Erro: Grafo direcionado!";
        return retorno;
    }

    bool visitados[this->ordem];
    float distancia[this->ordem];
    int caminho[this->ordem];
    float infinito = INFINITY;
    float menorPeso = infinito;
    Aresta* menorAresta;



    for (No *no = this->getPrimeiroNo(); no != nullptr; no = no->getProxNo())
    {
        for (Aresta *aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProx())
        {
            if(aresta->getPesoAresta() <= menorPeso)
            {
                menorPeso = aresta->getPesoAresta();
                menorAresta = aresta;
            }
        }
        
    }

    int idOrigem = menorAresta->getOriginId();

    for (int i = 0; i < this->ordem; i++)
    {
        visitados[i] = false;
        distancia[i] = infinito;
        caminho[i] = -1;
    }

    distancia[idOrigem] = 0;

    for (int i = 0; i < this->ordem; i++)
    {
        int u = this->distMinima(visitados, distancia);
        visitados[u] = true;
        No *noAux = this->procurarNo(u); // Ta vindo null aq

        for (Aresta *adjacente = noAux->getPrimeiraAresta(); adjacente != nullptr ; adjacente = adjacente->getProx())
        {
            if(!visitados[adjacente->getTargetId()] && adjacente->getPesoAresta() < distancia[adjacente->getTargetId()])
            {
                distancia[adjacente->getTargetId()] = adjacente->getPesoAresta();
                caminho[adjacente->getTargetId()] = u;
            }
        }
        
    }
    
    string seta = " -- ";
    retorno += "strict graph { \n";

    for (int i = 0; i < this->ordem; i++)
    {
        if(caminho[i] != -1)
            retorno += "\t" + std::to_string(this->procurarNo(i)->getId()) + seta + std::to_string(this->procurarNo(caminho[i])->getId()) + "\n";
        else if(caminho[i] == -1 && i != idOrigem)
            retorno += "\t" + std::to_string(this->procurarNo(i)->getId()) + "\n";
    }

    retorno += "} \n";
    retorno += "---------------------------------------";
    return retorno;
    
    
}

int Grafo::distMinima(bool visitados[], float dist[]) {
    // Variavel de valor minimo, inicializada como + infinito
    float min = std::numeric_limits<float>::max();
    // Variavel para gravar o id do menor vertice
    int idMenor;
    // Laco que percorre o grafo
    for(int i=0; i<this->ordem; i++){
        // Caso o vertice não tenha sido visitado e tenha distancia menor que a variavel 'min', o mesmo passa a ser o menor
        if(visitados[i]==false && dist[i]<=min){
            min = dist[i];
            idMenor = i;
        }
    }
    // Retorna o vertice de menor valor de distancia
    return idMenor;
}

Grafo* Grafo::subgrafo(int vertices[], int tamanho)
{
    Grafo* subgrafo = new Grafo(tamanho, this->direcionado, this->ponderadoArestas, this->ponderadoNos);

    for (int i = 0; i < tamanho; i++)
    {
        if(!this->existeNoPorIdAux(vertices[i]))
        {
            cout << "Não existe esse vértice no grafo!" << endl;
            return subgrafo;
        }
    }

    for (No *no = this->primeiroNo; no != nullptr ; no = no->getProxNo())
    {
        if(this->auxBuscaVetor(vertices, tamanho, no->getId()))
        {
            if(!subgrafo->existeNoPorIdAux(no->getId()))
            {
                subgrafo->inserirNo(no->getId());
            }

            for (Aresta *aresta = no->getPrimeiraAresta(); aresta != nullptr ; aresta = aresta->getProx())
            {
                if(this->auxBuscaVetor(vertices, tamanho, aresta->getTargetId()))
                {
                    subgrafo->adicionarAresta(aresta->getOriginId(), aresta->getTargetId(), aresta->getPesoAresta());
                }
            }
            
        }
    }
    
    return subgrafo;
    
}

bool Grafo::existeNoPorIdAux(int id_aux) {
    // Veririca se tem No nesse grafo
    if(this->primeiroNo != nullptr) {
        // Percorre os Nos do grafo
        for (No* no = this->primeiroNo; no != nullptr ; no = no->getProxNo()) {
            // Se encontrar o No pelo Id Aux, retorna verdadeiro
            if(no->getId() == id_aux) {
                return true;
            }
        }
    }
    return false;
}

bool Grafo::auxBuscaVetor(int vertices[], int tamanho, int id_aux) {
    // Percorre o vetor
    for(int i = 0; i < tamanho; i++) {
        // Se encontrar, retorna true
        if(vertices[i] == id_aux) {
            return true;
        }
    }
    return false;
}