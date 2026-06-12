#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) 
    : asientosReservados(asientosReservados), fecha(fecha), pasajero(nullptr), calificaciones() {}

Reserva::~Reserva() {}

void Reserva::setAsientosReservados(int a) {
    this->asientosReservados = a;
}

void Reserva::setFecha(DTFecha f) {
    this->fecha = f;
}

std::list<Calificacion*> Reserva::getCalificaciones() {
    return this->calificaciones;
}

int Reserva::getAsientosReservados() {
    return this->asientosReservados;
}

DTFecha Reserva::getfecha() {
    return this->fecha;
}

void Reserva::asociarReservaPasajero(Pasajero* p) {
    this->pasajero = p;
}

std::string Reserva::obtenerNickPasajero() {
    return this->pasajero->getNickname();
}

bool Reserva::igualUsuario(const Usuario* u) {
    return this->obtenerNickPasajero() == u->getNickname();
}

Pasajero* Reserva::getPasajero() {
    return this->pasajero;
}

bool Reserva::existeCal(Usuario* u, Usuario* u_calif) {
    for (auto const& c : this->calificaciones) {
        if (c->coicidenUsuario(u, u_calif))
            return true;
    }
    return false;
}

void Reserva::crearCalificacion(Usuario* u, Usuario* u_calif, int calificacion) {
    ControladorFechaActual* c = ControladorFechaActual::getInstance();
    DTFecha fecha = c->getFecha();
    Calificacion* cal = new Calificacion(fecha, calificacion);
    
    this->calificaciones.push_back(cal);
    
    cal->linkearCalifUsuario(u, u_calif);
    u_calif->asociarCalificacion(cal);
}

DTDetalleReserva Reserva::crearDTDetalleReserva() {
    return DTDetalleReserva(asientosReservados, fecha, pasajero->getNickname());
}

bool Reserva::relacionResPas(Pasajero* p) {
    return p->getNickname() == this->pasajero->getNickname();
}

void Reserva::eliminarCalificaciones() {
    for (auto const& c : this->calificaciones) {
        c->eliminarLinks();
        delete c;
    }
    this->calificaciones.clear();
}

void Reserva::eliminarLinkPasajero() {
    pasajero = nullptr;
}