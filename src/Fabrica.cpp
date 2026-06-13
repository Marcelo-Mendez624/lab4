#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorReserva.h"
#include "../include/ControladorCalificacion.h"
#include"../include/ControladorViaje.h"



Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IAltaUsuario *Fabrica::getIAltaUsuario() {
  return ControladorUsuario::getInstance();
}
IGenerarReserva* Fabrica:: getIGenerarReserva(){
  return ControladorReserva::getInstance();
}

ICalificarUsuario* Fabrica:: getICalificarUsuario(){
  return ControladorCalificacion::getInstance();
}
IAltaViaje* Fabrica::getIAltaViaje(){
  return ControladorViaje::getInstance();
}

IEliminarViaje* Fabrica::getIEliminarViaje(){
  return ControladorViaje::getInstance();
}

void Fabrica::cleanUp()
{
  ControladorFechaActual::cleanUp();
  ControladorViaje::cleanUp();
  ControladorCalificacion::cleanUp();
  ControladorReserva::cleanUp();
  ControladorUsuario::cleanUp();

  delete instancia;
  instancia = nullptr;
}