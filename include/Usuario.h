#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Calificacion.h"
#include "DTUsuario.h"
#include "DTListarViaje.h"



class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::vector<Calificacion*> calificaciones;
    std::vector<DTListarViaje> viajes; //TODO cuando se cree el controlador quitar

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    
    // TODO Revisar include
    void asociarCalificacion(Calificacion* calificacion);

    float getCalificacionPromedio() const;

    DTUsuario getDTUsuario() const;

    std::string getNickname() const;

    std::vector<DTListarViaje> getViajes() const; 

    virtual DTUsuarioViaje getDTUsuarioViaje() = 0;  //polimórfica
    
};

#endif
