#include "Jugador.h"
#include <iostream>

Jugador::Jugador(std::string nombre) : nombre(nombre), victorias(0) {}

std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getVictorias() const {
    return victorias;
}

int Jugador::getNumFichas() const {
    return fichas.size();
}

void Jugador::agregarFicha(Ficha f) {
    fichas.push_back(f);
}

void Jugador::removerFicha(int indice) {
    if (indice >= 0 && indice < fichas.size()) {
        fichas.erase(fichas.begin() + indice);
    }
}

Ficha Jugador::getFicha(int indice) const {
    return fichas[indice];
}

bool Jugador::tieneFichasConectables(int extremoIzq, int extremoDer) const {
    for (const auto& ficha : fichas) {
        if (ficha.puedeConectar(extremoIzq) || ficha.puedeConectar(extremoDer)) {
            return true;
        }
    }
    return false;
}

int Jugador::sumaPuntos() const {
    int total = 0;
    for (const auto& ficha : fichas) {
        total += ficha.suma();
    }
    return total;
}

void Jugador::incrementarVictorias() {
    victorias++;
}

void Jugador::mostrarFichas() const {
    std::cout << nombre << " - fichas (" << fichas.size() << "): ";
    for (size_t i = 0; i < fichas.size(); i++) {
        std::cout << i+1 << ".";
        fichas[i].imprimir();
        std::cout << " ";
    }
    std::cout << std::endl;
}

void Jugador::limpiarFichas() {
    fichas.clear();
}