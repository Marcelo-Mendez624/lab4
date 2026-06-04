#include "../include/ControladorViaje.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorVehiculo.h"
#include "../include/ManejadorViaje.h"

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

    return true;
}

std::vector<DTListarViaje> ControladorViaje::listarViajes()
{
    std::vector<DTListarViaje> res;

    ManejadorViaje* mv = mv->getInstance();
    std::map<std::string, Viaje*> viajes = mv->getViajes();

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

    Vehiculo* v = vi->getVehiculo();
    DTDetalleViaje res = vi->crearDTDetalleViaje();
    
    this->codigo = new int;
    *(this->codigo) = codigo;

    return res;
}

bool ControladorViaje::eliminarViaje()
{
    ManejadorViaje* mv = mv->getInstance();
    Viaje* vi = mv->obtenerViaje(*(this->codigo));

}

void ControladorViaje::cancelarEliminarViaje()
{
    delete this->codigo;
    this->codigo = nullptr;
}