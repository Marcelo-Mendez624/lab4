#include "../include/Conductor.h"


Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {
    
}

void Conductor::agregarVehiculoConductor(Vehiculo* nuevoVehiculo)
{
    vehiculos.push_back(nuevoVehiculo);
}

bool Conductor::tieneLibreta(TipoVehiculo tipo) const 
{
    std::set<TipoLibreta>::const_iterator lib1, lib2;
    if (tipo == Auto)
    {
        lib1 = libretas.find(AutoAmateur);
        lib2 = libretas.find(AutoProfesional);
    }
    else
    {
        lib1 = libretas.find(MotoAmateur);
        lib2 = libretas.find(MotoProfesional);
    }
    return (lib1 != libretas.end() && lib2 != libretas.end());
}

DTUsuarioViaje Conductor::getDTUsuarioViaje()
{
    TipoUsuario aux = TipoUsuario::Conductor;
    return DTUsuarioViaje(this->getNickname(), aux);
}

std::vector<DTVehiculosConductor> Conductor::listarVehiculos() const
{
    std::vector<DTVehiculosConductor> dtVehiculos;
    
    for (const auto& vehiculo : vehiculos) 
    {
        DTVehiculosConductor dtVehiculo(vehiculo->getMatricula(), vehiculo->getMarca(), vehiculo->getCapacidad());
        dtVehiculos.push_back(dtVehiculo);
    }
    return dtVehiculos;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha) const
{
    for (const auto& ve : vehiculos)
    {
        for (const auto& vi : ve->getViajes())
        {
            if (vi->getFecha() == fecha) 
                return true;
        }
    }
    return false;
}