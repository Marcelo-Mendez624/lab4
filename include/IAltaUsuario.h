#ifndef IAltaUsuario_H
#define IAltaUsuario_H

#include <string>
#include <vector>
#include "TipoLibreta.h"
#include "TipoVehiculo.h"

class IAltaUsuario
{
public:
  virtual bool AltaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) = 0;
  virtual bool AltaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) = 0;
  virtual int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) = 0;
};

#endif