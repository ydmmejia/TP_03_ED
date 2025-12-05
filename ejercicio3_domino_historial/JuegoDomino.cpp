#include "JuegoDomino.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>

JuegoDomino::JuegoDomino(int numJugadores) : turnoActual(0) {
    for (int i = 0; i < numJugadores; i++) {
        std::string nombre = "jugador " + std::to_string(i + 1);
        jugadores.push_back(Jugador(nombre));
    }
    crearFichas();
}

void JuegoDomino::crearFichas() {
    todasLasFichas.clear();
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            todasLasFichas.push_back(Ficha(i, j));
        }
    }
}

void JuegoDomino::mezclarFichas() {
    srand(time(0));
    for (size_t i = 0; i < todasLasFichas.size(); i++) {
        int j = rand() % todasLasFichas.size();
        std::swap(todasLasFichas[i], todasLasFichas[j]);
    }
}

void JuegoDomino::distribuirFichas() {
    int fichasPorJugador = todasLasFichas.size() / jugadores.size();
    int indice = 0;
    
    for (auto& jugador : jugadores) {
        jugador.limpiarFichas();
        for (int i = 0; i < fichasPorJugador; i++) {
            jugador.agregarFicha(todasLasFichas[indice++]);
        }
    }
}

void JuegoDomino::iniciarPartida() {
    std::cout << "\niniciando nueva partida\n";
    
    crearFichas();
    mezclarFichas();
    distribuirFichas();
    mesa.clear();
    historial.limpiar();
    turnoActual = 0;
    
    std::cout << "fichas distribuidas\n";
    std::cout << "total de fichas: 28\n";
    std::cout << "fichas por jugador: " << jugadores[0].getNumFichas() << "\n\n";
}

int JuegoDomino::getExtremoIzquierdo() const {
    if (mesa.empty()) return -1;
    return mesa.front().getLado1();
}

int JuegoDomino::getExtremoDerecho() const {
    if (mesa.empty()) return -1;
    return mesa.back().getLado2();
}

std::string JuegoDomino::obtenerEstadoMesa() const {
    if (mesa.empty()) return "(vacia)";
    
    std::stringstream ss;
    for (const auto& ficha : mesa) {
        ss << ficha.toString() << " ";
    }
    return ss.str();
}

void JuegoDomino::jugarTurno() {
    Jugador& jugadorActual = jugadores[turnoActual];
    
    std::cout << "\nturno de " << jugadorActual.getNombre() << "\n";
    jugadorActual.mostrarFichas();
    
    if (mesa.empty()) {
        std::cout << "la mesa esta vacia. coloca cualquier ficha.\n";
        std::cout << "ingresa el numero de ficha (1-" << jugadorActual.getNumFichas() << "): ";
        int opcion;
        std::cin >> opcion;
        
        if (opcion >= 1 && opcion <= jugadorActual.getNumFichas()) {
            Ficha fichaJugada = jugadorActual.getFicha(opcion - 1);
            mesa.push_back(fichaJugada);
            jugadorActual.removerFicha(opcion - 1);
            
            historial.agregarMovimiento(jugadorActual.getNombre(), fichaJugada, obtenerEstadoMesa());
            
            std::cout << "ficha colocada: ";
            fichaJugada.imprimir();
            std::cout << std::endl;
        } else {
            std::cout << "opcion invalida\n";
            return;
        }
    } else {
        int extremoIzq = getExtremoIzquierdo();
        int extremoDer = getExtremoDerecho();
        
        mostrarMesa();
        std::cout << "extremos: izq=" << extremoIzq << ", der=" << extremoDer << "\n";
        
        if (!jugadorActual.tieneFichasConectables(extremoIzq, extremoDer)) {
            std::cout << jugadorActual.getNombre() << " no puede jugar. pasa turno.\n";
            turnoActual = (turnoActual + 1) % jugadores.size();
            return;
        }
        
        std::cout << "opciones:\n";
        std::cout << "  numero de ficha (1-" << jugadorActual.getNumFichas() << ")\n";
        std::cout << "  lado (1=izquierda, 2=derecha)\n";
        
        int numFicha, lado;
        std::cout << "ingresa ficha y lado (ej: 1 2): ";
        std::cin >> numFicha >> lado;
        
        if (numFicha < 1 || numFicha > jugadorActual.getNumFichas()) {
            std::cout << "ficha invalida\n";
            return;
        }
        
        Ficha fichaJugada = jugadorActual.getFicha(numFicha - 1);
        
        if (lado == 1) {
            if (fichaJugada.puedeConectar(extremoIzq)) {
                if (fichaJugada.getLado2() != extremoIzq) {
                    fichaJugada.voltear();
                }
                mesa.insert(mesa.begin(), fichaJugada);
                jugadorActual.removerFicha(numFicha - 1);
                
                historial.agregarMovimiento(jugadorActual.getNombre(), fichaJugada, obtenerEstadoMesa());
                
                std::cout << "ficha colocada en izquierda: ";
                fichaJugada.imprimir();
                std::cout << std::endl;
            } else {
                std::cout << "la ficha no conecta con el extremo izquierdo\n";
                return;
            }
        } else if (lado == 2) {
            if (fichaJugada.puedeConectar(extremoDer)) {
                if (fichaJugada.getLado1() != extremoDer) {
                    fichaJugada.voltear();
                }
                mesa.push_back(fichaJugada);
                jugadorActual.removerFicha(numFicha - 1);
                
                historial.agregarMovimiento(jugadorActual.getNombre(), fichaJugada, obtenerEstadoMesa());
                
                std::cout << "ficha colocada en derecha: ";
                fichaJugada.imprimir();
                std::cout << std::endl;
            } else {
                std::cout << "la ficha no conecta con el extremo derecho\n";
                return;
            }
        } else {
            std::cout << "lado invalido\n";
            return;
        }
    }
    
    turnoActual = (turnoActual + 1) % jugadores.size();
}

