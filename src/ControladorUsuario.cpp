#include "../include/ControladorUsuario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Conductor.h"

ControladorUsuario::ControladorUsuario() 
{
    
}

ControladorUsuario::~ControladorUsuario() 
{
    
}

bool ControladorUsuario::AltaPasajero(std::string nombre, std::string contrasena, std::string email, std::string ci) 
{
    ManejadorUsuario* manejador = ManejadorUsuario::getInstance();
    
    if(manejador->existeUsuario(nombre)) 
    {
        return false; 
    }

    manejador->nuevoPasajero(nombre, nombre, contrasena, email, ci);

    return true; // Retorna true si el alta fue exitosa, false en caso contrario
}

bool ControladorUsuario::AltaConductor(std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libretas) 
{
    ManejadorUsuario* manejador = ManejadorUsuario::getInstance();
    if(manejador->existeUsuario(nombre)) 
    {
        return false; 
    }

    manejador->nuevoConductor(nombre, nombre, contrasena, email, std::set<TipoLibreta>(libretas.begin(), libretas.end()));
    return true; // Retorna true si el alta fue exitosa, false en caso contrario
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, TipoVehiculo tipo) 
{
    ManejadorUsuario* manejador = ManejadorUsuario::getInstance();
    
        class Conductor* conductor = dynamic_cast<class Conductor*>(manejador->obtenerUsuario(nickname));

        /*
        if(conductor.tieneLibreta(TipoVehiculo))
        {

        }
        */
        
        // Aquí se debería agregar la lógica para registrar el vehículo al conductor
    return 0; // Retorna un identificador único para el vehículo registrado
}