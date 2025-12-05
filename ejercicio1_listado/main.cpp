#include <iostream>
#include "ListadoEstudiantil.h"

using namespace std;

int main() {
    cout << "ejercicio 1: listado estudiantil\n\n";
    
    ListadoEstudiantil listado;
    
    listado.insertar(Estudiante("juan perez", 2000, "1001", 4.2, "juan@email.com"));
    listado.insertar(Estudiante("maria garcia", 1999, "1002", 4.5, "maria@email.com"));
    listado.insertar(Estudiante("carlos lopez", 2001, "1003", 3.8, "carlos@email.com"));
    listado.insertar(Estudiante("ana rodriguez", 2000, "1004", 4.0, "ana@email.com"));
    listado.insertar(Estudiante("luis martinez", 1998, "1005", 3.9, "luis@email.com"));
    
    cout << "total de estudiantes: " << listado.getTamano() << "\n\n";
    
    cout << "buscando estudiante con id 1003...\n";
    int pos = listado.buscar("1003");
    if (pos != -1) {
        cout << "encontrado en posicion: " << pos << "\n";
        cout << listado[pos].toString() << "\n\n";
    }
    
    cout << "accediendo al estudiante en posicion 1:\n";
    cout << listado[1].toString() << "\n\n";
    
    cout << "eliminando estudiante con id 1002...\n";
    if (listado.eliminar("1002")) {
        cout << "estudiante eliminado\n";
        cout << "total de estudiantes: " << listado.getTamano() << "\n\n";
    }
    
    cout << "invirtiendo lista...\n";
    listado.invertir();
    cout << "lista invertida\n\n";
    
    cout << "primer estudiante despues de invertir:\n";
    cout << listado[0].toString() << "\n\n";
    
    cout << "guardando listado en archivo...\n";
    listado.imprimir("listado_estudiantes.txt");
    cout << "archivo 'listado_estudiantes.txt' creado exitosamente\n";
    
    return 0;
}