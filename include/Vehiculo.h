#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include <vector>
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "DTFecha.h"
#include "Conductor.h"
#include "Viaje.h"


class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    std::vector<Viaje*> viajes; // Vector para almacenar los viajes asociados al vehículo
    class Conductor* conductor; // Asociación con el conductor del vehículo

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    
    //Getters
    int getCapacidad() const;
    std::string getMatricula() const;
    std::string getModelo() const;
    std::string getMarca() const;
    TipoVehiculo getTipo() const;
    std::vector<Viaje*> getViajes() const;

    std::vector<DTListarViaje> listarViajes(); 
    std::string getConductor() const;
    float getCalifConductor() const;
    std::string getNickConductor();
    DTVehiculosConductor getDTVehiculoConductor() const;
    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
    void asociarViaje(Viaje* cvi);
};

#endif
