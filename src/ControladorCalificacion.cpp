#include "../include/ControladorCalificacion.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorViaje.h"

ControladorCalificacion* ControladorCalificacion::instancia = nullptr;

ControladorCalificacion* ControladorCalificacion::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorCalificacion();
    }
    return instancia;
}

ControladorCalificacion::ControladorCalificacion() {}

ControladorCalificacion::~ControladorCalificacion() {}

std::map<std::string, DTUsuario> ControladorCalificacion::listarUsuarios() {
    std::map<std::string, DTUsuario> usuarios;
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    std::map<std::string, Usuario*> us = m->getUsuarios();

    for (const auto& [str, u] : us) {
        DTUsuario dt = u->getDTUsuario();
        usuarios.insert_or_assign(str, dt);
    }
    return usuarios;
}

std::vector<DTListarViaje> ControladorCalificacion::listarViajes(std::string nickname) {
    this->nickname = nickname;
    Usuario* mu = ManejadorUsuario::getInstance()->obtenerUsuario(nickname);
    return mu->getViajes();
}

std::map<std::string, DTUsuarioViaje> ControladorCalificacion::listarUsuariosViaje(int codigo) {
    this->codigoViaje = codigo;
    Viaje* vi = ManejadorViaje::getInstance()->obtenerViaje(codigo);

    std::vector<DTUsuarioViaje> op = vi->obtenerPasajeros(this->nickname);
    DTUsuarioViaje oc = vi->obtenerConductor();

    std::map<std::string, DTUsuarioViaje> resultado;
    for (const DTUsuarioViaje& dt : op) {
        resultado.insert({dt.getNickname(), dt});
    }
    
    if (oc.getNickname() != nickname)
        resultado.insert({oc.getNickname(), oc});

    return resultado;
}

bool ControladorCalificacion::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    ManejadorViaje* mv = ManejadorViaje::getInstance();
    
    Usuario* u_calif = mu->obtenerUsuario(nicknameCalificado);
    Usuario* u = mu->obtenerUsuario(this->nickname);
    Viaje* vi = mv->obtenerViaje(this->codigoViaje);

    if (!u_calif || !u || !vi) return false;

    if (!vi->coincideCalif(u, u_calif)) {
        Reserva* r = vi->obtenerReservaCalif(u, u_calif);
        if (r != nullptr) {
            r->crearCalificacion(u, u_calif, calificacion);
            this->nickname = "";
            this->codigoViaje = -1;
            return true;
        }
    }
    return false;
}