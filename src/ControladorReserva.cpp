#include "ControladorReserva.h"
#include "ManejadorUsuario.h"
#include "Usuario.h"

ControladorReserva* ControladorReserva::instance = nullptr;

ControladorReserva::ControladorReserva() {}

ControladorReserva* ControladorReserva::getInstance() {
    if (instance == nullptr) {
        instance = new ControladorReserva();
    }
    return instance;
}

std::list<std::string> ControladorReserva::listarUsuarios() {
    
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    std::map<std::string, Usuario*> us = mu->getUsuarios();
    std::list<std::string> res;
    for (const auto& u : us) {
        Usuario* user = u.second;
        class Pasajero* pasajero = dynamic_cast<class Pasajero*>(user);
        if (pasajero != nullptr) {
            std::string nick = user->getNickname();
            res.push_back(nick);
        }
    }
    return res;
}
