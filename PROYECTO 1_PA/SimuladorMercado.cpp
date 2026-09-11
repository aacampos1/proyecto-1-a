#include "SimuladorMercado.h"
#include "Defensa.h"
#include "Delantero.h"
#include "Mediocampista.h"
#include "Portero.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

SimuladorMercado::SimuladorMercado() {
    clubes = nullptr;
    todosLosJugadores = nullptr;
    ofertas = nullptr;
    historialTransferencias = nullptr;
    totalJugadores = 0;
    cantidadOfertas = 0;
    capacidadOfertas = 0;
    cantidadHistorial = 0;
    capacidadHistorial = 0;
    diaActual = 0;
    totalDias = 0;
    indxClubUsuario = -1;
    
    totalGastado = 0.0;
    totalRecibido = 0.0;
    jugadoresComprados = 0;
    jugadoresVendidos = 0;
    ofertasAceptadas = 0;
    ofertasRechazadas = 0;
}

SimuladorMercado::~SimuladorMercado() {
    for (int i = 0; i < totalJugadores; i++) {
        delete todosLosJugadores[i];
    }
    delete[] todosLosJugadores;
    delete[] clubes;
    delete[] ofertas;
    delete[] historialTransferencias;
}

// Getters y Setters
int SimuladorMercado::getTotalJugadores() const { return totalJugadores; }
int SimuladorMercado::getCantidadOfertas() const { return cantidadOfertas; }
int SimuladorMercado::getCantidadHistorial() const { return cantidadHistorial; }
int SimuladorMercado::getDiaActual() const { return diaActual; }
int SimuladorMercado::getTotalDias() const { return totalDias; }

void SimuladorMercado::setTotalJugadores(int totalJugadores) { this->totalJugadores = totalJugadores; }
void SimuladorMercado::setCantidadOfertas(int cantidadOfertas) { this->cantidadOfertas = cantidadOfertas; }
void SimuladorMercado::setCantidadHistorial(int cantidadHistorial) { this->cantidadHistorial = cantidadHistorial; }
void SimuladorMercado::setDiaActual(int diaActual) { this->diaActual = diaActual; }
void SimuladorMercado::setTotalDias(int totalDias) { this->totalDias = totalDias; }

