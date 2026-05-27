#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>

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
    std::string getMarca();
    TipoVehiculo getTipo();
    int getCapacidad();

    
    std::string getConductor();
    float getCalifConductor();
    DTUsuarioViaje getNickConductor()
    std::vector<DTListarViajes> listarViajes(); 
};

#endif
