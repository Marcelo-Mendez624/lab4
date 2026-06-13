#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Calificacion.h"
#include "DTUsuario.h"
#include "DTUsuarioViaje.h"
#include "DTListarViaje.h"



class Usuario {
private:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    float calificacionProm = 5;
    std::vector<Calificacion*> calificaciones;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    //getters
    std::string getNickname() const { return this->nickname; }
    std::string getNombre() const { return this->nombre; }
    std::string getEmail() const { return this->email; }
    std::string getContrasena() const { return this->contrasena; }
    std::vector<Calificacion*> getCalificaciones() const { return this->calificaciones; }
    float getCalificacionProm() { return this->calificacionProm; }

    void asociarCalificacion(Calificacion* calificacion);

    DTUsuario getDTUsuario() const;

    std::vector<DTListarViaje> getViajes() const; 

    virtual DTUsuarioViaje getDTUsuarioViaje() = 0;  //polimórfica
    
    void eliminarLinkCalificacion(Calificacion* c);

    void setCalificacionProm(float calprom);
};

#endif
