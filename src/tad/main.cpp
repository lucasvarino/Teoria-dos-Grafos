#include <iostream>
#include <fstream>
#include "Grafo.h"

using namespace std;

/*
• o padrão para a execução a ser utilizado pelo professor será a linha abaixo, executada em ambiente Linux ou
IOS:
•./execGrupoX <arquivo_entrada> <arquivo_saida> <Opc_Direc> <Opc_Peso_Aresta> <Opc_Peso_Nos>, onde
< arquivo_entrada> é o nome do arquivo que contém as informações do grafo, < arquivo_saida> é o arquivo onde
será gravado o grafo armazenado na memória ao término do;

*/

Grafo *lerArquivo(ifstream &arquivo, int isDirecionado, int temPesoAresta, int temPesoNo)
{
    int idNo;
    int pesoAresta;
    int destinoNo;
    int ordem;

    arquivo >> ordem;
    Grafo *grafo = new Grafo(ordem, isDirecionado, temPesoAresta, temPesoNo);

    // leitura -> com peso nas arestas e com peso nos vertices
    if (grafo->getPonderadoArestas() && grafo->getPonderadoNos())
        while (arquivo >> idNo >> destinoNo >> pesoAresta)
        {
            grafo->inserirNo(idNo, 0); // 0 por enquanto
            grafo->adicionarAresta(idNo, destinoNo, pesoAresta);
        }
    else if (!grafo->getPonderadoArestas()) // leitura -> sem peso nas arestas
        while (arquivo >> idNo >> destinoNo)
        {
            grafo->inserirNo(idNo, 0);                  // 0 por enquanto
            grafo->adicionarAresta(idNo, destinoNo, 0); // peso 0 para todas // se descomentar isso nao roda o codigo
        }

    cout << "Grafo de ordem " << ordem << " ultimo no: " << grafo->getUltimoNo()->getId() << " ordem: " << grafo->getOrdem() << endl;
    cout << "Total de Arestas: " << grafo->getTotalArestas();

    
    int idOrigem, idDestino;
    cout << endl << "Id No1" << endl;
    cin >> idOrigem;
    cout << "Id no2" << endl;
    cin >> idDestino;

    grafo->floyd(idOrigem, idDestino);

    return grafo;
}

void menu(Grafo *grafo, string arquivoSaida)
{
    int escolha;
    cout<<"MENU:"<<endl;
    cout<<"[1] Fecho transitivo direto"<<endl;
    cout<<"[2] Fecho transitivo indireto"<<endl;

    cout<<"[0] Sair"<<endl;

    cout<<"Digite o valor desejado: ";
    cin>>escolha;
    switch (escolha)
    {
    case 0:
        cout<<"Au revoir!"<<endl;
        exit(0);
        break;
    case 1:
        cout<<"Escolha o ID para o fecho transitivo direto: ";
        cin>>escolha;
        grafo->fechoTransitivoDireto(escolha);
        menu(grafo, "oi");
        break;
    
    default:
        break;
    }
    
}

int main(int argc, char const *argv[])
{
    // argv[1,2,...] = <arquivo_entrada> <arquivo_saida> <Opc_Direc> <Opc_Peso_Aresta> <Opc_Peso_Nos>
    std::ifstream arquivo;
    string arquivoEntrada = argv[1];
    string arquivoSaida = argv[2];
    
    Grafo *grafo;
    if (argc != 6)
        cout << "ERRO-> Todos os parametros sao necessários!";
    else
    {
        try
        {
            arquivo.open(arquivoEntrada, ios::in);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Houve um erro ao abrir o arquivo de entrada!" << std::endl
                      << e.what() << '\n';
        }
        if (arquivo.is_open())
        {
            string Opc_Direc = argv[3];       // 0 -> nao direcionado 1 -> direcionado
            string Opc_Peso_Aresta = argv[4]; // 0 -> sem peso nas arestas 1 -> com peso nas arestas
            string Opc_Peso_Nos = argv[5];    // 0 -> sem peso nos nos 1 -> com peso nos nos

            grafo = lerArquivo(arquivo, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
        }
        menu(grafo, "oi");
    }
    return 0;
}