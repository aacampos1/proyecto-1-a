#ifndef JUGADOR_H
#define JUGADOR_H
#include "Estructuras.h"
#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
  int Id;
  string Nombre;
  double ValorMercado;
  Club *clubActual;

public:
  // Constructor por defecto
  Jugador() {
    Id = 0;
    Nombre = "";
    ValorMercado = 0.0;
    clubActual = nullptr;
  }
  // Constructor
  Jugador(const int &Id, const string &Nombre, const double &ValorMercado,
          Club *clubActual)
      : Id(Id), Nombre(Nombre), ValorMercado(ValorMercado),
        clubActual(clubActual) {}

  virtual ~Jugador() {}

  // Setters
  void setNombre(const string &nombre) { this->Nombre = nombre; }
  void setValorMercado(const double &valorMercado) {
    this->ValorMercado = valorMercado;
  }
  void setclubActual(Club *clubActual) { this->clubActual = clubActual; }
  // Getters
  int getId() const { return Id; }
  string getNombre() const { return Nombre; }
  double getValorMercado() const { return ValorMercado; }

  Club *getClubActual() const { return clubActual; }

  virtual string mostrarDescripcion() const {
    return "id: " + to_string(Id) + " Nombre: " + Nombre +
           " Valor: " + to_string(ValorMercado);
  }
};
#endif