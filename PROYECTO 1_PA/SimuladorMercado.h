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
  int cantidadOfertas;
  int capacidadOfertas;
  int cantidadHistorial;
  int capacidadHistorial;
  int diaActual;
  int totalDias;
  int indxClubUsuario;

  //estadoinicial del club usuario
  double presupuestoInicialUsuario;
  vector<Jugador *> plantillaInicialUsuario;

  //Acumuladores
  double totalGastado;
  double totalRecibido;
  int jugadoresComprados;
  int jugadoresVendidos;
  int ofertasAceptadas;
  int ofertasRechazadas;
 
  //Helpers Internos
  int indiceDelClub(Club *c) const;
  bool clubSeQuedaSinPosicion(Club &c, Jugador *jugadorQueSaldria) const;
  void ejecutarTransferencia(Jugador *j, Club &origen, Club &destino,
   double monto);

public:
  SimuladorMercado();
  ~SimuladorMercado();

  // getters
  int getTotalJugadores();
  int getCantidadOfertas();
  int getCantidadHistorial();
  int getDiaActual();
  int getTotalDias();
  int getIndxClubUsuario() const { return indxClubUsuario; };
  Club *getClubes() const { return clubes; }

  // setters
int getTotalJugadores() const;
    int getCantidadOfertas() const;
    int getCantidadHistorial() const;
    int getDiaActual() const;
    int getTotalDias() const;

    void agregarOferta(const Oferta &o);
    void agregarTransferencia(const Transferencia &t);

  // metodos
  void crearClubes();
  void asignarPresupuestos();
  void asignarValoresMercado();
  void realizarOferta();
  void avanzarDia();
  void agregarOferta(Oferta o);
  void agregarTransferencia(Transferencia t);
  void EstadoInicial();

  //opciones menu
  void verMiClub();
  void explorarJugadores();
  void revisarOfertasRecibidas();
  void verHistorial();
  void generarReporteFinal();

};
#endif