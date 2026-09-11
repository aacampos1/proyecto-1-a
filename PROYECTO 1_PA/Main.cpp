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

// Función Para detectar letras
int pedirNumeroEntero(const string &mensaje, int minimo, int maximo) {
  int numero;
  while (true) {
    cout << mensaje;
    cin >> numero;
    if (cin.fail()) {
      cout << "Error: Ingresa solo números.\n";
      cin.clear();
      cin.ignore(10000, '\n');
    } else {
      cin.ignore(10000, '\n');
      if (numero < minimo || numero > maximo) {
        cout << "Debe estar entre " << minimo << " y " << maximo
             << ", intenta de nuevo.\n";
      } else {
        return numero;
      }
    }
  }
}

int main() {
  // Inicialización del Simulador
  srand(time(0));
  SimuladorMercado simulador;
  simulador.crearClubes();
  simulador.asignarPresupuestos();
  simulador.asignarValoresMercado();

  int OpcionMenu;
  cout << "Creado por:" << endl;
  cout << "Avril - 1386724" << endl;
  cout << "Larissa - 1142526" << endl;
  cout << "\n" << endl;
  cout << "====Bienvenido al Simulador de Transferencia de Fútbol====" << endl;
  cout << "\n" << endl;
  cout << "¿Qué club deseas administrar?" << endl;
  for (int i = 0; i < 6; i++) {
    cout << (i + 1) << ". " << simulador.getClubes()[i].getNombre() << endl;
  }
  int opcionClub = pedirNumeroEntero("Elige un número del 1 al 6: ", 1, 6);
  simulador.setIndxClubUsuario(opcionClub - 1);

  int dias = pedirNumeroEntero(
      "¿Cuántos días quieres simular? (entre 5 y 15): ", 5, 15);
  simulador.setTotalDias(dias);
  cout << "\n" << endl;
  cout << "--Antes de empezar..." << endl;
  cout << "\n=== Configuración inicial ===" << endl;
  cout << "Administrando: "
       << simulador.getClubes()[simulador.getIndxClubUsuario()].getNombre()
       << endl;
  cout << "Presupuesto inicial: "
       << simulador.getClubes()[simulador.getIndxClubUsuario()].getPresupuesto()
       << " M€" << endl;
  cout << "Días de simulación: " << simulador.getTotalDias() << endl;
  cout << "\nResumen de los 6 clubes:" << endl;
  for (int i = 0; i < 6; i++) {
    cout << "- " << simulador.getClubes()[i].getNombre()
         << " | Presupuesto: " << simulador.getClubes()[i].getPresupuesto()
         << " M€" << endl;
  }
  cout << "\n" << endl;

  // Menú Principal
  do {
    cout << "=====Simulador de Transferencia de Fútbol=====" << endl;
    cout << "1. Ver mi Club" << endl;
    cout << "2. Explorar Jugadores" << endl;
    cout << "3. Realizar una Oferta" << endl;
    cout << "4. Revisar Ofertas Recibidas" << endl;
    cout << "5. Ver Historial" << endl;
    cout << "6. Avanzar de día" << endl;
    cout << "7. Salir" << endl;
    OpcionMenu = pedirNumeroEntero("Selecciona una opción: ", 1, 7);

    switch (OpcionMenu) {
    case 1:
      cout << "\n-----Ver mi Club-----" << endl;
      simulador.verMiClub(); // ¡Llamada agregada!
      break;
    case 2:
      cout << "\n-----Explorar Jugadores-----" << endl;
      simulador.explorarJugadores(); // ¡Llamada agregada!
      break;
    case 3:
      cout << "\n-----Realizar una Oferta-----" << endl;
      simulador.realizarOferta(); // ¡Llamada agregada!
      break;
    case 4:
      cout << "\n-----Revisar Ofertas Recibidas-----" << endl;
      simulador.revisarOfertasRecibidas(); // ¡Llamada agregada!
      break;
    case 5:
      cout << "\n-----Ver Historial-----" << endl;
      simulador.verHistorial(); // ¡Llamada agregada!
      break;
    case 6:
      cout << "\n-----Avanzar de día-----" << endl;
      simulador.avanzarDia(); // ¡Llamada agregada!
      break;
    case 7:
      cout << "\nSaliendo..." << endl;
      cout << "Generando Reporte..." << endl;
      simulador.generarReporteFinal(); // ¡Llamada agregada!
      break;
    default:
      cout << "\nOpción inválida" << endl;
      break;
    }