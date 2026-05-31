#include "../include/Conductor.h"


Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {
    
}

void Conductor::agregarVehiculoConductor(Vehiculo nuevoVehiculo)
{
    vehiculos.push_back(nuevoVehiculo);
}

bool Conductor::tieneLibreta(TipoLibreta tipo) const 
{
    libretas.find(tipo);
    return libretas.find(tipo) != libretas.end();
}

DTUsuarioViaje Conductor::getDTUsuarioViaje()
{
    TipoUsuario Conductor;
    return DTUsuarioViaje(this->getNickname(), Conductor);
}

std::vector<DTVehiculosConductor> Conductor::listarVehiculos() const
{
    std::vector<DTVehiculosConductor> dtVehiculos;
    
    for (const auto& vehiculo : vehiculos) 
    {
        DTVehiculosConductor dtVehiculo(vehiculo.getMatricula(), vehiculo.getMarca(), vehiculo.getCapacidad());
        dtVehiculos.push_back(dtVehiculo);
    }
    return dtVehiculos;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha) const
{
    for (const auto& ve : vehiculos)
    {
        for (const auto& vi : ve.getViajes())
        {
            if (vi.getFecha() == fecha) 
                return true;
        }
    }
    return false;
}