void SimuladorMercado::crearClubes() {
    clubes = new Club[6];
    todosLosJugadores = new Jugador *[30];
    int idGlobal = 1;
    int i = 0;

    // Club del Barcelona
    clubes[0] = Club(1, "FC Barcelona", 0.0);
    Jugador *j6 = new Portero(idGlobal++, "Marc-André ter Stegen", 0.0, &clubes[0]);
    clubes[0].agregarJugador(j6);
    todosLosJugadores[i++] = j6;
    Jugador *j7 = new Defensa(idGlobal++, "Ronald Araújo", 0.0, &clubes[0]);
    clubes[0].agregarJugador(j7);
    todosLosJugadores[i++] = j7;
    Jugador *j8 = new Mediocampista(idGlobal++, "Pedri", 0.0, &clubes[0]);
    clubes[0].agregarJugador(j8);
    todosLosJugadores[i++] = j8;
    Jugador *j9 = new Delantero(idGlobal++, "Robert Lewandowski", 0.0, &clubes[0]);
    clubes[0].agregarJugador(j9);
    todosLosJugadores[i++] = j9;
    Jugador *j10 = new Delantero(idGlobal++, "Lamine Yamal", 0.0, &clubes[0]);
    clubes[0].agregarJugador(j10);
    todosLosJugadores[i++] = j10;

    // Club del Real Madrid
    clubes[1] = Club(2, "Real Madrid", 0.0);
    Jugador *j1 = new Portero(idGlobal++, "Thibaut Courtois", 0.0, &clubes[1]);
    clubes[1].agregarJugador(j1);
    todosLosJugadores[i++] = j1;
    Jugador *j2 = new Defensa(idGlobal++, "Éder Militão", 0.0, &clubes[1]);
    clubes[1].agregarJugador(j2);
    todosLosJugadores[i++] = j2;
    Jugador *j3 = new Mediocampista(idGlobal++, "Jude Bellingham", 0.0, &clubes[1]);
    clubes[1].agregarJugador(j3);
    todosLosJugadores[i++] = j3;
    Jugador *j4 = new Delantero(idGlobal++, "Kylian Mbappé", 0.0, &clubes[1]);
    clubes[1].agregarJugador(j4);
    todosLosJugadores[i++] = j4;
    Jugador *j5 = new Delantero(idGlobal++, "Rodrygo", 0.0, &clubes[1]);
    clubes[1].agregarJugador(j5);
    todosLosJugadores[i++] = j5;

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

    // Club de Bayern Munich
    clubes[3] = Club(4, "Bayern Múnich", 0.0);
    Jugador *j21 = new Portero(idGlobal++, "Manuel Neuer", 0.0, &clubes[3]);
    clubes[3].agregarJugador(j21);
    todosLosJugadores[i++] = j21;
    Jugador *j22 = new Defensa(idGlobal++, "Dayot Upamecano", 0.0, &clubes[3]);
    clubes[3].agregarJugador(j22);
    todosLosJugadores[i++] = j22;
    Jugador *j23 = new Mediocampista(idGlobal++, "Joshua Kimmich", 0.0, &clubes[3]);
    clubes[3].agregarJugador(j23);
    todosLosJugadores[i++] = j23;
    Jugador *j24 = new Delantero(idGlobal++, "Harry Kane", 0.0, &clubes[3]);
    clubes[3].agregarJugador(j24);
    todosLosJugadores[i++] = j24;
    Jugador *j25 = new Mediocampista(idGlobal++, "Jamal Musiala", 0.0, &clubes[3]);
    clubes[3].agregarJugador(j25);
    todosLosJugadores[i++] = j25;

    // Club de Liverpool
    clubes[4] = Club(5, "Liverpool", 0.0);
    Jugador *j16 = new Portero(idGlobal++, "Alisson Becker", 0.0, &clubes[4]);
    clubes[4].agregarJugador(j16);
    todosLosJugadores[i++] = j16;
    Jugador *j17 = new Defensa(idGlobal++, "Virgil van Dijk", 0.0, &clubes[4]);
    clubes[4].agregarJugador(j17);
    todosLosJugadores[i++] = j17;
    Jugador *j18 = new Mediocampista(idGlobal++, "Alexis Mac Allister", 0.0, &clubes[4]);
    clubes[4].agregarJugador(j18);
    todosLosJugadores[i++] = j18;
    Jugador *j19 = new Delantero(idGlobal++, "Mohamed Salah", 0.0, &clubes[4]);
    clubes[4].agregarJugador(j19);
    todosLosJugadores[i++] = j19;
    Jugador *j20 = new Delantero(idGlobal++, "Luis Díaz", 0.0, &clubes[4]);
    clubes[4].agregarJugador(j20);
    todosLosJugadores[i++] = j20;

    // Club de Paris Saint-Germain
    clubes[5] = Club(6, "Paris Saint-Germain", 0.0);
    Jugador *j26 = new Portero(idGlobal++, "Gianluigi Donnarumma", 0.0, &clubes[5]);
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
    
    totalJugadores = i; 
}

void SimuladorMercado::asignarPresupuestos() {
    for (int i = 0; i < 6; i++) {
        int presupuesto = 100 + rand() % 101; // 100 a 200
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
        } else {                                  // Para el delantero
            valor = 35 + rand() % (140 - 35 + 1); // (35 a 140)
        }
        j->setValorMercado(valor);
    }
}

void SimuladorMercado::EstadoInicial() {
    presupuestoInicialUsuario = clubes[indxClubUsuario].getPresupuesto();
    plantillaInicialUsuario = clubes[indxClubUsuario].getJugadores();
}

