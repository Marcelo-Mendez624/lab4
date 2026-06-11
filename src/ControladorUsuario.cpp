#include "../include/ControladorUsuario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorVehiculo.h"

ControladorUsuario* ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario() 
{
    
}
ControladorUsuario* ControladorUsuario:: getInstance(){
  if (instancia==NULL)
    instancia = new ControladorUsuario();
  return instancia;
}



bool ControladorUsuario::AltaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) 
{
  ManejadorUsuario* m = ManejadorUsuario::getInstance();
  
  if (m->existeUsuario(nickname)) return false;

  else m->nuevoPasajero(nickname, nombre, contrasena, email, ci);
  return true;
}

bool ControladorUsuario::AltaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) 
{
  ManejadorUsuario* m = ManejadorUsuario::getInstance();
  
  if (m->existeUsuario(nickname)) return false;

  else m->nuevoConductor(nickname, nombre, contrasena, email, libretas);
  return true;
}

int ControladorUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) 
{
  ManejadorVehiculo* mv = ManejadorVehiculo::getInstance();
  ManejadorUsuario* mu = ManejadorUsuario::getInstance();
  if (mv->existeVeh(matricula)) return -1;

  Usuario* u = mu->obtenerUsuario(nickname);
  class Conductor* c = dynamic_cast<class Conductor*>(u);
  if (!(c->tieneLibreta(tipo))) return -2;
  
  Vehiculo* nv = mv->nuevoVehiculo(matricula, capacidad, marca, modelo, tipo);
  c->agregarVehiculoConductor(nv);
  nv->asociarConductor(c);

  return 0;
}