#include "Movimiento.h"
#include <fstream>

HistorialMovimientos::HistorialMovimientos() : cabeza(nullptr), cola(nullptr), numMovimientos(0) {}

HistorialMovimientos::~HistorialMovimientos() {
    limpiar();
}

void HistorialMovimientos::agregarMovimiento(std::string nombreJugador, Ficha ficha, std::string estadoTablero) {
    NodoMovimiento* nuevo = new NodoMovimiento(nombreJugador, ficha, estadoTablero);
    
    if (cabeza == nullptr) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
    
    numMovimientos++;
}

void HistorialMovimientos::guardarEnArchivo(std::string nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        return;
    }
    
    archivo << "historial de movimientos - juego de domino\n";
    archivo << "total de movimientos: " << numMovimientos << "\n\n";
    
    NodoMovimiento* actual = cabeza;
    int contador = 1;
    
    while (actual != nullptr) {
        archivo << "movimiento " << contador << ":\n";
        archivo << "jugador: " << actual->nombreJugador << "\n";
        archivo << "ficha jugada: " << actual->fichaJugada.toString() << "\n";
        archivo << "estado del tablero: " << actual->estadoTablero << "\n";
        archivo << "\n";
        
        actual = actual->siguiente;
        contador++;
    }
    
    archivo.close();
}

void HistorialMovimientos::limpiar() {
    NodoMovimiento* actual = cabeza;
    while (actual != nullptr) {
        NodoMovimiento* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    cabeza = cola = nullptr;
    numMovimientos = 0;
}

int HistorialMovimientos::getNumMovimientos() const {
    return numMovimientos;
}