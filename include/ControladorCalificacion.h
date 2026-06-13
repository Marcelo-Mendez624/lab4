#define CONTROLADOR_CALIFICACION_H
#ifdef CONTROLADOR_CALIFICACION_H

#include <string>
#include <map>
#include <vector>
#include "DTUsuario.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"
#include "ICalificarUsuario.h"

class ControladorCalificacion : public ICalificarUsuario {
private:
    static ControladorCalificacion* instancia;
    ControladorCalificacion();

    std::string nickname;
    int codigoViaje;

public:
    static ControladorCalificacion* getInstance();
    std::map<std::string, DTUsuario> listarUsuarios();
    std::vector<DTListarViaje> listarViajes(std::string nickname);
    std::map<std::string, DTUsuarioViaje> listarUsuariosViaje(int codigo);
    bool calificarUsuario(std::string nicknameCalificado, int calificacion);

    static void cleanUp();
    ~ControladorCalificacion();
};

#endif // CONTROLADOR_CALIFICACION_
