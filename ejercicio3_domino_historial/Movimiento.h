#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <string>
#include "Ficha.h"

class NodoMovimiento {
public:
    std::string nombreJugador;
    Ficha fichaJugada;
    std::string estadoTablero;
    NodoMovimiento* siguiente;
    
    NodoMovimiento(std::string nombre, Ficha ficha, std::string tablero)
        : nombreJugador(nombre), fichaJugada(ficha), estadoTablero(tablero), siguiente(nullptr) {}
};

class HistorialMovimientos {
private:
    NodoMovimiento* cabeza;
    NodoMovimiento* cola;
    int numMovimientos;

public:
    HistorialMovimientos();
    ~HistorialMovimientos();
    
    void agregarMovimiento(std::string nombreJugador, Ficha ficha, std::string estadoTablero);
    void guardarEnArchivo(std::string nombreArchivo) const;
    void limpiar();
    
    int getNumMovimientos() const;
};

#endif