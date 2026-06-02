#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H
#include <map>
#include "Usuario.h"
#include "Pasajero.h"
#include "Conductor.h"
#include "TipoLibreta.h"



class ManejadorUsuario {
private:
    static ManejadorUsuario* instancia;
    std::map<std::string, Usuario*> usuarios; // Mapa de nickname a Usuario*
    ManejadorUsuario();
public:
  static ManejadorUsuario *getInstance();
  void agregarUsuario(Usuario *u);
  bool existeUsuario(std::string nick);
  std::map<std::string, Usuario *> getUsuarios();
  void nuevoPasajero(std::string nick, std::string nombre, std::string contrasena, std::string email, std::string ci);
  void nuevoConductor(std::string nick, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas);
  Usuario *obtenerUsuario(std::string nick);
};
#endif


