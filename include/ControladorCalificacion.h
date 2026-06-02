#define CONTROLADOR_CALIFICACION_H
#ifdef CONTROLADOR_CALIFICACION_H

#include <string>
#include <map>
#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"
#include "ICalificarUsuario.h"

class ControladorCalificacion : public ICalificarUsuario {
private:
    static ControladorCalificacion* instancia;
    ControladorCalificacion();

public:
    static ControladorCalificacion* getInstance();
    bool calificarUsuario(std::string nicknameCalificado, int calificacion);
    std::map<std::string, DTUsuario> listarUsuarios();
    std::map<std::string, DTConsultaViaje> listarViajes(std::string nickname);
    std::map<std::string, DTUsuarioViaje> listarUsuariosViaje(int codigo);
    
    ~ControladorCalificacion();
}

#endif // CONTROLADOR_CALIFICACION_
