#ifndef CONTROlADORUSUARIO_H
#define CONTROlADORUSUARIO_H

#include "IAltaUsuario.h"

class ControladorUsuario : public IAltaUsuario 
{
public:
    ControladorUsuario();
    ~ControladorUsuario();

    bool AltaPasajero(std::string nombre, std::string contrasena, std::string email, std::string ci) override;
    bool AltaConductor(std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libretas) override;
    int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, TipoVehiculo tipo) override;
};

#endif