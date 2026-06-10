#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
#include <set>

class Usuario;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* u_calificado;
    Usuario* u_califica;
public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
    int getPuntaje() const { return puntaje; }
    bool coicidenUsuario( Usuario* u, Usuario* u_calif);
    void linkearCalifUsuario(Usuario* u, Usuario* u_calif);
    void eliminarLinks();

    bool operator==(Calificacion other);
};

#endif