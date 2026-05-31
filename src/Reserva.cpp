#include "../include/Reserva.h"


Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}

Reserva::~Reserva() {}

std::list<Calificacion*> Reserva:: getCalificaciones(){
  return this->calificaciones;
}

int Reserva:: getAsientosReservados(){
  return this->asientosReservados;
}

DTFecha Reserva:: getfecha(){
  return this->fecha;
}

void Reserva:: asociarReservaPasajero(class Pasajero* p){
  this->pasajero=p;
}

std::string Reserva:: obtenerNickPasajero(){
  Pasajero* p= this->pasajero;
  return p->getNickname();
}

bool Reserva:: igualUsuario (Usuario* u){
    return this->obtenerNickPasajero()==u->getNickname();
}

class Pasajero* Reserva:: getPasajero(){
  return this->pasajero;
}

bool Reserva:: existeCal(Usuario* u, Usuario* u_calif){
  std::list<Calificacion*> calificaciones=this->calificaciones;
  std::list<Calificacion*>::iterator it=calificaciones.begin();
  bool bandera=false;
  while(it!=calificaciones.end() && !bandera){
    if ((*it)->coicidenUsuario(u,u_calif))
       bandera=true;
    else
      ++it;
    }
    return bandera;
}

void Reserva:: crearCalificacion(Usuario* u,Usuario* u_calif,int calificacion){
  ControladorFechaActual* c = ControladorFechaActual::getInstancia();
  DTFecha fecha=c->getFecha();
  Calificacion* cal=new Calificacion(fecha,calificacion);
  this->calificaciones.push_back(cal);
  cal->linkearCalifUsuario(u,u_calif);
  u_calif->asociarCalificacion(cal);
}






