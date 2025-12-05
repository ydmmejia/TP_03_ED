#include "Estudiante.h"
#include <sstream>

Estudiante::Estudiante() : anoNacimiento(0), promedioAcademico(0.0) {}

Estudiante::Estudiante(std::string nombre, int ano, std::string id, double promedio, std::string email)
    : nombreCompleto(nombre), anoNacimiento(ano), numeroIdentificacion(id), 
      promedioAcademico(promedio), email(email) {}

std::string Estudiante::getNombre() const { return nombreCompleto; }
int Estudiante::getAno() const { return anoNacimiento; }
std::string Estudiante::getId() const { return numeroIdentificacion; }
double Estudiante::getPromedio() const { return promedioAcademico; }
std::string Estudiante::getEmail() const { return email; }

void Estudiante::setNombre(std::string nombre) { nombreCompleto = nombre; }
void Estudiante::setAno(int ano) { anoNacimiento = ano; }
void Estudiante::setId(std::string id) { numeroIdentificacion = id; }
void Estudiante::setPromedio(double promedio) { promedioAcademico = promedio; }
void Estudiante::setEmail(std::string e) { email = e; }

std::string Estudiante::toString() const {
    std::stringstream ss;
    ss << "nombre: " << nombreCompleto << "\n"
       << "ano nacimiento: " << anoNacimiento << "\n"
       << "id: " << numeroIdentificacion << "\n"
       << "promedio: " << promedioAcademico << "\n"
       << "email: " << email;
    return ss.str();
}