#include "../include/ControladorCalificacion.h"
#include "../include/ManejadorUsuario.h"


ControladorCalificacion* ControladorCalificacion::instancia = nullptr;

ControladorCalificacion* ControladorCalificacion::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorCalificacion();
    }
    return instancia;
}

ControladorCalificacion::ControladorCalificacion() {
}

ControladorCalificacion::~ControladorCalificacion() {
}

std::map<std::string, DTUsuario> ControladorCalificacion::listarUsuarios() {
    std::map<std::string, DTUsuario> usuarios;

    ManejadorUsuario* m = m->getInstance();
    std::map<std::string, Usuario*> us = m->getUsuarios();

    for (const auto& [str, u] : us)
    {
        DTUsuario dt = u->getDTUsuario();
        usuarios.insert_or_assign(str, dt);
    }

    return usuarios;
}

std::map<std::string, DTConsultaViaje> ControladorCalificacion::listarViajes(std::string nickname) {
    std::map<std::string, DTConsultaViaje> viajes;
    return viajes;
}

std::map<std::string, DTUsuarioViaje> ControladorCalificacion::listarUsuariosViaje(int codigo) {
    std::map<std::string, DTUsuarioViaje> usuariosViaje;
    return usuariosViaje;
}

bool ControladorCalificacion::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    return true;
}