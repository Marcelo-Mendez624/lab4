#ifndef CTRL_VIAJE_H

#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"
#include <vector>

class ControllerViaje {
private:

public:
    bool calificarUsuario(std::string nicknameCalificado, int calificacion);
    std::vector<DTUsuario> listarUsuarios();
    std::vector<DTConsultaViaje> listarViajes(std::string nickname);
    std::vector<DTUsuarioViaje> listarUsuariosViaje(int codigo);
};

#endif