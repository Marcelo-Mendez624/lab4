#include "../include/CargaDatos.h"
#include "Fabrica.cpp"
#include <iostream>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    
    // Aquí iría la lógica de carga de datos harcodeados
    std::cout << "Cargando datos harcodeados del sistema...\n";
    // TODO hacer pruebas aqui
    // ... (inserción de usuarios, vehículos, viajes, reservas) ...
    Fabrica *f = f->getInstance();

    IAltaUsuario *altaUsuario = f->getIAltaUsuario();
    std::set<TipoLibreta> libretas;
    libretas.insert(AutoAmateur);
    altaUsuario->AltaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", libretas);
    libretas.erase(AutoAmateur);
    libretas.insert(AutoProfesional);
    altaUsuario->AltaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", libretas);
    libretas.erase(AutoProfesional);
    libretas.insert(MotoAmateur);
    altaUsuario->AltaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", libretas);
    libretas.erase(MotoAmateur);
    libretas.insert(MotoProfesional);
    altaUsuario->AltaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", libretas);
    libretas.erase(MotoProfesional);
    libretas.insert(AutoProfesional);
    libretas.insert(MotoAmateur);
    altaUsuario->AltaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", libretas);

    altaUsuario->AltaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    altaUsuario->AltaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    altaUsuario->AltaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    altaUsuario->AltaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    altaUsuario->AltaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    altaUsuario->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
    altaUsuario->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", TipoVehiculo::Auto);
    altaUsuario->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", TipoVehiculo::Auto);
    altaUsuario->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", TipoVehiculo::Auto);
    altaUsuario->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", TipoVehiculo::Moto);
    altaUsuario->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", TipoVehiculo::Moto);
    altaUsuario->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", TipoVehiculo::Auto);
    altaUsuario->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", TipoVehiculo::Moto);


    IAltaViaje *altaViaje = f->getIAltaViaje();
    altaViaje->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);
    altaViaje->altaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250);
    altaViaje->altaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200);
    altaViaje->altaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200);
    altaViaje->altaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300);
    altaViaje->altaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350);
    altaViaje->altaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260);
    altaViaje->altaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150);
    altaViaje->altaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140);
    altaViaje->altaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180);
    altaViaje->altaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100);
    altaViaje->altaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600);
    altaViaje->altaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250);

    IGenerarReserva* gr = f->getIGenerarReserva();
    IControladorFechaActual* fa = f->getIControladorFechaActual();

    DTFecha f1(14, 3, 2026);
    fa->setFecha(f1);
    gr->generarReserva("santi_90", 9, 2);
    gr->generarReserva("mari_b", 9, 1);
    gr->generarReserva("nacho_f", 10, 5);
    gr->generarReserva("valen_uy", 10, 3);
    gr->generarReserva("joaco_r", 10, 1);

    DTFecha f2(13, 3, 2026);
    fa->setFecha(f2);
    gr->generarReserva("mari_b", 12, 1);
    gr->generarReserva("nacho_f", 12, 1);
    gr->generarReserva("nacho_f", 9, 1);

    DTFecha f3(1, 6, 2026);
    fa->setFecha(f3);
    gr->generarReserva("mari_b", 1, 2);

    ICalificarUsuario* calificarUsuario = f->getICalificarUsuario();
    calificarUsuario->listarViajes("santi_90");
    calificarUsuario->listarUsuariosViaje(9);
    calificarUsuario->calificarUsuario("matil92",4);

    calificarUsuario->listarViajes("mari_b");
    calificarUsuario->listarUsuariosViaje(9);
    calificarUsuario->calificarUsuario("matil92",4);

    calificarUsuario->listarViajes("matil92");
    calificarUsuario->listarUsuariosViaje(9);
    calificarUsuario->calificarUsuario("mari_b",3);

    calificarUsuario->listarViajes("ana_silva");
    calificarUsuario->listarUsuariosViaje(10);
    calificarUsuario->calificarUsuario("valen_uy",5);

    calificarUsuario->listarViajes("ana_silva");
    calificarUsuario->listarUsuariosViaje(10);
    calificarUsuario->calificarUsuario("joaco_r",5);

    calificarUsuario->listarViajes("mari_b");
    calificarUsuario->listarUsuariosViaje(12);
    calificarUsuario->calificarUsuario("carlos_r",5);

    calificarUsuario->listarViajes("carlos_r");
    calificarUsuario->listarUsuariosViaje(12);
    calificarUsuario->calificarUsuario("nacho_f",5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
