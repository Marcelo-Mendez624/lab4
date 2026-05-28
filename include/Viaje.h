#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "Pasajero.h"
#include "Reserva.h"
#include "Vehiculo.h"
#include <string>
#include <vector>

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    std::vector<Reserva*> reservas;
    Vehiculo * veh;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();

    //Getters
    float getPrecio() const;
    int getAsientosPublicados() const;
    int getCodigo() const;
    DTFecha getFecha() const;
    std::string getOrigen() const;
    std::string getDestino() const;

    //consultarViajes
    bool cumpleDatos(DTFecha fecha, std::string origen, std::string destino);
    bool consultarAsientos(int asientos);
    DTConsultaViaje crearDTConsultaViaje();

    //generarReserva
    bool relacion(class Pasajero* p);
    int totalAsientosRes();
    Reserva* crearReserva(int asientos, DTFecha fecha);

    //listarViajes
    std::vector<DTListarViaje> crearDTViajes(class Pasajero* p);        //DCD: Usuario u en vez de Pasajero p (así ahorro un include)

    //listarUsuariosViaje
    std::vector<DTUsuarioViaje> obtenerPasajeros();
    DTUsuarioViaje obtenerConductor();

    //calificarUsuario
    Reserva obtenerReservaCalif(Usuario* u);                            //DCD: agregar usuario como parámetro
    bool coincideCalif(Usuario* u, Usuario* u_calif);                   //DCD: coincide en vez de coincideCalif
};

#endif