void SimuladorMercado::agregarOferta(const Oferta &o) {
    if (cantidadOfertas == capacidadOfertas) {
        int nuevaCapacidad = (capacidadOfertas == 0) ? 4 : capacidadOfertas * 2;
        Oferta *temp = new Oferta[nuevaCapacidad];
        for (int i = 0; i < cantidadOfertas; i++) {
            temp[i] = ofertas[i];
        }
        delete[] ofertas;
        ofertas = temp;
        capacidadOfertas = nuevaCapacidad;
    }
    ofertas[cantidadOfertas] = o;
    cantidadOfertas++;
}

void SimuladorMercado::agregarTransferencia(const Transferencia &t) {
    if (cantidadHistorial == capacidadHistorial) {
        int nuevaCapacidad = (capacidadHistorial == 0) ? 4 : capacidadHistorial * 2;
        Transferencia *temp = new Transferencia[nuevaCapacidad];
        for (int i = 0; i < cantidadHistorial; i++) {
            temp[i] = historialTransferencias[i];
        }
        delete[] historialTransferencias;
        historialTransferencias = temp;
        capacidadHistorial = nuevaCapacidad;
    }
    historialTransferencias[cantidadHistorial] = t;
    cantidadHistorial++;
}

// Helper interno
int SimuladorMercado::indiceDelClub(Club *c) const {
    for (int i = 0; i < 6; i++) {
        if (&clubes[i] == c) {
            return i;
        }
    }
    return -1;
}

bool SimuladorMercado::clubSeQuedaSinPosicion(Club &c, Jugador *jugadorQueSaldria) const {
    int mismaPosicion = 0;
    vector<Jugador *> &jugadores = c.getJugadores();
    for (size_t k = 0; k < jugadores.size(); k++) {
        Jugador *j = jugadores[k];
        if (j == jugadorQueSaldria) continue;
        
        bool coincide = false;
        if (dynamic_cast<Portero *>(jugadorQueSaldria) && dynamic_cast<Portero *>(j)) coincide = true;
        else if (dynamic_cast<Defensa *>(jugadorQueSaldria) && dynamic_cast<Defensa *>(j)) coincide = true;
        else if (dynamic_cast<Mediocampista *>(jugadorQueSaldria) && dynamic_cast<Mediocampista *>(j)) coincide = true;
        else if (dynamic_cast<Delantero *>(jugadorQueSaldria) && dynamic_cast<Delantero *>(j)) coincide = true;
        
        if (coincide) mismaPosicion++;
    }
    return mismaPosicion == 0;
}

void SimuladorMercado::ejecutarTransferencia(Jugador *j, Club &origen, Club &destino, double monto) {
    vector<Jugador*> &jugadoresOrigen = origen.getJugadores();
    int idx = -1;
    for (size_t k = 0; k < jugadoresOrigen.size(); k++) {
        if (jugadoresOrigen[k] == j) {
            idx = (int)k;
            break;
        }
    }
    if (idx == -1) return;

    origen.quitarJugador(idx);
    destino.agregarJugador(j);

    origen.setPresupuesto(origen.getPresupuesto() + monto);
    destino.setPresupuesto(destino.getPresupuesto() - monto);

    Transferencia t;
    t.Dia = diaActual;
    t.jugador = j;
    t.montoPagado = monto;
    t.Origen = &origen;
    t.Destino = &destino;
    agregarTransferencia(t);

    if (indiceDelClub(&destino) == indxClubUsuario) {
        totalGastado += monto;
        jugadoresComprados++;
    }
    if (indiceDelClub(&origen) == indxClubUsuario) {
        totalRecibido += monto;
        jugadoresVendidos++;
    }
}

