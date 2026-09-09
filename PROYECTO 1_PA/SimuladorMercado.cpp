#include "SimuladorMercado.h"
#include "Defensa.h"
#include "Delantero.h"
#include "Mediocampista.h"
#include "Portero.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
using namespace std;

SimuladorMercado::SimuladorMercado() {
  clubes = nullptr;
  todosLosJugadores = nullptr;
  ofertas = nullptr;
  historialTransferencias = nullptr;
  totalJugadores = 0;
  cantiadOfertas = 0;
  capacidadOfertas = 0;
  cantidadHistorial = 0;
  capacidadHistorial = 0;
  diaActual = 0;
  totalDias = 0;
}
SimuladorMercado::~SimuladorMercado() {}

void SimuladorMercado::crearClubes() {
  clubes = new Club[6];
  todosLosJugadores = new Jugador *[30];
  int idGlobal = 1;
  int i = 0;

  // Club del Real Madrid
  clubes[0] = Club(1, "Real Madrid", 0.0);
  Jugador *j1 = new Portero(idGlobal++, "Thibaut Courtois", 0.0, &clubes[0]);
  clubes[0].agregarJugador(j1);
  todosLosJugadores[i++] = j1;
  Jugador *j2 = new Defensa(idGlobal++, "Éder Militão", 0.0, &clubes[0]);
  clubes[0].agregarJugador(j2);
  todosLosJugadores[i++] = j2;
  Jugador *j3 =
      new Mediocampista(idGlobal++, "Jude Bellingham", 0.0, &clubes[0]);
  clubes[0].agregarJugador(j3);
  todosLosJugadores[i++] = j3;
  Jugador *j4 = new Delantero(idGlobal++, "Kylian Mbappé", 0.0, &clubes[0]);
  clubes[0].agregarJugador(j4);
  todosLosJugadores[i++] = j4;
  Jugador *j5 = new Delantero(idGlobal++, "Rodrygo", 0.0, &clubes[0]);
  clubes[0].agregarJugador(j5);
  todosLosJugadores[i++] = j5;

  // Club del Barcelona
  clubes[1] = Club(2, "FC Barcelona", 0.0);
  Jugador *j6 =
      new Portero(idGlobal++, "Marc-André ter Stegen", 0.0, &clubes[1]);
  clubes[1].agregarJugador(j6);
  todosLosJugadores[i++] = j6;
  Jugador *j7 = new Defensa(idGlobal++, "Ronald Araújo", 0.0, &clubes[1]);
  clubes[1].agregarJugador(j7);
  todosLosJugadores[i++] = j7;
  Jugador *j8 = new Mediocampista(idGlobal++, "Pedri", 0.0, &clubes[1]);
  clubes[1].agregarJugador(j8);
  todosLosJugadores[i++] = j8;
  Jugador *j9 =
      new Delantero(idGlobal++, "Robert Lewandowski", 0.0, &clubes[1]);
  clubes[1].agregarJugador(j9);
  todosLosJugadores[i++] = j9;
  Jugador *j10 = new Delantero(idGlobal++, "Lamine Yamal", 0.0, &clubes[1]);
  clubes[1].agregarJugador(j10);
  todosLosJugadores[i++] = j10;

  // Club del Manchester City
  clubes[2] = Club(3, "Manchester City", 0.0);
  Jugador *j11 = new Portero(idGlobal++, "Ederson", 0.0, &clubes[2]);
  clubes[2].agregarJugador(j11);
  todosLosJugadores[i++] = j11;
  Jugador *j12 = new Defensa(idGlobal++, "Rúben Dias", 0.0, &clubes[2]);
  clubes[2].agregarJugador(j12);
  todosLosJugadores[i++] = j12;
  Jugador *j13 = new Mediocampista(idGlobal++, "Rodri", 0.0, &clubes[2]);
  clubes[2].agregarJugador(j13);
  todosLosJugadores[i++] = j13;
  Jugador *j14 = new Delantero(idGlobal++, "Erling Haaland", 0.0, &clubes[2]);
  clubes[2].agregarJugador(j14);
  todosLosJugadores[i++] = j14;
  Jugador *j15 = new Mediocampista(idGlobal++, "Phil Foden", 0.0, &clubes[2]);
  clubes[2].agregarJugador(j15);
  todosLosJugadores[i++] = j15;

  // Club de Liverpool
  clubes[3] = Club(4, "Liverpool", 0.0);
  Jugador *j16 = new Portero(idGlobal++, "Alisson Becker", 0.0, &clubes[3]);
  clubes[3].agregarJugador(j16);
  todosLosJugadores[i++] = j16;
  Jugador *j17 = new Defensa(idGlobal++, "Virgil van Dijk", 0.0, &clubes[3]);
  clubes[3].agregarJugador(j17);
  todosLosJugadores[i++] = j17;
  Jugador *j18 =
      new Mediocampista(idGlobal++, "Alexis Mac Allister", 0.0, &clubes[3]);
  clubes[3].agregarJugador(j18);
  todosLosJugadores[i++] = j18;
  Jugador *j19 = new Delantero(idGlobal++, "Mohamed Salah", 0.0, &clubes[3]);
  clubes[3].agregarJugador(j19);
  todosLosJugadores[i++] = j19;
  Jugador *j20 = new Delantero(idGlobal++, "Luis Díaz", 0.0, &clubes[3]);
  clubes[3].agregarJugador(j20);
  todosLosJugadores[i++] = j20;

  // Club de Bayern Múnich
  clubes[4] = Club(5, "Bayern Múnich", 0.0);
  Jugador *j21 = new Portero(idGlobal++, "Manuel Neuer", 0.0, &clubes[4]);
  clubes[4].agregarJugador(j21);
  todosLosJugadores[i++] = j21;
  Jugador *j22 = new Defensa(idGlobal++, "Dayot Upamecano", 0.0, &clubes[4]);
  clubes[4].agregarJugador(j22);
  todosLosJugadores[i++] = j22;
  Jugador *j23 =
      new Mediocampista(idGlobal++, "Joshua Kimmich", 0.0, &clubes[4]);
  clubes[4].agregarJugador(j23);
  todosLosJugadores[i++] = j23;
  Jugador *j24 = new Delantero(idGlobal++, "Harry Kane", 0.0, &clubes[4]);
  clubes[4].agregarJugador(j24);
  todosLosJugadores[i++] = j24;
  Jugador *j25 =
      new Mediocampista(idGlobal++, "Jamal Musiala", 0.0, &clubes[4]);
  clubes[4].agregarJugador(j25);
  todosLosJugadores[i++] = j25;

  // Club de Paris Saint-Germain
  clubes[5] = Club(6, "Paris Saint-Germain", 0.0);
  Jugador *j26 =
      new Portero(idGlobal++, "Gianluigi Donnarumma", 0.0, &clubes[5]);
  clubes[5].agregarJugador(j26);
  todosLosJugadores[i++] = j26;
  Jugador *j27 = new Defensa(idGlobal++, "Marquinhos", 0.0, &clubes[5]);
  clubes[5].agregarJugador(j27);
  todosLosJugadores[i++] = j27;
  Jugador *j28 = new Mediocampista(idGlobal++, "Vitinha", 0.0, &clubes[5]);
  clubes[5].agregarJugador(j28);
  todosLosJugadores[i++] = j28;
  Jugador *j29 = new Delantero(idGlobal++, "Ousmane Dembélé", 0.0, &clubes[5]);
  clubes[5].agregarJugador(j29);
  todosLosJugadores[i++] = j29;
  Jugador *j30 = new Defensa(idGlobal++, "Achraf Hakimi", 0.0, &clubes[5]);
  clubes[5].agregarJugador(j30);
  todosLosJugadores[i++] = j30;
}

void SimuladorMercado::asignarPresupuestos() {
  for (int i = 0; i < 6; i++) {
    int presupuesto = 100 + rand() % 101; // 100 a 200 inclusive
    clubes[i].setPresupuesto(presupuesto);
  }
}

void SimuladorMercado::asignarValoresMercado() {
  for (int i = 0; i < 30; i++) {
    Jugador *j = todosLosJugadores[i];
    int valor;
    if (dynamic_cast<Portero *>(j)) {
      valor = 20 + rand() % (70 - 20 + 1); // (20 a 70)
    } else if (dynamic_cast<Defensa *>(j)) {
      valor = 25 + rand() % (90 - 25 + 1); // (25 a 90)
    } else if (dynamic_cast<Mediocampista *>(j)) {
      valor = 30 + rand() % (110 - 30 + 1); // (30 a 110)
    } else {                                // Para el delantero
      valor = 35 + rand() % (140 - 35 + 1); // (35 a 140)
    }
    j->setValorMercado(valor);
  }
}