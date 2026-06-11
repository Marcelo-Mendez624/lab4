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

std::vector<DTListarViaje> ControladorCalificacion::listarViajes(std::string nickname) {
    
    this->nickname = nickname;
    Usuario* mu =  ManejadorUsuario::getInstance()->obtenerUsuario(nickname);
    std::vector<DTListarViaje> res = mu->getViajes();

    return res;
}


std::map<std::string, DTUsuarioViaje> ControladorCalificacion::listarUsuariosViaje(int codigo) {
    
    this->codigoViaje = codigo;
    
    ManejadorViaje* mv =  mv->getInstance();
    Viaje* vi =  mv->obtenerViaje(codigo);

    std::vector<DTUsuarioViaje> op = vi->obtenerPasajeros(this->nickname);
    DTUsuarioViaje oc = vi->obtenerConductor();

    std::map<std::string, DTUsuarioViaje> resultado;
    //resultado.insert(op.begin(), op.end());
    for (const DTUsuarioViaje& dt : op) {
    resultado.insert({dt.getNickname(), dt});
    }
    
    if (oc.getNickname() != nickname)
        resultado.insert({oc.getNickname(), oc});

    return resultado;
}

bool ControladorCalificacion::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    
    ManejadorUsuario* mu = mu->getInstance();
    ManejadorViaje* mv =  mv->getInstance();
    
    Usuario* obtenerUsuario = mu->obtenerUsuario(nicknameCalificado);
    Usuario* u = mu->obtenerUsuario(this->nickname);

    Viaje* vi = mv->obtenerViaje(this->codigoViaje);

    bool coincide = vi->coincideCalif(u, obtenerUsuario);

    if(!coincide){
        Reserva* r = vi->obtenerReservaCalif(u, obtenerUsuario);
        r->crearCalificacion(u, obtenerUsuario, calificacion);

        //no estoy seguro si se hace asi eliminar el nickname recodado y codigo recordado, pero asi intuyo o seria coherente
        this->nickname = "";
        this->codigoViaje = -1; 
        return true;
    } else {
        return false;
    }
}
