#include "../include/Pasajero.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Pasajero::~Pasajero() {}

DTUsuarioViaje Pasajero::getDTUsuarioViaje()
{
    TipoUsuario aux = TipoUsuario::Pasajero;
    return DTUsuarioViaje(this->getNickname(), aux);
}

void Pasajero::asociarPasajeroReserva(Reserva* r)
{
    reservas.push_back(r);
}

void Pasajero::eliminarLinkReserva(Reserva* r)
{
    
}