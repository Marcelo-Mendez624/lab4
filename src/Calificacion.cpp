#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

bool Calificacion::coicidenUsuario(Usuario*u,Usuario* u_calif) {
    return  u->getNickname()==this->califica->getNickname() && u_calif->getNickname()==this->calificado->getNickname();
}

void Calificacion::linkearCalifUsuario(Usuario* u,Usuario* u_calif) {
   this->u_calificado=u_calif;
   this->u_califica=u;
}

