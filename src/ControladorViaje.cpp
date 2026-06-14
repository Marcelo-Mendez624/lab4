#include "../include/ControladorViaje.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorVehiculo.h"
#include "../include/ManejadorViaje.h"

ControladorViaje* ControladorViaje::instance = nullptr;

ControladorViaje* ControladorViaje::getInstance()
{
    if (instance == nullptr)
        instance = new ControladorViaje;
    return instance;
}

std::vector<DTVehiculosConductor> ControladorViaje::listarVehiculosConductor(std::string nickname)
{
    ManejadorUsuario* m = m->getInstance();

    Usuario* u = m->obtenerUsuario(nickname);
    class Conductor* c = dynamic_cast<class Conductor*>(u);
    std::vector<DTVehiculosConductor> res = c->listarVehiculos();
    return res;
}

bool ControladorViaje::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino,  int asientos, float precio)
{
    ManejadorVehiculo* mve = mve->getInstance();
    Vehiculo* v = mve->obtenerVeh(matricula);
    int capacidad = v->getCapacidad();

    if (capacidad < asientos) return false;

    bool hayViajesFecha = v->hayViajesConductor(fecha);
    if (hayViajesFecha) return false;

    ManejadorViaje* mvi = mvi->getInstance();
    Viaje* vi = mvi->crearViaje(v, fecha, origen, destino, asientos, precio);
    v->asociarViaje(vi);
    vi->asociarViajeVeh(v);

    return true;
}

std::vector<DTListarViaje> ControladorViaje::listarViajes()
{
    std::vector<DTListarViaje> res;

    ManejadorViaje* mv = mv->getInstance();
    std::map<int, Viaje*> viajes = mv->getViajes();

    for(const auto& [str, vi] : viajes)
    {
        DTUsuarioViaje aux = vi->DTUsuarioViajeCond();
        DTListarViaje dt = DTListarViaje(vi->getCodigo(), vi->getFecha(), vi->getOrigen(), vi->getDestino(), aux.getNickname());
        res.push_back(dt);
    }
    return res;
}

DTDetalleViaje ControladorViaje::DetalleViaje(int codigo)
{
    ManejadorViaje* mv = mv->getInstance();
    Viaje* vi = mv->obtenerViaje(codigo);

    this->codigo = codigo;
    return vi->crearDTDetalleViaje();
}

void ControladorViaje::eliminarViaje()
{
    ManejadorViaje* mv = ManejadorViaje::getInstance();
    Viaje* vi = mv->obtenerViaje(codigo);
    Vehiculo* ve = vi->getVehiculo();

    //Eliminar link vehículo <-> viaje
    ve->eliminarLinkViaje(codigo);
    vi->eliminarLinkVehiculo();

    std::vector<Reserva*> reservas = vi->getReservas();

    while (!reservas.empty())
    {
        Reserva* r = reservas.back();

        //Eliminar link reserva -> calificacion <-> usuario (+ eliminar instancia de calificacion)
        r->eliminarCalificaciones();
        Pasajero* p = r->getPasajero();

        //Eliminar reserva <-> pasajero
        r->eliminarLinkPasajero();
        p->eliminarLinkReserva(r);
        reservas.pop_back();

        //Eliminar instancia de reserva
        delete r;
    }

    //Eliminar instancia de viaje
    mv->eliminarViaje(vi);
}

void ControladorViaje::cancelarEliminarViaje()
{
}

void ControladorViaje::cleanUp()
{
    ControladorViaje* it = ControladorViaje::getInstance();
    ManejadorViaje* mv = ManejadorViaje::getInstance();

    for(auto const& [id, v] : mv->getViajes())
    {
        it->DetalleViaje(id);
        it->eliminarViaje();
    }
    delete mv;

    if (instance != nullptr) delete it->instance;
    it->instance = nullptr;
}