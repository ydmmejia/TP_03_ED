#include "SenalECG.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iostream>

SenalECG::SenalECG() : cabeza(nullptr), cola(nullptr), numMuestras(0) {}

SenalECG::~SenalECG() {
    NodoECG* actual = cabeza;
    while (actual != nullptr) {
        NodoECG* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void SenalECG::cargarDesdeArchivo(std::string nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        throw std::runtime_error("no se pudo abrir el archivo");
    }
    
    std::string encabezado;
    std::getline(archivo, encabezado);
    
    double tiempo, amplitud;
    char coma; //variable auxiliar para leer la coma
    
    while (archivo >> amplitud >> coma >> tiempo) {
        NodoECG* nuevo = new NodoECG(tiempo, amplitud);
        
        if (cabeza == nullptr) {
            cabeza = cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
        numMuestras++;
    }
    
    archivo.close();
}

double SenalECG::aplicarFiltro(NodoECG* nodo) {
    // filtro pasa bajos simple: promedio movil de 5 puntos
    double suma = nodo->amplitud;
    int count = 1;
    
    NodoECG* temp = nodo->anterior;
    for (int i = 0; i < 2 && temp != nullptr; i++) {
        suma += temp->amplitud;
        count++;
        temp = temp->anterior;
    }
    
    temp = nodo->siguiente;
    for (int i = 0; i < 2 && temp != nullptr; i++) {
        suma += temp->amplitud;
        count++;
        temp = temp->siguiente;
    }
    
    return suma / count;
}

void SenalECG::aplicarFiltroPasaBajos() {
    NodoECG* actual = cabeza;
    
    while (actual != nullptr) {
        actual->amplitudFiltrada = aplicarFiltro(actual);
        actual = actual->siguiente;
    }
}

void SenalECG::detectarPicos(double umbral) {
    picos.clear();
    
    NodoECG* actual = cabeza;
    if (actual == nullptr || actual->siguiente == nullptr) return;
    
    actual = actual->siguiente;
    
    while (actual->siguiente != nullptr) {
        double valorActual = actual->amplitudFiltrada;
        double valorAnterior = actual->anterior->amplitudFiltrada;
        double valorSiguiente = actual->siguiente->amplitudFiltrada;
        
        if (valorActual > valorAnterior && valorActual > valorSiguiente && valorActual > umbral) {
            picos.push_back(actual->tiempo);
        }
        
        actual = actual->siguiente;
    }
}

void SenalECG::imprimirSenal(std::string nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        throw std::runtime_error("no se pudo abrir el archivo");
    }
    
    archivo << "tiempo\tamplitud_original\tamplitud_filtrada\n";
    
    NodoECG* actual = cabeza;
    while (actual != nullptr) {
        archivo << actual->tiempo << "\t" 
                << actual->amplitud << "\t" 
                << actual->amplitudFiltrada << "\n";
        actual = actual->siguiente;
    }
    
    archivo << "\npicos detectados:\n";
    for (size_t i = 0; i < picos.size(); i++) {
        archivo << "pico " << (i+1) << ": " << picos[i] << " segundos\n";
    }
    
    archivo << "\nfrecuencia cardiaca: " << calcularFrecuenciaCardiaca() << " bpm\n";
    
    archivo.close();
}

double SenalECG::calcularFrecuenciaCardiaca() const {
    if (picos.size() < 2) return 0.0;
    
    double tiempoTotal = picos[picos.size()-1] - picos[0];
    int numIntervalos = picos.size() - 1;
    
    if (tiempoTotal == 0) return 0.0;
    
    double intervaloPromedio = tiempoTotal / numIntervalos;
    double frecuencia = 60.0 / intervaloPromedio;
    
    return frecuencia;
}

int SenalECG::getNumMuestras() const {
    return numMuestras;
}

int SenalECG::getNumPicos() const {
    return picos.size();
}
