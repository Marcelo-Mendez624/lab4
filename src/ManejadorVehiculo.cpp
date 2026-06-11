#include "../include/ManejadorVehiculo.h"

ManejadorVehiculo* ManejadorVehiculo::inst = nullptr;

ManejadorVehiculo::ManejadorVehiculo()
{   
}

ManejadorVehiculo* ManejadorVehiculo::getInstance()
{
    if (inst == nullptr)
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
    std::vector<Vehiculo*> setVeh = this->vehiculos;
    for(const auto& v : setVeh)
    {
        printf("ENTRÉ AL FOR DE OBTENERVEH\n");
    
        if (v->getMatricula() == matricula)
            return v;
    }
    return nullptr;
}

Vehiculo* ManejadorVehiculo::nuevoVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo)
{
    Vehiculo* res = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
    vehiculos.push_back(res);

    return res;
}