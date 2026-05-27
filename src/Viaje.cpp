#include "../include/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

Viaje::~Viaje() {};

float Viaje::getPrecio() const { return this->precio; }

int Viaje::getAsientosPublicados() const { return this->asientosPublicados; }

int Viaje::getCodigo() const { return this->codigo; }

DTFecha Viaje::getFecha() const { return this->fecha; }

std::string Viaje::getOrigen() const { return this->origen; }

std::string Viaje::getDestino() const { return this->destino; }

bool Viaje::cumpleDatos(DTFecha fecha, std::string origen, std::string destino)
{
    bool cond1 = fecha == this->fecha;
    bool cond2 = origen == this->origen;
    bool cond3 = destino == this->destino;

    return cond1 && cond2 && cond3;
}

bool Viaje::consultarAsientos(int asientos)
{
    int reservados = 0;
    for (const auto& r : reservas)
        reservados = reservados + r.getAsientosReservados();
    
    return (reservados + asientos) <= this->asientosPublicados;
}

DTConsultaViaje Viaje::crearDTConsultaViaje()
{

    int codigo = this->getCodigo();
    std::string marca = (this->veh).getMarca();
    std::string modelo = (this->veh).getModelo();
    std::string conductor = (this->veh).obtenerConductor();
    float calif = (this->veh).obtenerCalifConductor();
    float precio = this->getPrecio();

    DTConsultaViaje res = DTConsultaViaje(codigo, marca, modelo, conductor, calif, precio);
    return res;
}