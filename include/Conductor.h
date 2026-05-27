#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include <set>
#include "DTFecha.h"
#include "DTVehiculosConductor.h"

// Forward declaration Revisar
class vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();

    void agregarVehiculoConductor(vehiculo nuevoVehiculo);
    std::string getNombreConductor() const { return nombre; }
    float getCalificacionPromedio() const;
    bool tieneLibreta(TipoLibreta tipo) const;
    std::vector<DTVehiculosConductor> listarVehiculos() const;
    bool hayViajesFechaConductor(DTFecha fecha) const;
    
};

#endif
