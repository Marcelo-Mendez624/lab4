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
    setCalificacionProm(((this->getCalificacionProm() * calificaciones.size()) + calificacion->getPuntaje()) / (calificaciones.size() + 1));
    calificaciones.push_back(calificacion);
}

DTUsuario Usuario::getDTUsuario() const
{
    return DTUsuario(nickname, nombre);
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

void Usuario::eliminarLinkCalificacion(Calificacion* c)
{
    std::vector<Calificacion*>::iterator it = calificaciones.begin();
    while ((*it) != c)
        it++;
    calificaciones.erase(it);
    if (calificaciones.size() == 0)
        setCalificacionProm(0);
    else
        setCalificacionProm((this->getCalificacionProm() * (calificaciones.size() + 1)) - c->getPuntaje() / calificaciones.size());
}

void Usuario::setCalificacionProm(float calprom){

  this->calificacionProm = calprom;
}