#ifndef ICalificarUsuario_H
#define ICalificarUsuario_H

#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"

class ICalificarUsuario
{
public:
  virtual DTUsuario listarUsuarios() = 0;
  virtual DTConsultaViaje listarViajes() = 0;
  virtual DTUsuarioViaje listarViajesUsuario(int codigoViaje) = 0;
  virtual bool calificarUsuario(std::string nickname, int calificacion) = 0;
};

#endif
