#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include "DTUsuarioViaje.h"
#include <string>
class Reserva;

class Pasajero : public Usuario {
private:
    std::string ci;
    std::vector<Reserva*> reservas;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();

    std::string getCi();
    DTUsuarioViaje getDTUsuarioViaje() override;
    void asociarPasajeroReserva(Reserva* r);
    void eliminarLinkReserva(Reserva* r);
};

#endif
