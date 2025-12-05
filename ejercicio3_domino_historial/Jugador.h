#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Ficha.h"

class Jugador {
private:
    std::string nombre;
    std::vector<Ficha> fichas;
    int victorias;

public:
    Jugador(std::string nombre);
    
    std::string getNombre() const;
    int getVictorias() const;
    int getNumFichas() const;
    
    void agregarFicha(Ficha f);
    void removerFicha(int indice);
    Ficha getFicha(int indice) const;
    
    bool tieneFichasConectables(int extremoIzq, int extremoDer) const;
    int sumaPuntos() const;
    void incrementarVictorias();
    
    void mostrarFichas() const;
    void limpiarFichas();
};

#endif