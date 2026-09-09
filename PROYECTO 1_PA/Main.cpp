#include "Defensa.h"
#include "Delantero.h"
#include "Jugador.h"
#include "Mediocampista.h"
#include "Portero.h"
#include "SimuladorMercado.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));
  SimuladorMercado simulador;
  simulador.crearClubes();
  simulador.asignarPresupuestos();
  simulador.asignarValoresMercado();
  int OpcionMenu;
  cout << "Creado por:" << endl;
  cout << "Avril - 1386724" << endl;
  cout << "Larissa - 1142526" << endl;
  do {
    cout << "=====Simulador de Transferencia de Fútbol=====" << endl;
    cout << "1. Ver mi Club" << endl;
    cout << "2. Explorar Jugadores" << endl;
    cout << "3. Realizar una Oferta" << endl;
    cout << "4. Revisar Ofertas Recibidas" << endl;
    cout << "5. Ver Historial" << endl;
    cout << "6. Avanzar de día" << endl;
    cout << "7. Salir" << endl;
    cout << "Selecciona una opción: ";
    cin >> OpcionMenu;
    switch (OpcionMenu) {
    case 1:
      cout << "\n" << endl;
      cout << "-----Ver mi Club-----" << endl;
      break;
    case 2:
      cout << "\n" << endl;
      cout << "-----Explorar Jugadores-----" << endl;
      break;
    case 3:
      cout << "\n" << endl;
      cout << "-----Realizar una Oferta-----" << endl;
      break;
    case 4:
      cout << "\n" << endl;
      cout << "-----Revisar Ofertas Recibidas-----" << endl;
      break;
    case 5:
      cout << "\n" << endl;
      cout << "-----Ver Historial-----" << endl;
      break;
    case 6:
      cout << "\n" << endl;
      cout << "-----Avanzar de día-----" << endl;
      break;
    case 7:
      cout << "\n" << endl;
      cout << "Saliendo..." << endl;
      cout << "Generando Reporte..." << endl;
      cout << "" << endl;
      break;
    default:
      cout << "\n" << endl;
      cout << "Opción inválida" << endl;
      break;
    }
  } while (OpcionMenu != 7);
  return 0;
}