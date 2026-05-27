#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    std set<Usuario> usuariosCalificados; // Conjunto para almacenar los usuarios que han sido calificados
    std set<Reserva> reservasCalificadas; // Conjunto para almacenar las reservas que han sido calificadas
public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    int getPuntaje() const { return puntaje; }
    bool coicidenUsuario(u: Usuario, u_Calif: usuario);
    void linkerCalifUsuario(u: Usuario, u_Calif: usuario);
};

#endif

