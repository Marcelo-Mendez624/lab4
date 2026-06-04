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
    std::vector<Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();
    
    //getters
    const std::set<TipoLibreta>& getLibretas() const { return libretas; }
    const std::vector<Vehiculo*>& getVehiculos() const { return vehiculos; }

    void agregarVehiculoConductor(Vehiculo* nuevoVehiculo);

    bool tieneLibreta(TipoVehiculo tipo) const;

    DTUsuarioViaje getDTUsuarioViaje() override;

    std::vector<DTVehiculosConductor> listarVehiculos() const;

    bool hayViajesFechaConductor(DTFecha fecha) const;
    
};

#endif
