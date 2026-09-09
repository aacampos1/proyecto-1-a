#ifndef DELANTERO_H
#define DELANTERO_H
#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;

class Delantero : public Jugador {
public:
  Delantero(int id, const string &nombre, double valorMercado, Club *clubActual)
      : Jugador(id, nombre, valorMercado, clubActual) {}

  string mostrarDescripcion() const override {
    return "Delantero: " + Jugador::mostrarDescripcion();
  }
};
#endif