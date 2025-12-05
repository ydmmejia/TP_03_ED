#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombreCompleto;
    int anoNacimiento;
    std::string numeroIdentificacion;
    double promedioAcademico;
    std::string email;

public:
    Estudiante();
    Estudiante(std::string nombre, int ano, std::string id, double promedio, std::string email);
    
    std::string getNombre() const;
    int getAno() const;
    std::string getId() const;
    double getPromedio() const;
    std::string getEmail() const;
    
    void setNombre(std::string nombre);
    void setAno(int ano);
    void setId(std::string id);
    void setPromedio(double promedio);
    void setEmail(std::string email);
    
    std::string toString() const;
};

#endif