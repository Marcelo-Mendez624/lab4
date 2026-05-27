#ifndef RESERVA_H
#define RESERVA_H
#include <map>
#include <string>
#include "DTFecha.h"
#include "Pasajero.h"
#include "Usuario.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero;
    std::vector<Calificacion*> calificaciones;
public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    void setAsientosReservados(int a);
    void setFecha(DTFecha f);
    int getasientosReservados();
    DTFecha getfecha();
    void asociarReservaPasajero(Pasajero* p);
    bool coinciden(Usuario* u);
    void crearCalificacion(Usuario* u, Usuario* u_calif);
    bool existeCal(Usuario* u, Usuario* u_calif);
    bool igualUsuario(Usuario* u);
    Pasajero* getPasajero();
    bool relacionResPas(Pasajero* p);
    std::string obtenerNickPasajero();
};

#endif
