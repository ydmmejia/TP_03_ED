#ifndef FICHA_H
#define FICHA_H

#include <iostream>
#include <string>

class Ficha {
private:
    int lado1;
    int lado2;

public:
    Ficha(int lado1 = 0, int lado2 = 0);
    
    int getLado1() const;
    int getLado2() const;
    
    bool esDoble() const;
    int suma() const;
    bool puedeConectar(int valor) const;
    void voltear();
    
    void imprimir() const;
    std::string toString() const;
};

#endif