#include "../include/Vehiculo.h"
#include "../include/Viaje.h"
#include "../include/Vehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

Vehiculo::~Vehiculo() {}

int Vehiculo::getCapacidad() const {
    return this->capacidad;
}

std::string Vehiculo::getMatricula() const {
    return this->matricula;
}

std::string Vehiculo::getModelo() const {
    return this->modelo;
}

std::string Vehiculo::getMarca() const{
    return this->marca;
} 

TipoVehiculo Vehiculo::getTipo() const{
    return this->tipo;
} 

std::map<int, Viaje*> Vehiculo::getViajes() const { return this->viajes; }

std::vector<DTListarViaje> Vehiculo::listarViajes() {
    std::vector<DTListarViaje> resultado;
    for (const auto& [id, viaje] : viajes) {
        // Crear un objeto DTListarViajes para cada viaje y agregarlo al vector
        DTListarViaje DTListarViaje(viaje->getCodigo(), viaje->getFecha(), viaje->getOrigen(), viaje->getDestino(), conductor->getNickname());
        resultado.push_back(DTListarViaje);
    }
    return resultado;
}

std::string Vehiculo::getConductor() const {
    return conductor->getNombre();
}

float Vehiculo::getCalifConductor() const {
    return conductor->getCalificacionProm();
}

std::string Vehiculo::getNickConductor() {
    return conductor->getDTUsuarioViaje().getNickname();
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor() const {
    return DTVehiculosConductor(matricula, modelo, capacidad);
}

DTDetalleVehiculo Vehiculo::crearDTDetalleVehiculo()
{
    return DTDetalleVehiculo(matricula, capacidad, marca, modelo, tipo);
}

bool Vehiculo::hayViajesConductor(DTFecha fecha) {
    for (const auto& [id, viaje] : viajes) {
        if (viaje->getFecha() == fecha) {
            return true;
        }
    }
    return false;
}

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
    for (const auto& [id, viaje] : viajes) {
        if (viaje->getFecha() == fecha) {
            return true;
        }
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje* cvi) {
    viajes[cvi->getCodigo()] = cvi;
}

void Vehiculo::asociarConductor(Conductor *c)
{
    this->conductor = c;
}

void Vehiculo::eliminarLinkViaje(int codigo)
{
    viajes.erase(codigo);
}