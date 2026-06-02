#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "Viaje.h"
#include <map>
#include <string>

class ManejadorViaje{
private:
    static ManejadorViaje* instancia;
    std :map<std::string, Viaje*> viajes;
    ManejadorViaje();
public:
    agregarViaje(Viaje* viaje);
    static ManejadorViaje* getInstance();
    std :map<std::string, Viaje*> getViajes();
    Viaje* obtenerViaje(int codigo);
    ~ManejadorViaje();
};
    
#endif