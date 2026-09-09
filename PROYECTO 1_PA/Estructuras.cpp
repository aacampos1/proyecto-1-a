#include "Estructuras.h"
#include "Jugador.h"

void Club::agregarJugador(Jugador *j) {
  jugadores.push_back(j);
  j->setclubActual(this);
}

void Club::quitarJugador(int indice) {
  if (indice < 0 || indice >= (int)jugadores.size()) {
    cout << "Índice de jugador inválido." << endl;
    return;
  }
  for (int k = indice; k < (int)jugadores.size() - 1; k++) {
    jugadores[k] = jugadores[k + 1];
  }
  jugadores.pop_back();
}