#ifndef ICalificarUsuario_H
#define ICalificarUsuario_H

#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"
#include <string>
#include <map>

class ICalificarUsuario
{
public:
  virtual std::map<std::string, DTUsuario> listarUsuarios() = 0;
  virtual std::vector<DTListarViaje> listarViajes(std::string nickname) = 0;
  virtual std::map<std::string, DTUsuarioViaje> listarUsuariosViaje(int codigoViaje) = 0;
  virtual bool calificarUsuario(std::string nickname, int calificacion) = 0;
};

#endif
