#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "Viaje.h"
#include <map>
#include <string>

class ManejadorViaje{
private:
    static ManejadorViaje* instancia;
    std::map<std::string, Viaje*> viajes;
    ManejadorViaje();
public:
    void agregarViaje(Viaje* viaje);
    static ManejadorViaje* getInstance();
    std::map<std::string, Viaje*> getViajes();
    Viaje* obtenerViaje(int codigo);
    Viaje* crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~ManejadorViaje();
};
    
#endif
