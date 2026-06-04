#ifndef CONTROlADORRESERVA_H
#define CONTROlADORRESERVA_H

#include "IGenerarReserva.h"
#include "DTConsultaViaje.h"
#include <string>
#include <list>
#include <set>


class ControladorReserva : public IGenerarReserva 
{
  private:
    static ControladorReserva *instance;
    ControladorReserva();

  public:
    static ControladorReserva *getInstance();
    std::list<std::string> listarPasajeros() ;
    std::set<DTConsultaViaje> consultarViajes(DTFecha fecha,std::string origen,std::string destino,int asientos);
    bool generarReserva (std::string nickname,int codigo,int asientos) ;
};

#endif
