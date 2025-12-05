#include "ListadoEstudiantil.h"
#include <fstream>
#include <stdexcept>

ListadoEstudiantil::ListadoEstudiantil() : cabeza(nullptr), tamano(0) {}

ListadoEstudiantil::~ListadoEstudiantil() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListadoEstudiantil::insertar(Estudiante est) {
    Nodo* nuevo = new Nodo(est);
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    tamano++;
}

bool ListadoEstudiantil::eliminar(std::string id) {
    if (cabeza == nullptr) return false;
    
    if (cabeza->datos.getId() == id) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        tamano--;
        return true;
    }
    
    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr) {
        if (actual->siguiente->datos.getId() == id) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
            tamano--;
            return true;
        }
        actual = actual->siguiente;
    }
    
    return false;
}

int ListadoEstudiantil::buscar(std::string id) const {
    Nodo* actual = cabeza;
    int posicion = 0;
    
    while (actual != nullptr) {
        if (actual->datos.getId() == id) {
            return posicion;
        }
        actual = actual->siguiente;
        posicion++;
    }
    
    return -1;
}

void ListadoEstudiantil::imprimir(std::string nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        throw std::runtime_error("no se pudo abrir el archivo");
    }
    
    archivo << "listado estudiantil\n";
    archivo << "total de estudiantes: " << tamano << "\n\n";
    
    Nodo* actual = cabeza;
    int contador = 1;
    
    while (actual != nullptr) {
        archivo << "estudiante " << contador << ":\n";
        archivo << actual->datos.toString() << "\n\n";
        actual = actual->siguiente;
        contador++;
    }
    
    archivo.close();
}

void ListadoEstudiantil::invertir() {
    Nodo* anterior = nullptr;
    Nodo* actual = cabeza;
    Nodo* siguiente = nullptr;
    
    while (actual != nullptr) {
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }
    
    cabeza = anterior;
}

Estudiante& ListadoEstudiantil::operator[](int indice) {
    if (indice < 0 || indice >= tamano) {
        throw std::out_of_range("indice fuera de rango");
    }
    
    Nodo* actual = cabeza;
    for (int i = 0; i < indice; i++) {
        actual = actual->siguiente;
    }
    
    return actual->datos;
}

const Estudiante& ListadoEstudiantil::operator[](int indice) const {
    if (indice < 0 || indice >= tamano) {
        throw std::out_of_range("indice fuera de rango");
    }
    
    Nodo* actual = cabeza;
    for (int i = 0; i < indice; i++) {
        actual = actual->siguiente;
    }
    
    return actual->datos;
}

int ListadoEstudiantil::getTamano() const {
    return tamano;
}

bool ListadoEstudiantil::estaVacia() const {
    return cabeza == nullptr;
}