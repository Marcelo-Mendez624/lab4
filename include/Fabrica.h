#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IAltaUsuario.h"
#include "IGenerarReserva.h"
#include "ICalificarUsuario.h"
#include "IAltaViaje.h"
#include "IEliminarViaje.h"


class Fabrica {
private:
    static Fabrica* instancia;

    Fabrica();

public:
    static Fabrica* getInstance();
    IAltaUsuario* getIAltaUsuario();
    IGenerarReserva* getIGenerarReserva();
    ICalificarUsuario *getICalificarUsuario();
    IAltaViaje *getIAltaViaje();
    IEliminarViaje *getIEliminarViaje();
    IControladorFechaActual* getIControladorFechaActual();
    void cleanUp();
};

#endif
