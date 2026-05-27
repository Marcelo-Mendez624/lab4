#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

bool Calificacion::coicidenUsuario(u: Usuario, u_Calif: usuario) {
    // Implementación para verificar si el usuario coincide con el usuario de la calificación
    return u.getNickname() == u_Calif.getNickname();
}

void Calificacion::linkerCalifUsuario(u: Usuario, u_Calif: usuario) {
   this->u_calificado=u_calif;
   this->u_califica=u;
}