void JuegoDomino::mostrarMesa() const {
    std::cout << "\nmesa: ";
    if (mesa.empty()) {
        std::cout << "(vacia)";
    } else {
        for (const auto& ficha : mesa) {
            ficha.imprimir();
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

bool JuegoDomino::hayBloqueo() {
    int extremoIzq = getExtremoIzquierdo();
    int extremoDer = getExtremoDerecho();
    
    for (const auto& jugador : jugadores) {
        if (jugador.tieneFichasConectables(extremoIzq, extremoDer)) {
            return false;
        }
    }
    return true;
}

bool JuegoDomino::juegoTerminado() const {
    for (const auto& jugador : jugadores) {
        if (jugador.getNumFichas() == 0) {
            return true;
        }
    }
    return false;
}

int JuegoDomino::determinarGanador() {
    int ganadorIndice = 0;
    int menorPuntos = jugadores[0].sumaPuntos();
    
    for (size_t i = 1; i < jugadores.size(); i++) {
        int puntos = jugadores[i].sumaPuntos();
        if (puntos < menorPuntos) {
            menorPuntos = puntos;
            ganadorIndice = i;
        }
    }
    
    return ganadorIndice;
}

void JuegoDomino::mostrarEstadisticas() const {
    std::cout << "\nestadisticas\n";
    for (const auto& jugador : jugadores) {
        std::cout << jugador.getNombre() << ": " 
                  << jugador.getVictorias() << " victorias, "
                  << jugador.getNumFichas() << " fichas restantes, "
                  << jugador.sumaPuntos() << " puntos\n";
    }
}

void JuegoDomino::finalizarJuego() {
    int ganadorIndice = -1;
    
    if (juegoTerminado()) {
        for (size_t i = 0; i < jugadores.size(); i++) {
            if (jugadores[i].getNumFichas() == 0) {
                ganadorIndice = i;
                break;
            }
        }
    } else if (hayBloqueo()) {
        ganadorIndice = determinarGanador();
        std::cout << "\njuego bloqueado! ganador por menor puntos.\n";
    }
    
    if (ganadorIndice != -1) {
        jugadores[ganadorIndice].incrementarVictorias();
        std::cout << "\n*** " << jugadores[ganadorIndice].getNombre() 
                  << " gana esta ronda! ***\n";
    }
    
    mostrarEstadisticas();
    
    std::cout << "\nguardando historial de movimientos...\n";
    historial.guardarEnArchivo("historial_domino.txt");
    std::cout << "historial guardado en 'historial_domino.txt'\n";
    std::cout << "total de movimientos: " << historial.getNumMovimientos() << "\n";
}