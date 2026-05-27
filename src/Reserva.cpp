#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}

Reserva::~Reserva() {}


std::vector<Calificacion*> Reserva:: getCalificaciones{
  return this->calificaciones;
}

void Reserva:: asociarReservaPasajero(Pasajero* p){
  this->pasajero=p;
}

std::string Reserva:: obtenerNickPasajero(){
  Pasajero* p= this->pasajero;
  return p->getNickname();
}

bool Reserva:: coinciden (Usuario* u){
    return this->obtenerNickPasajero()==u->getNickname();
}

Pasajero* Reserva:: getPasajero(){
  return this->pasajero;
}



