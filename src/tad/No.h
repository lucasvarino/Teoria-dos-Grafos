#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Aresta.h"

class No
{
    private:
        Aresta* primeiraAresta;
        Aresta* ultimaAresta;
        No* proxNo;

    public:
        No();
        ~No();

        Aresta* getPrimeiraAresta();
        Aresta* getUltimaAresta();
        No* getPoxNo();
};

#endif // NO_H_INCLUDED