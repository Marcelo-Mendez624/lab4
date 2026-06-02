#ifndef CTRLVEHICULO_H
#include "Vehiculo.h"

class ManejadorVehiculo {
private:
    static ManejadorVehiculo* inst;
    std::vector<Vehiculo*> vehiculos;

public:
    ManejadorVehiculo();
    static ManejadorVehiculo* getInstance();
    bool existeVeh(std::string matricula);
    Vehiculo* obtenerVeh(std::string matricula);
    Vehiculo* nuevoVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
};

#endif