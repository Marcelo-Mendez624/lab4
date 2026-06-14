#include "../include/ManejadorViaje.h"

ManejadorViaje* ManejadorViaje::instancia = nullptr;
int ManejadorViaje::contadorCodigo = 1;

ManejadorViaje::ManejadorViaje() {
}

ManejadorViaje::~ManejadorViaje()
{
    instancia = nullptr;
}

ManejadorViaje* ManejadorViaje::getInstance(){
    if (instancia==nullptr){
        instancia = new ManejadorViaje();
    }
    return instancia;
}

void ManejadorViaje::agregarViaje(Viaje* viaje){
    viajes[viaje->getCodigo()] = viaje;
}

Viaje* ManejadorViaje::obtenerViaje(int codigo){
    if (viajes.find(codigo) != viajes.end()) {
        return viajes[codigo];
    }
    return nullptr;
}

std::map<int, Viaje*> ManejadorViaje::getViajes(){
    return viajes;
}

Viaje* ManejadorViaje::crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio){
    Viaje* nuevoViaje = new Viaje(v, fecha, origen, destino, asientosPublicados, precio);
    agregarViaje(nuevoViaje);
    return nuevoViaje;
}

void ManejadorViaje::eliminarViaje(Viaje* vi)
{
    viajes.erase(vi->getCodigo());
    delete vi;
}