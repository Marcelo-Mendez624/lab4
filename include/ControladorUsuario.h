#ifndef CONTROlADORUSUARIO_H
#define CONTROlADORUSUARIO_H

#include "IAltaUsuario.h"

class ControladorUsuario : public IAltaUsuario 
{
  private:
    static ControladorUsuario *instancia;
    ControladorUsuario();

  public:
    static ControladorUsuario* getInstance();
    bool AltaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) override;
    bool AltaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) override;
    int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) override;
    static void cleanUp();
};

#endif