#ifndef ICONTROLADORRESERVA_H
#define ICONTROLADORRESERVA_H
#include <list>
#include <set>
#include <string>
#include "DTConsultaViaje.h"

class IControladorReserva
{
public:

  virtual std::list<std::string> listarUsuarios() = 0;
  virtual std::set<DTConsultaViaje> consultarViajes(DTFecha fecha,std::string origen,std::string destino,int asientos) = 0;
  virtual bool generarReserva (std::string nickname,int codigo,int asientos) = 0;

};
#endif