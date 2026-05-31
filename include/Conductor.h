#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include <set>
#include "DTFecha.h"
#include "DTVehiculosConductor.h"
#include "Vehiculo.h"



class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::vector<Vehiculo> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();

    void agregarVehiculoConductor(Vehiculo nuevoVehiculo);

    std::string getNombreConductor() const { return nombre; }

    bool tieneLibreta(TipoLibreta tipo) const;

    DTUsuarioViaje getDTUsuarioViaje() override;

    std::vector<DTVehiculosConductor> listarVehiculos() const;

    bool hayViajesFechaConductor(DTFecha fecha) const;
    
};

#endif
