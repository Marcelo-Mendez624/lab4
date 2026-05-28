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

        if (res)
            break;
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

Reserva* Viaje::crearReserva(int asientos, DTFecha fecha) 
{
    Reserva *nuevaRes = new Reserva(asientos, fecha);

    this->reservas.push_back(nuevaRes);
    
    //BITÁCORA DE PIPE:
    //crearReserva debe retornar la reserva y realizar la función
    //asociarReservaPasajero desde el controlador ya que el scope
    //del pasajero p no llega a viaje, por ende no puedo crear el link desde acá.

    return nuevaRes;
}

std::vector<DTListarViaje> Viaje::crearDTViajes(class Pasajero* p)
{
    std::vector<DTListarViaje> res;

    for(const auto& r : reservas)
    {
        bool iguales = r->coinciden(p);

        if (iguales)
        {
            DTListarViaje dt = DTListarViaje(this->getCodigo(), this->getFecha(), this->getOrigen(), this->getDestino(), veh->getConductor());
            res.push_back(dt);
        }
    }
    return res;
}


std::vector<DTUsuarioViaje> Viaje::obtenerPasajeros() 
{
    std::vector<DTUsuarioViaje> res;

    for (const auto& r : reservas) 
    {
        std::string dtp = r->obtenerNickPasajero();
        //BITÁCORA DE PIPE:
        //Ni idea cómo representar el dato recordado por el sistema.
    }
    return res;
}

Reserva Viaje::obtenerReservaCalif(Usuario* u)
{
    
}