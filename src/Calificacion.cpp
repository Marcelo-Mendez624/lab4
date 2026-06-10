#include "../include/Calificacion.h"
#include "../include/Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

bool Calificacion::coicidenUsuario(Usuario*u,Usuario* u_calif)
{
    return  u->getNickname() == u_califica->getNickname()
            &&
            u_calif->getNickname() == u_calificado->getNickname();
}

void Calificacion::linkearCalifUsuario(Usuario* u,Usuario* u_calif) {
   this->u_calificado=u_calif;
   this->u_califica=u;
}

void Calificacion::eliminarLinks()
{
    u_calificado->eliminarLinkCalificacion(this);
    u_calificado = nullptr;
    u_califica = nullptr;
}

bool Calificacion::operator==(Calificacion other)
{
    bool aux1 = u_califica->getNickname() == other.u_califica->getNickname();
    bool aux2 = u_calificado->getNickname() == other.u_calificado->getNickname();
    bool aux3 = fecha == other.fecha;
    bool aux4 = puntaje == other.puntaje;
    return aux1 && aux2 && aux3 && aux4;
}