// Menu
void SimuladorMercado::verMiClub() {
    Club &miClub = clubes[indxClubUsuario];
    cout << "\n Club: " << miClub.getNombre() << endl;
    cout << " Presupuesto: " << miClub.getPresupuesto() << " millones" << endl;
    cout << " Plantilla:" << endl;

    vector<Jugador *> &jugadores = miClub.getJugadores();
    for (size_t k = 0; k < jugadores.size(); k++) {
        cout << "---> " << jugadores[k]->mostrarDescripcion() << endl;
    }
}

void SimuladorMercado::explorarJugadores() {
    cout << "\n1. Ver todos" << endl;
    cout << "2. Filtrar por posicion" << endl;
    cout << "3. Buscar por identificador" << endl;
    cout << "SELECCIONA UNA OPCION: ";
    int opcion;
    cin >> opcion;

    bool encontrado = false;

    if (opcion == 2) {
        cout << "1. Portero  2. Defensa  3. Mediocampista  4. Delantero" << endl;
        cout << "posicion: ";
        int pos;
        cin >> pos;
        for (int i = 0; i < 6; i++) {
            if (i == indxClubUsuario) continue;
            
            vector<Jugador *> &jugadores = clubes[i].getJugadores();
            for (size_t k = 0; k < jugadores.size(); k++) {
                Jugador *j = jugadores[k];
                bool coincide =
                    (pos == 1 && dynamic_cast<Portero *>(j)) ||
                    (pos == 2 && dynamic_cast<Defensa *>(j)) ||
                    (pos == 3 && dynamic_cast<Mediocampista *>(j)) ||
                    (pos == 4 && dynamic_cast<Delantero *>(j));
                if (coincide) {
                    cout << "  - " << j->mostrarDescripcion()
                         << "  (Club: " << clubes[i].getNombre() << ")" << endl;
                    encontrado = true;
                }
            }
        }
    } else if (opcion == 3) {
        cout << "Identificador del jugador: ";
        int id;
        cin >> id;
        for (int i = 0; i < 6; i++) {
            if (i == indxClubUsuario) continue;
            
            vector<Jugador *> &jugadores = clubes[i].getJugadores();
            for (size_t k = 0; k < jugadores.size(); k++) {
                if (jugadores[k]->getId() == id) {
                    cout << "  - " << jugadores[k]->mostrarDescripcion()
                         << "  (Club: " << clubes[i].getNombre() << ")" << endl;
                    encontrado = true;
                }
            }
        }
    } else {
        for (int i = 0; i < 6; i++) {
            if (i == indxClubUsuario) continue;
            
            cout << "\nClub: " << clubes[i].getNombre() << endl;
            vector<Jugador *> &jugadores = clubes[i].getJugadores();
            for (size_t k = 0; k < jugadores.size(); k++) {
                cout << "  - " << jugadores[k]->mostrarDescripcion() << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron jugadores con esos criterios." << endl;
    }
}

void SimuladorMercado::realizarOferta() {
    cout << "Ingresa el identificador del jugador que quieres ofertar: ";
    int Id;
    cin >> Id;

    Jugador *jugadorObjetivo = nullptr;
    for (int i = 0; i < totalJugadores; i++) {
        if (todosLosJugadores[i]->getId() == Id) {
            jugadorObjetivo = todosLosJugadores[i];
            break;
        }
    }

    if (jugadorObjetivo == nullptr) {
        cout << "No existe un jugador con ese identificador." << endl;
        return;
    }
    if (jugadorObjetivo->getClubActual() == &clubes[indxClubUsuario]) {
        cout << "No puedes ofertar por un jugador de tu propio club." << endl;
        return;
    }

    int clubVendedorIdx = indiceDelClub(jugadorObjetivo->getClubActual());

    cout << "Monto de la oferta (millones): ";
    double monto;
    cin >> monto;
    if (monto <= 0) {
        cout << "Monto inválido." << endl;
        return;
    }

    Oferta o;
    o.Id = cantidadOfertas + 1;
    o.jugador = jugadorObjetivo;
    o.Comprador = &clubes[indxClubUsuario];
    o.Vendedor = &clubes[clubVendedorIdx];
    o.Monto = monto;
    o.Estado = "pendiente";
    agregarOferta(o);

    cout << "Oferta registrada por " << monto << " millones. Se resolverá al avanzar el día." << endl;
}

void SimuladorMercado::revisarOfertasRecibidas() {
    int idx = -1;
    for (int i = 0; i < cantidadOfertas; i++) {
        if (ofertas[i].Estado == "pendiente" &&
            ofertas[i].Vendedor == &clubes[indxClubUsuario]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "No tienes ofertas pendientes por revisar." << endl;
        return;
    }

    Oferta &o = ofertas[idx];
    cout << "\n" << o.Comprador->getNombre() << " ofrece " << o.Monto
         << " millones por " << o.jugador->getNombre()
         << " (valor actual: " << o.jugador->getValorMercado() << " millones)" << endl;
    cout << "1. Aceptar   2. Rechazar: ";
    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        if (clubSeQuedaSinPosicion(clubes[indxClubUsuario], o.jugador)) {
            cout << "No puedes aceptar: tu club se quedaría sin jugadores en esa posición. La oferta queda rechazada." << endl;
            o.Estado = "rechazada";
            ofertasRechazadas++;
            return;
        }
        if (o.Comprador->getPresupuesto() < o.Monto) {
            cout << o.Comprador->getNombre() << " ya no tiene presupuesto suficiente. La oferta queda rechazada." << endl;
            o.Estado = "rechazada";
            ofertasRechazadas++;
            return;
        }
        ejecutarTransferencia(o.jugador, clubes[indxClubUsuario], *o.Comprador, o.Monto);
        o.Estado = "aceptada";
        ofertasAceptadas++;
        cout << "¡Transferencia realizada!" << endl;
    } else {
        o.Estado = "rechazada";
        ofertasRechazadas++;
        cout << "Oferta rechazada." << endl;
    }
}

void SimuladorMercado::verHistorial() {
    if (cantidadHistorial == 0) {
        cout << "\nTodavía no se ha completado ninguna transferencia." << endl;
        return;
    }
    cout << "\n===== Historial de transferencias =====" << endl;
    for (int i = 0; i < cantidadHistorial; i++) {
        Transferencia &t = historialTransferencias[i];
        cout << "Día " << t.Dia << " | " << t.jugador->getNombre() << " | "
             << t.Origen->getNombre() << " -> " << t.Destino->getNombre()
             << " | " << t.montoPagado << " millones" << endl;
    }
}

void SimuladorMercado::avanzarDia() {
    if (diaActual >= totalDias) {
        cout << "Ya se alcanzó el total de días de la simulación." << endl;
        return;
    }

    diaActual++;

    // Resolver la oferta de compra que el usuario haya enviado
    for (int i = 0; i < cantidadOfertas; i++) {
        if (ofertas[i].Estado != "pendiente" || ofertas[i].Comprador != &clubes[indxClubUsuario]) continue;
        
        Oferta &o = ofertas[i];
        double umbral = o.jugador->getValorMercado() * 1.10;
        bool alcanzaUmbral = o.Monto >= umbral;
        bool hayPresupuesto = o.Comprador->getPresupuesto() >= o.Monto;
        bool dejaSinPosicion = clubSeQuedaSinPosicion(*o.Vendedor, o.jugador);

        cout << "\nResolviendo tu oferta por " << o.jugador->getNombre() << "..." << endl;
        if (alcanzaUmbral && hayPresupuesto && !dejaSinPosicion) {
            ejecutarTransferencia(o.jugador, *o.Vendedor, *o.Comprador, o.Monto);
            o.Estado = "aceptada";
            ofertasAceptadas++;
            cout << "¡Oferta aceptada! Fichaste a " << o.jugador->getNombre() << "." << endl;
        } else {
            o.Estado = "rechazada";
            ofertasRechazadas++;
            cout << "Oferta rechazada";
            if (!alcanzaUmbral) cout << " (el monto no llegó al 110% del valor de mercado)";
            else if (!hayPresupuesto) cout << " (presupuesto insuficiente)";
            else if (dejaSinPosicion) cout << " (el club vendedor se quedaría sin esa posición)";
            cout << "." << endl;
        }
        break; 
    }

    // Generar oferta rival
    bool yaTieneOfertaRecibida = false;
    for (int i = 0; i < cantidadOfertas; i++) {
        if (ofertas[i].Estado == "pendiente" && ofertas[i].Vendedor == &clubes[indxClubUsuario]) {
            yaTieneOfertaRecibida = true;
            break;
        }
    }
    
    if (!yaTieneOfertaRecibida && rand() % 100 < 40) {
        vector<Jugador *> &misJugadores = clubes[indxClubUsuario].getJugadores();
        if (!misJugadores.empty()) {
            int idxJugador = rand() % (int)misJugadores.size();
            Jugador *elegido = misJugadores[idxJugador];

            int idxComprador;
            do {
                idxComprador = rand() % 6;
            } while (idxComprador == indxClubUsuario);

            double valor = elegido->getValorMercado();
            int porcentaje = 90 + rand() % 41; // 90 a 130
            int monto = (int)(valor * porcentaje / 100.0);
            if (monto < 1) monto = 1;

            Oferta o;
            o.Id = cantidadOfertas + 1;
            o.jugador = elegido;
            o.Comprador = &clubes[idxComprador];
            o.Vendedor = &clubes[indxClubUsuario];
            o.Monto = monto;
            o.Estado = "pendiente";
            agregarOferta(o);

            cout << "\n" << clubes[idxComprador].getNombre()
                 << " envió una oferta por " << elegido->getNombre()
                 << ". Revísala en \"Revisar Ofertas Recibidas\"." << endl;
        }
    }

    // Fluctuacion de valores de mercado
    for (int i = 0; i < totalJugadores; i++) {
        Jugador *j = todosLosJugadores[i];
        double valorActual = j->getValorMercado();
        int variacion = -5 + rand() % 11; // -5..5
        double nuevoValor = valorActual * (1.0 + variacion / 100.0);
        if (nuevoValor < 5) nuevoValor = 5;
        j->setValorMercado(nuevoValor);
    }

    cout << "\nDía " << diaActual << " de " << totalDias << " completado." << endl;
}

// REPORTE
void SimuladorMercado::generarReporteFinal() {
    Club &miClub = clubes[indxClubUsuario];

    cout << "\n===== Reporte final =====" << endl;
    cout << "Club administrado: " << miClub.getNombre() << endl;

    cout << "\nPlantilla inicial:" << endl;
    for (size_t k = 0; k < plantillaInicialUsuario.size(); k++) {
        cout << "  - " << plantillaInicialUsuario[k]->mostrarDescripcion() << endl;
    }

    cout << "\nPlantilla final:" << endl;
    vector<Jugador *> &jugadoresFinal = miClub.getJugadores();
    for (size_t k = 0; k < jugadoresFinal.size(); k++) {
        cout << "  - " << jugadoresFinal[k]->mostrarDescripcion() << endl;
    }

    cout << "\nPresupuesto inicial: " << presupuestoInicialUsuario << " millones" << endl;
    cout << "Presupuesto final: " << miClub.getPresupuesto() << " millones" << endl;
    cout << "Total gastado en compras: " << totalGastado << " millones" << endl;
    cout << "Total recibido por ventas: " << totalRecibido << " millones" << endl;
    cout << "Jugadores comprados: " << jugadoresComprados << endl;
    cout << "Jugadores vendidos: " << jugadoresVendidos << endl;
    cout << "Ofertas aceptadas: " << ofertasAceptadas << endl;
    cout << "Ofertas rechazadas: " << ofertasRechazadas << endl;

    verHistorial();
}
