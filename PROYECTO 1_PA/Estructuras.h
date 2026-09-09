#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jugador;

struct Club {
private:
  int Id;
  string Nombre;
  double Presupuesto;
  vector<Jugador *> jugadores;

public:
  Club() : Id(0), Nombre(""), Presupuesto(0.0) {}
  Club(int Id, const string &Nombre, double Presupuesto)
      : Id(Id), Nombre(Nombre), Presupuesto(Presupuesto) {}

  // getters
  int getId() const { return Id; }
  string getNombre() const { return Nombre; }
  double getPresupuesto() const { return Presupuesto; }
  vector<Jugador *> &getJugadores() { return jugadores; }
  // setters
  void setPresupuesto(double Presupuesto) { this->Presupuesto = Presupuesto; }
  // métodos
  void agregarJugador(Jugador *j);
  void quitarJugador(int indice);
};

struct Transferencia {
public:
  int Dia;
  Jugador *jugador;
  double montoPagado;
  Club *Origen;
  Club *Destino;
};
struct Oferta {
public:
  int Id;
  Jugador *jugador;
  Club *Comprador;
  Club *Vendedor;
  double Monto;
  string Estado;
};
#endif