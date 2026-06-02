#include "../include/ManejadorVehiculo.h"

ManejadorVehiculo* ManejadorVehiculo::inst = NULL;

ManejadorVehiculo::ManejadorVehiculo()
{   
}

ManejadorVehiculo* ManejadorVehiculo::getInstance()
{
    if (inst == NULL)
        inst = new ManejadorVehiculo;
    return inst;
}

bool ManejadorVehiculo::existeVeh(std::string matricula)
{
    for(const auto& v : vehiculos)
        if (v->getMatricula() == matricula)
            return true;
    return false;
}

Vehiculo* ManejadorVehiculo::obtenerVeh(std::string matricula)
{
    for(const auto& v : vehiculos)
        if (v->getMatricula() == matricula)
            return v;
}

Vehiculo* ManejadorVehiculo::nuevoVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo)
{
    Vehiculo* res = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
    vehiculos.push_back(res);

    return res;
}