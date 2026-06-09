#include "../include/ControladorReserva.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Usuario.h"
#include "../include/ManejadorViaje.h"

ControladorReserva* ControladorReserva::instance = nullptr;

ControladorReserva::ControladorReserva() {}

ControladorReserva* ControladorReserva::getInstance() {
    if (instance == nullptr) {
        instance = new ControladorReserva();
    }
    return instance;
}

std::list<std::string> ControladorReserva::listarPasajeros() {
    
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


// Checkear
std::set<DTConsultaViaje> ControladorReserva::consultarViajes(DTFecha fecha,std::string origen,std::string destino,int asientos) 
{
    ManejadorViaje* mv = ManejadorViaje::getInstance();
    std::map<int, Viaje*> setvi = mv->getViajes();
    std::set<DTConsultaViaje> dtcv;

    bool check = false, hayLugar = false;

    for (const auto& v : setvi) 
    {
        check = v.second->cumpleDatos(fecha, origen, destino);
        if (check)
        {
            hayLugar = v.second->consultarAsientos(asientos);
            if (hayLugar)
            {
                DTConsultaViaje dt = v.second->crearDTConsultaViaje();
                dtcv.insert(dt);
                //dtcv.insert(v.second->crearDTConsultaViaje());
            }
        }
    }

    return dtcv;
}

bool ControladorReserva::generarReserva (std::string nickname,int codigo,int asientos) 
{
    ManejadorViaje* mv = ManejadorViaje::getInstance();
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();

    Viaje* v = mv->obtenerViaje(codigo);

    int asientosViajes = v->getAsientosPublicados();

    Usuario* p = mu->obtenerUsuario(nickname); 
    class Pasajero* pasajero = dynamic_cast<class Pasajero*>(p);

    bool existeRel = v->relacion(pasajero);

    if (!existeRel && asientosViajes >= asientos) {
        Reserva* r = new Reserva(asientos, v->getFecha());

        r->asociarReservaPasajero(pasajero);
        v->asociarViajeReserva(r);
        pasajero->asociarPasajeroReserva(r);

        return true;
    }
    
    return false;
}
