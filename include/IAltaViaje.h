#ifndef IAltaViaje_H
#define IAltaViaje_H
#include "DTVehiculosConductor.h"
class IAltaViaje
{
public:
  virtual DTVehiculosConductor listarVehiculos(std::string nickname) = 0;
  virtual bool altaViaje(std::string matricula, std::string fecha, std::string origen, std::string destino,  int asientos, float precio) = 0;
};

#endif 