#ifndef RESERVA_H
#define RESERVA_H

#include <map>
#include <string>
#include <list>
#include "DTFecha.h"
#include "Pasajero.h"
#include "Usuario.h"
#include "Calificacion.h"
#include "ControladorFechaActual.h"
#include "DTDetalleReserva.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero;
    std::list<Calificacion*> calificaciones;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    Reserva(const Reserva&) = delete;
    Reserva& operator=(const Reserva&) = delete;

    void setAsientosReservados(int a);
    void setFecha(DTFecha f);
    int getAsientosReservados();
    DTFecha getfecha();
    void asociarReservaPasajero(Pasajero* p);
    void crearCalificacion(Usuario* u, Usuario* u_calif, int calificacion);
    std::list<Calificacion*> getCalificaciones();
    bool existeCal(Usuario* u, Usuario* u_calif);
    bool igualUsuario(const Usuario* u);
    Pasajero* getPasajero();
    bool relacionResPas(Pasajero* p);
    std::string obtenerNickPasajero();
    DTDetalleReserva crearDTDetalleReserva();
    void eliminarCalificaciones();
    void eliminarLinkPasajero();
};

#endif