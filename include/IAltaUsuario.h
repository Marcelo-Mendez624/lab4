#ifndef IAltaUsuario_H
#define IAltaUsuario_H

#include <string>
#include <vector>
#include "Tipolibreta.h"
#include "TipoVehiculo.h"

class IAltaUsuario
{
public:
  virtual bool AltaPasajero(std::string nombre, std::string contrasena, std::string email, std::string ci) = 0;
  virtual bool AltaConductor(std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libretas) = 0;
  virtual int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, TipoVehiculo tipo) = 0;
};

#endif