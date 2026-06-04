#ifndef CTRL_VIAJE_H

#include "IAltaViaje.h"
#include "IEliminarViaje.h"
#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"
#include <vector>

class ControladorViaje {
private:
    int* codigo = nullptr;
public:
    //AltaViaje
    std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino,  int asientos, float precio);

    //EliminarViaje
    std::vector<DTListarViaje> listarViajes();
    DTDetalleViaje DetalleViaje(int codigo);
    bool eliminarViaje();
    void cancelarEliminarViaje();
};

#endif