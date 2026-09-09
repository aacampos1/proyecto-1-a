#ifndef MEDIOCAMPISTA_H
#define MEDIOCAMPISTA_H
#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;

class Mediocampista : public Jugador {
public:
  Mediocampista(int id, const string &nombre, double valorMercado,
                Club *clubActual)
      : Jugador(id, nombre, valorMercado, clubActual) {}

  string mostrarDescripcion() const override {
    return "Mediocampista: " + Jugador::mostrarDescripcion();
  }
};
#endif