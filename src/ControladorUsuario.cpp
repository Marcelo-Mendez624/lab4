#include "../include/ControladorUsuario.h"
ControladorUsuario::ControladorUsuario() 
{
    
}

ControladorUsuario::~ControladorUsuario() 
{
    
}

bool ControladorUsuario::AltaPasajero(std::string nombre, std::string contrasena, std::string email, std::string ci) 
{
    // Implementación de la lógica para dar de alta a un pasajero
    return true; // Retorna true si el alta fue exitosa, false en caso contrario
}

bool ControladorUsuario::AltaConductor(std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libretas) 
{
    // Implementación de la lógica para dar de alta a un conductor
    return true; // Retorna true si el alta fue exitosa, false en caso contrario
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, TipoVehiculo tipo) 
{
    // Implementación de la lógica para registrar un vehículo
    return 0; // Retorna un identificador único para el vehículo registrado
}