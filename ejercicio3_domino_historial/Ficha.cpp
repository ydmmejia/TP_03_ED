#include "Ficha.h"
#include <sstream>

Ficha::Ficha(int lado1, int lado2) : lado1(lado1), lado2(lado2) {}

int Ficha::getLado1() const {
    return lado1;
}

int Ficha::getLado2() const {
    return lado2;
}

bool Ficha::esDoble() const {
    return lado1 == lado2;
}

int Ficha::suma() const {
    return lado1 + lado2;
}

bool Ficha::puedeConectar(int valor) const {
    return lado1 == valor || lado2 == valor;
}

void Ficha::voltear() {
    int temp = lado1;
    lado1 = lado2;
    lado2 = temp;
}

void Ficha::imprimir() const {
    std::cout << "[" << lado1 << "|" << lado2 << "]";
}

std::string Ficha::toString() const {
    std::stringstream ss;
    ss << "[" << lado1 << "|" << lado2 << "]";
    return ss.str();
}