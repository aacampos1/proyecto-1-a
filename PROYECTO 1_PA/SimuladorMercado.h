#ifndef SIMULADORMERCADO_H
#define SIMULADORMERCADO_H
#include "Jugador.h"
#include <iostream>
#include <string>
using namespace std;

class SimuladorMercado {
private:
  Club *clubes;
  Jugador **todosLosJugadores;
  Oferta *ofertas;
  Transferencia *historialTransferencias;
  int totalJugadores;
  int cantiadOfertas;
  int capacidadOfertas;
  int cantidadHistorial;
  int capacidadHistorial;
  int diaActual;
  int totalDias;

public:
  SimuladorMercado();
  ~SimuladorMercado();

  // getters
  int getTotalJugadores();
  int getCantidadOfertas();
  int getCantidadHistorial();
  int getDiaActual();
  int getTotalDias();

  // setters
  void setTotalJugadores(int totalJugadores);
  void setCantidadOfertas(int cantidadOfertas);
  void setCantidadHistorial(int cantidadHistorial);
  void setDiaActual(int diaActual);
  void setTotalDias(int totalDias);

  // metodos
  void crearClubes();
  void asignarPresupuestos();
  void asignarValoresMercado();
  void realizarOferta();
  void avanzarDia();
};
#endif