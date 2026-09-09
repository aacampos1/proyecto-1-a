#ifndef DEFENSA_H
#define DEFENSA_H
#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;

class Defensa : public Jugador {
public:
  Defensa(int id, const string &nombre, double valorMercado, Club *clubActual)
      : Jugador(id, nombre, valorMercado, clubActual) {}

  string mostrarDescripcion() const override {
    return "Defensa: " + Jugador::mostrarDescripcion();
  }
};
#endif