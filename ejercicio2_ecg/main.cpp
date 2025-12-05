#include <iostream>
#include "SenalECG.h"

using namespace std;

int main() {
    cout << "ejercicio 2: procesamiento de senal ecg\n\n";
    
    SenalECG senal;
    
    try {
        cout << "cargando senal desde archivo ECG.txt...\n";
        senal.cargarDesdeArchivo("ECG.txt");
        cout << "senal cargada exitosamente\n";
        cout << "numero de muestras: " << senal.getNumMuestras() << "\n\n";
        
        cout << "aplicando filtro pasa bajos...\n";
        senal.aplicarFiltroPasaBajos();
        cout << "filtro aplicado\n\n";
        
        cout << "detectando picos en la senal filtrada...\n";
        double umbral = 50.0;
        senal.detectarPicos(umbral);
        cout << "picos detectados: " << senal.getNumPicos() << "\n\n";
        
        cout << "calculando frecuencia cardiaca...\n";
        double frecuencia = senal.calcularFrecuenciaCardiaca();
        cout << "frecuencia cardiaca promedio: " << frecuencia << " bpm\n\n";
        
        cout << "guardando resultados en archivo...\n";
        senal.imprimirSenal("senal_procesada.txt");
        cout << "archivo 'senal_procesada.txt' creado exitosamente\n";
        
    } catch (const exception& e) {
        cerr << "error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}