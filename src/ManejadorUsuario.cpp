#include "ManejadorUsuario.h"

ManejadorUsuario *ManejadorUsuario::getInstance()
{
  if (instancia=NULL){
    instancia = new ManejadorUsuario();
  }
    return instancia;
}

void ManejadorUsuario::agregarUsuario(Usuario *u){
  this->usuarios.insert({u->getNickname(), u});
}

Usuario* ManejadorUsuario:: obtenerUsuario(std::string nick){
  auto it = usuarios.find(nick);
  return it->second;
}

bool ManejadorUsuario:: existeUsuario(std::string nick){
  auto it = usuarios.find(nick);
  if (it==usuarios.end())
    return false;
  return true;
}

std::map<std::string, Usuario *> ManejadorUsuario:: getUsuarios(){
  return usuarios;
}

void ManejadorUsuario:: nuevoPasajero(std::string nick, std::string nombre, std::string contrasena, std::string email, std::string ci){
  class Pasajero* p = new class Pasajero(nick, nombre, contrasena, email, ci);
}

void ManejadorUsuario::nuevoConductor(std::string nick, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas){

  class Conductor *c = new class Conductor(nick, nombre, contrasena, email, libretas);
}

