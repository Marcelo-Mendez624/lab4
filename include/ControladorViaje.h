#ifndef CTRL_VIAJE_H

#include "IAltaViaje.h"
#include "IEliminarViaje.h"
#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"
#include <vector>

class ControladorViaje : public IAltaViaje, public IEliminarViaje {
private:
    static ControladorViaje* instance;
    int* codigo = nullptr;
public:
    static ControladorViaje* getInstance();

    //AltaViaje
    std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname) override;
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino,  int asientos, float precio) override;

    //EliminarViaje
    std::vector<DTListarViaje> listarViajes() override;
    DTDetalleViaje DetalleViaje(int codigo) override;
    void eliminarViaje() override;
    void cancelarEliminarViaje() override;
};

#endif