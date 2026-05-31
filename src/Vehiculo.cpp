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

std::vector<Viaje> Vehiculo::getViajes() const { return this->viajes; }

std::vector<DTListarViaje> Vehiculo::listarViajes() {
    // Implementación para listar los viajes asociados al vehículo
    std::vector<DTListarViaje> resultado;
    for (const auto& viaje : viajes) {
        // Crear un objeto DTListarViajes para cada viaje y agregarlo al vector
        DTListarViaje DTListarViaje(viaje.getCodigo(), viaje.getFecha(), viaje.getOrigen(), viaje.getDestino(), conductor.getNickname());
        resultado.push_back(DTListarViaje);
    }
    return resultado;
}

std::string Vehiculo::getConductor() const {
    // Implementación para obtener el nombre del conductor asociado al vehículo
    return conductor.getNickname();
}

float Vehiculo::getCalifConductor() const {
    // Implementación para obtener la calificación promedio del conductor asociado al vehículo
    return conductor.getCalificacionPromedio();
}

DTUsuarioViaje Vehiculo::getNickConductor() {
    // Implementación para obtener el nickname del conductor asociado al vehículo
    return conductor.getDTUsuarioViaje();
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor() const {
    // Implementación para obtener un objeto DTVehiculosConductor con los detalles del vehículo y su conductor
    return DTVehiculosConductor(matricula, capacidad, marca, modelo, tipo, conductor.getNickname(), conductor.getCalificacionPromedio());
}

bool Vehiculo::hayViajesConductor(DTFecha fecha) {
    // Implementación para verificar si hay viajes asociados al conductor en una fecha específica
    for (const auto& viaje : viajes) {
        if (viaje.getFecha() == fecha) {
            return true;
        }
    }
    return false;
}

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
    // Implementación para verificar si hay viajes asociados al vehículo en una fecha específica
    for (const auto& viaje : viajes) {
        if (viaje.getFecha() == fecha) {
            return true;
        }
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje cvi) {
    // Implementación para asociar un viaje al vehículo
    viajes.push_back(cvi);
}
 
