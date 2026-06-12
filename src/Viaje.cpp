#include "../include/Viaje.h"
#include "../include/ManejadorViaje.h"

Viaje::Viaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = ManejadorViaje::contadorCodigo++;    
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->veh = v;
}

Viaje::~Viaje() {}

float Viaje::getPrecio() const { return this->precio; }

int Viaje::getAsientosPublicados() const { return this->asientosPublicados; }

int Viaje::getCodigo() const { return this->codigo; }

DTFecha Viaje::getFecha() const { return this->fecha; }

std::string Viaje::getOrigen() const { return this->origen; }

std::string Viaje::getDestino() const { return this->destino; }

Vehiculo* Viaje::getVehiculo() const { return this->veh; }

std::vector<Reserva*> Viaje::getReservas() { return this->reservas; }

bool Viaje::cumpleDatos(DTFecha fecha, std::string origen, std::string destino) {
    return (fecha == this->fecha && origen == this->origen && destino == this->destino);
}

bool Viaje::consultarAsientos(int asientos) {
    return (totalAsientosRes() + asientos) <= this->asientosPublicados;
}

DTConsultaViaje Viaje::crearDTConsultaViaje() {
    return DTConsultaViaje(this->codigo, veh->getMarca(), veh->getModelo(), veh->getConductor(), veh->getCalifConductor(), this->precio);
}

bool Viaje::relacion(class Pasajero* p) {
    for(auto const& r : reservas) {
        if (r->relacionResPas(p)) return true;
    }
    return false;
}

int Viaje::totalAsientosRes() {
    int reservados = 0;
    for (auto const& r : reservas)
        reservados += r->getAsientosReservados();
    return reservados;
}

void Viaje::asociarViajeReserva(Reserva* nr) {
    this->reservas.push_back(nr);
}

void Viaje::asociarViajeVeh(Vehiculo *veh) {
    this->veh = veh;
}

std::vector<DTListarViaje> Viaje::crearDTViajes(const Usuario* u) {
    std::vector<DTListarViaje> res;
    for(auto const& r : reservas) {
        if (r->igualUsuario(u)) {
            res.push_back(DTListarViaje(this->codigo, this->fecha, this->origen, this->destino, veh->getConductor()));
        }
    }
    return res;
}

std::vector<DTUsuarioViaje> Viaje::obtenerPasajeros(std::string nickname) {
    std::vector<DTUsuarioViaje> res;
    for (auto const& r : reservas) {
        std::string nick = r->obtenerNickPasajero();
        if (nick != nickname)
            res.push_back(DTUsuarioViaje(nick, TipoUsuario::Pasajero));
    }
    return res;
}

DTUsuarioViaje Viaje::obtenerConductor() {
    return DTUsuarioViaje(veh->getNickConductor(), TipoUsuario::Conductor);
}

Reserva* Viaje::obtenerReservaCalif(Usuario* u, Usuario* u_calif) {
    DTUsuarioViaje dtu = u->getDTUsuarioViaje();
    TipoUsuario tipo = dtu.getTipo();

    for (auto* r : this->reservas) {
        if (tipo == TipoUsuario::Pasajero) {
            if (r->igualUsuario(u)) return r;
        } else {
            if (r->igualUsuario(u_calif)) return r;
        }
    }
    return nullptr;
}

bool Viaje::coincideCalif(Usuario* u, Usuario* u_calif) {
    for(auto const& r : reservas) {
        if (r->existeCal(u, u_calif)) return true;
    }
    return false;
}

DTUsuarioViaje Viaje::DTUsuarioViajeCond() {
    return DTUsuarioViaje(veh->getNickConductor(), TipoUsuario::Conductor);
}

DTDetalleViaje Viaje::crearDTDetalleViaje() {
    std::vector<DTDetalleReserva> dtreservas;
    for (auto const& r : reservas) {
        dtreservas.push_back(r->crearDTDetalleReserva());
    }
    return DTDetalleViaje(codigo, fecha, origen, destino, asientosPublicados, precio, veh->crearDTDetalleVehiculo(), dtreservas);
}

void Viaje::eliminarLinkVehiculo() {
    veh = nullptr;
}