#ifndef IAltaViaje_H
#define IAltaViaje_H
#include "DTVehiculosConductor.h"

class IAltaViaje
{
public:
  virtual std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname) = 0;
  virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino,  int asientos, float precio) = 0;
};

#endif 