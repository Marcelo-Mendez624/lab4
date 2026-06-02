#include "ControladorCalificacion.h"


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

bool ControladorCalificacion::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    if 
    return true;
}

std::map<std::string, DTUsuario> ControladorCalificacion::listarUsuarios() {
    std::map<std::string, DTUsuario> usuarios;
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
