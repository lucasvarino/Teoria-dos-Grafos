#include <iostream> //entrada pelo teclado e saida pela prompt
#include <fstream>
#include <vector>

using namespace std;

no::no(int id){
    this->id = id;
    this->grauEntrada = grauEntrada;
    this->grauSaida = grauSaida;
    this->proxNo = proNo;
    this->peso = peso;
}

no::~no(){

}

//getters

int no::getId(){
    return this->id;
}

float no::getPeso(){
    return this->peso;
}

int no::getGrauEntrada(){
    return this->grauEntrada;
}

int no::getGrauSaida(){
    return this->grauSaida;
}

//setters

