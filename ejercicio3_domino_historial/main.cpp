#include <iostream>
#include "JuegoDomino.h"

using namespace std;

int main() {
    cout << "juego de domino con historial\n";
    cout << "bienvenido\n\n";
    
    int numJugadores;
    cout << "ingresa el numero de jugadores (2-4): ";
    cin >> numJugadores;
    
    if (numJugadores < 2 || numJugadores > 4) {
        cout << "numero invalido. debe ser entre 2 y 4.\n";
        return 1;
    }
    
    JuegoDomino juego(numJugadores);
    
    bool continuarJugando = true;
    
    while (continuarJugando) {
        juego.iniciarPartida();
        
        while (!juego.juegoTerminado()) {
            juego.jugarTurno();
            juego.mostrarMesa();
        }
        
        juego.finalizarJuego();
        
        char respuesta;
        cout << "\nquieres jugar otra ronda? (s/n): ";
        cin >> respuesta;
        
        if (respuesta != 's' && respuesta != 'S') {
            continuarJugando = false;
        }
    }
    
    cout << "\njuego terminado\n";
    juego.mostrarEstadisticas();
    cout << "gracias por jugar\n";
    
    return 0;
}