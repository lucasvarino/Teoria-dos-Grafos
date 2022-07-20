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

/*
string linha;
            int numberNodes = 0;
            getline(arquivo, linha);
            numberNodes = stoi(linha);
            linha += "\n";
            int edgeWeigh = 0;
            int nodeId = 0;
            string graphInString = "";
            while (!arquivo.eof() && linha != "")
            {
                string aux = linha;
                getline(arquivo, linha);
                aux.append(linha);
                linha = aux + "\n";
            }
*/

Grafo* leitura(ifstream &arquivo, int directed, int weightedEdge, int weightedNode, int order){
    Grafo *grafo = new Grafo(directed, weightedEdge, weightedNode);

    


    return grafo;

}

void menu()
{
}

int main(int argc, char const *argv[])
{
    // argv[1,2,...] = <arquivo_entrada> <arquivo_saida> <Opc_Direc> <Opc_Peso_Aresta> <Opc_Peso_Nos>
    std::ifstream arquivo;
    if (argc != 6)
        cout << "ERRO-> Todos os parametros sao necessários!";
    else
    {
        string inputTxtPath = argv[1];
        string outputTxtPath = argv[2];
        try
        {
            arquivo.open(inputTxtPath, ios::in);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Houve um erro ao abrir o arquivo de entrada!" << std::endl
                      << e.what() << '\n';
        }
        if (arquivo.is_open())
        {
            int order;
            int teste = 324131;
            arquivo >> order; 
            string Opc_Direc = argv[3]; //0 -> nao direcionado 1 -> direcionado
            string Opc_Peso_Aresta = argv[4]; // 0 -> sem peso nas arestas 1 -> com peso nas arestas
            string Opc_Peso_Nos = argv[5];// 0 -> sem peso nos nos 1 -> com peso nos nos

            arquivo >> teste >> order;
            //cout <<"oioi " << teste << " "<< order <<endl;

        }
    }
    return 0;
}