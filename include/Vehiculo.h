#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include <vector>
#include DtListarViajes.h
#include DtUsuarioViaje.h
#include DTFecha.h


class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    std::vector<Viaje> viajes; // Vector para almacenar los viajes asociados al vehículo
    Conductor conductor; // Asociación con el conductor del vehículo

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    
    //Getters
    int getCapacidad() const;
    std::string getMatricula() const;
    std::string getModelo() const;
    std::string getMarca() const;
    TipoVehiculo getTipo() const;

    std::vector<DTListarViajes> listarViajes(); 
    std::string getConductor() const;
    float getCalifConductor() const;
    DTUsuarioViaje getNickConductor() const;
    DTVehiculosConductor getDTVehiculoConductor() const;
    bool hayViajesConductor(fecha:DTFecha);
    bool hayViajesFecha(fecha:DTFecha);
    void asociarViaje(cvi:Viaje);
};

#endif
