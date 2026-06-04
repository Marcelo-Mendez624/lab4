#include "../include/Viaje.h"

Viaje::Viaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = obtenerCodigo();     //PREGUNTAR AL PROFE MAÑANA
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->veh = v;
}

Viaje::~Viaje() {};

float Viaje::getPrecio() const { return this->precio; }

int Viaje::getAsientosPublicados() const { return this->asientosPublicados; }

int Viaje::getCodigo() const { return this->codigo; }

DTFecha Viaje::getFecha() const { return this->fecha; }

std::string Viaje::getOrigen() const { return this->origen; }

std::string Viaje::getDestino() const { return this->destino; }

Vehiculo* Viaje::getVehiculo() const { return this->veh; }

bool Viaje::cumpleDatos(DTFecha fecha, std::string origen, std::string destino)
{
    bool cond1 = fecha == this->fecha;
    bool cond2 = origen == this->origen;
    bool cond3 = destino == this->destino;

    return cond1 && cond2 && cond3;
}

bool Viaje::consultarAsientos(int asientos)
{
    int reservados = totalAsientosRes();
    return (reservados + asientos) <= this->asientosPublicados;
}

DTConsultaViaje Viaje::crearDTConsultaViaje()
{

    int codigo = this->getCodigo();
    std::string marca = (this->veh)->getMarca();
    std::string modelo = (this->veh)->getModelo();
    std::string conductor = (this->veh)->getConductor();
    float calif = (this->veh)->getCalifConductor();
    float precio = this->getPrecio();

    DTConsultaViaje res = DTConsultaViaje(codigo, marca, modelo, conductor, calif, precio);
    return res;
}

bool Viaje::relacion(class Pasajero* p) 
{
    bool res = false;

    for(const auto& r : reservas)
    {
        bool aux = r->relacionResPas(p);
        res = res || aux;

        if (res) break;
    }
    return res;
}

int Viaje::totalAsientosRes() 
{
    int reservados = 0;
    for (const auto& r : reservas)
        reservados = reservados + r->getAsientosReservados();
    
    return reservados;
}

void Viaje::asociarViajeReserva(Reserva* nr) 
{
    this->reservas.push_back(nr);
}

std::vector<DTListarViaje> Viaje::crearDTViajes(class Usuario* u)
{
    std::vector<DTListarViaje> res;

    for(const auto& r : reservas)
    {
        bool iguales = r->igualUsuario(u);

        if (iguales)
        {
            DTListarViaje dt = DTListarViaje(this->getCodigo(), this->getFecha(), this->getOrigen(), this->getDestino(), veh->getConductor());
            res.push_back(dt);
        }
    }
    return res;
}


std::vector<DTUsuarioViaje> Viaje::obtenerPasajeros(std::string nickname) 
{
    std::vector<DTUsuarioViaje> res;

    for (const auto& r : reservas) 
    {
        std::string nick = r->obtenerNickPasajero();
        if (nick != nickname)
            res.push_back(DTUsuarioViaje(nick, Pasajero));
    }
    return res;
}

DTUsuarioViaje Viaje::obtenerConductor(std::string nickname)
{
    Vehiculo* ve = getVehiculo();
    return DTUsuarioViaje(ve->getNickConductor(), Conductor);
}

Reserva* Viaje::obtenerReservaCalif(Usuario* u, Usuario* u_calif)
{
    DTUsuarioViaje dtu = u->getDTUsuarioViaje();
    TipoUsuario tipo = dtu.getTipo();

    if (tipo == Pasajero)
        for(const auto& r : reservas)
            if (r->igualUsuario(u))
                return r;
    
    else if (tipo == Conductor)
        for(const auto& r : reservas)
            if (r->igualUsuario(u_calif))
                return r;
}

bool Viaje::coincideCalif(Usuario* u, Usuario* u_calif)
{
    bool res = false;

    for(const auto& r : reservas)
    {
        bool aux = r->existeCal(u, u_calif);
        res = res || aux;
        if (res) break;
    }
    return res;
}