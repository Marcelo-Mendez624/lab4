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
    class Pasajero* pasajero;
    std::vector<Calificacion*> calificaciones;
public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    void setAsientosReservados(int a);
    void setFecha(DTFecha f);
    int getAsientosReservados();
    DTFecha getfecha();
    void asociarReservaPasajero(class Pasajero* p);
    bool coinciden(class Pasajero* p);
    void crearCalificacion(Usuario* u, Usuario* u_calif);
    bool existeCal(Usuario* u, Usuario* u_calif);
    bool igualUsuario(Usuario* u);
    class Pasajero* getPasajero();
    bool relacionResPas(class Pasajero* p);
    std::string obtenerNickPasajero();
};

#endif
