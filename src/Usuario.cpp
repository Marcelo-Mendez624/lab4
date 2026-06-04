#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

Usuario::~Usuario() {}


void Usuario::asociarCalificacion(Calificacion* calificacion) 
{
    calificaciones.push_back(calificacion);
}

DTUsuario Usuario::getDTUsuario() const
{
    return DTUsuario(nickname, nombre);
}

std::string Usuario::getNickname() const { return this->nickname; }

float Usuario::getCalificacionPromedio() const
{
    float calificacionTotal = 0;
    for (const Calificacion* calificacion : calificaciones) 
    {
        calificacionTotal += calificacion->getPuntaje();
    }
    return calificacionTotal / calificaciones.size();
}

std::vector<DTListarViaje> Usuario::getViajes() const
{
    return viajes; //FALTA IMPLEMENTAR LA LOGICA, IMPORTANTE
}
