#include <iostream> //entrada pelo teclado e saida pela prompt
#include <fstream>
#include <vector>
#include "../inc/No.h"

using namespace std;

No::No(int id){
    this->id = id;
    this->grauEntrada = grauEntrada;
    this->grauSaida = grauSaida;
    // this->proxNo = proNo;
    this->peso = peso;
}

No::~No(){

}

//getters

int No::getId(){
    return this->id;
}

float No::getPeso(){
    return this->peso;
}

int No::getGrauEntrada(){
    return this->grauEntrada;
}

int No::getGrauSaida(){
    return this->grauSaida;
}

//setters

