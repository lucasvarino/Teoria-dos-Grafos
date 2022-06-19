#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

using namespace std;

class No
{
private:
  int id;
  int grauEntrada;
  int grauSaida;
  float peso;


public:
 //construtor
  No(int id);
 //destrutor
  ~No();
  //getters 
  int getId();
  int getGrauEntrada();
  int getGrauSaida();
  float getPeso();



  //setters




};

#endif // NO_H_INCLUDED