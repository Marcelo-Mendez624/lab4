#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "Viaje.h"
#include <map>
#include <string>

class ManejadorViaje{
private:
    static ManejadorViaje* instancia;
    std::map<int, Viaje*> viajes;
    ManejadorViaje();
     
public:
    static int contadorCodigo;


    void agregarViaje(Viaje* viaje);
    static ManejadorViaje* getInstance();
    std::map<int, Viaje*> getViajes();
    Viaje* obtenerViaje(int codigo);
    Viaje* crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~ManejadorViaje();
};
    
#endif
