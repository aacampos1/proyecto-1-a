#ifndef PORTERO_H
#define PORTERO_H
#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;

class Portero : public Jugador {
public:
  Portero(int id, const string &nombre, double valorMercado, Club *clubActual)
      : Jugador(id, nombre, valorMercado, clubActual) {}

  string mostrarDescripcion() const override {
    return "Portero: " + Jugador::mostrarDescripcion();
  }
};
#endif