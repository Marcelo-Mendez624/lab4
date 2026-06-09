#include "../include/Usuario.h"
#include "../include/ManejadorViaje.h"

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

float Usuario::getCalificacionPromedio() const
{
    float calificacionTotal = 0;
    for (const Calificacion* calificacion : calificaciones) 
    {
        calificacionTotal += calificacion->getPuntaje();
    }
    return calificacionTotal / calificaciones.size();
}

std::vector<DTListarViaje> Usuario::getViajes() const {
    std::vector<DTListarViaje> viajes;
    
    const class Conductor* conductor = dynamic_cast<const class Conductor*>(this);

    if (conductor != nullptr) {
        
        for (Vehiculo* v : conductor->getVehiculos()) {
            std::vector<DTListarViaje> listarViajes = v->listarViajes();
            viajes.insert(viajes.end(), listarViajes.begin(), listarViajes.end());
        }
    } else {
        const class Pasajero* pasajero = dynamic_cast<const class Pasajero*>(this);
        ManejadorViaje* mv = ManejadorViaje::getInstance();
        std::map<int, Viaje*> setvi = mv->getViajes();
        for (const auto& vi : setvi) {
            std::vector<DTListarViaje> crearDTViajes = vi.second->crearDTViajes(pasajero);
            viajes.insert(viajes.end(), crearDTViajes.begin(), crearDTViajes.end());
        } 
    }
    return viajes;
}
