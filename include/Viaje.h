#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "Pasajero.h"
#include "Reserva.h"
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
    std::vector<Reserva> reservas;
    
public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();

    //Getters
    int getAsientosPublicados();
    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();

    //consultarViajes
    bool cumpleDatos(DTFecha fecha, std::string origen, std::string destino);
    bool consultarAsientos(int asientos);
    DTConsultaViaje crearDTConsultaViaje();

    //generarReserva
    bool relacion(Pasajero p);
    int totalAsientosRes();
    void crearReserva(int asientos, DTFecha fecha);

    //listarViajes
    std::vector<DTListarViaje> crearDTViajes(Pasajero p);       //DCD: Usuario u en vez de Pasajero p (así ahorro un include)

    //listarUsuariosViaje
    std::vector<DTUsuarioViaje> obtenerPasajeros();
    DTUsuarioViaje obtenerConductor();

    //calificarUsuario
    Reserva obtenerReservaCalif();
    bool coincideCalif(Usuario u, Usuario u_calif);             //DCD: coincide en vez de coincideCalif
};

#endif