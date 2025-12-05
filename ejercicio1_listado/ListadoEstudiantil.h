#ifndef LISTADOESTUDIANTIL_H
#define LISTADOESTUDIANTIL_H

#include "Estudiante.h"
#include <string>

class Nodo {
public:
    Estudiante datos;
    Nodo* siguiente;
    
    Nodo(Estudiante est) : datos(est), siguiente(nullptr) {}
};

class ListadoEstudiantil {
private:
    Nodo* cabeza;
    int tamano;

public:
    ListadoEstudiantil();
    ~ListadoEstudiantil();
    
    void insertar(Estudiante est);
    bool eliminar(std::string id);
    int buscar(std::string id) const;
    void imprimir(std::string nombreArchivo) const;
    void invertir();
    
    Estudiante& operator[](int indice);
    const Estudiante& operator[](int indice) const;
    
    int getTamano() const;
    bool estaVacia() const;
};

#endif