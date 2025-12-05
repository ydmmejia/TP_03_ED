#ifndef SENALECG_H
#define SENALECG_H

#include <string>
#include <vector>

class NodoECG {
public:
    double tiempo;
    double amplitud;
    double amplitudFiltrada;
    NodoECG* siguiente;
    NodoECG* anterior;
    
    NodoECG(double t, double amp) : tiempo(t), amplitud(amp), amplitudFiltrada(0.0), 
                                     siguiente(nullptr), anterior(nullptr) {}
};

class SenalECG {
private:
    NodoECG* cabeza;
    NodoECG* cola;
    int numMuestras;
    std::vector<double> picos;
    
    double aplicarFiltro(NodoECG* nodo);

public:
    SenalECG();
    ~SenalECG();
    
    void cargarDesdeArchivo(std::string nombreArchivo);
    void aplicarFiltroPasaBajos();
    void detectarPicos(double umbral);
    void imprimirSenal(std::string nombreArchivo) const;
    double calcularFrecuenciaCardiaca() const;
    
    int getNumMuestras() const;
    int getNumPicos() const;
};

#endif