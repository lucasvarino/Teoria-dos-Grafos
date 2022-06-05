#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

using namespace std;

class no
{
private:
  int id;
  int grauEntrada;
  int grauSaida;
  float peso;


public:
 //construtor
  no(int id);
 //destrutor
  ~no();
  //getters 
  int getId();
  int getGrauEntrada();
  int getGrauSaida();
  float getPeso();



  //setters




};

#endif // NO_H_INCLUDED