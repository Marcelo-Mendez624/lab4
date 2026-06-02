#ifndef IELIMINARVIAJE_H
#define IELIMINARVIAJE_H

#include <list>
#include <string>
#include "DTDetalleViaje.h"

class IEliminarViaje
{
public:

  virtual std::list<std::string> listarViajes() = 0;
  virtual DTDetalleViaje DetalleViaje(int codigo) = 0;
  virtual bool eliminarViaje () = 0;
  virtual void cancelarEliminarViaje() = 0;

};
#endif