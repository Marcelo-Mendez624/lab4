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
    Vehiculo* veh;

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
    Vehiculo* getVehiculo() const;

    //consultarViajes
    bool cumpleDatos(DTFecha fecha, std::string origen, std::string destino);
    bool consultarAsientos(int asientos);
    DTConsultaViaje crearDTConsultaViaje();

    //generarReserva
    bool relacion(class Pasajero* p);
    int totalAsientosRes();
    void asociarViajeReserva(Reserva* nr);

    //listarViajes
    std::vector<DTListarViaje> crearDTViajes(class Usuario* u);

    //listarUsuariosViaje
    std::vector<DTUsuarioViaje> obtenerPasajeros(std::string nickname);
    DTUsuarioViaje obtenerConductor(std::string nickname);

    //calificarUsuario
    Reserva* obtenerReservaCalif(Usuario* u, Usuario* u_calif);
    bool coincideCalif(Usuario* u, Usuario* u_calif);
};

#endif