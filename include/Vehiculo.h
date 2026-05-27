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

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    
    //getters
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    TipoVehiculo getTipo();

    std::vector<DTListarViajes> listarViajes(); 
    std::string getConductor();
    float getCalifConductor();
    DTUsuarioViaje getNickConductor();
    DTVehiculosConductor getDTVehiculoConductor();
    bool hayViajesConductor(fecha:DTFecha);
    bool hayViajesFecha(fecha:DTFecha);
    void asociarViaje(cvi:Viaje);
};

#endif

