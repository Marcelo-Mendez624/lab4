#ifndef RESERVA_H
#define RESERVA_H
#include <map>
#include <string>
#include "DTFecha.h"
#include "Pasajero.h"
#include "Usuario.h"
#include "Calificacion.h"
#include "ControladorFechaActual.h"
#include "DTDetalleReserva.h"
#include <list>

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    class Pasajero* pasajero;
    std::list<Calificacion*> calificaciones;
public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    void setAsientosReservados(int a);
    void setFecha(DTFecha f);
    int getAsientosReservados();
    DTFecha getfecha();
    void asociarReservaPasajero(class Pasajero* p);
    void crearCalificacion(Usuario* u, Usuario* u_calif, int calificacion);
    std::list<Calificacion*> getCalificaciones();
    bool existeCal(Usuario* u, Usuario* u_calif);
    bool igualUsuario(const Usuario* u);
    class Pasajero* getPasajero();
    bool relacionResPas(class Pasajero* p);
    std::string obtenerNickPasajero();
    DTDetalleReserva crearDTDetalleReserva();
    void eliminarCalificaciones();
    void eliminarLinkPasajero();
};

#endif
