#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/IControladorFechaActual.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include <iostream>
#include <limits>
#include <string>

void Menu::altaUsuario() {
    //Llamo a la Fabrica
    Fabrica *f = Fabrica::getInstance();
    IAltaUsuario *controlador = f->getIAltaUsuario();
    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);


    bool usuarioOk = false;

    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        //TODO: usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci) (HECHO!!)
        usuarioOk = controlador->AltaPasajero(nickname, nombre, contrasena, email, ci);
    } else if (tipoUsuario == 2) {
      std::set<TipoLibreta> libretas;
      bool tieneMotoProfesional = false;
      bool tieneMotoAmateur = false;
      bool tieneAutoProfesional = false;
      bool tieneAutoAmateur = false;

      int cantLibretas = 0;
      int agregarLibreta = 1;

      while (agregarLibreta == 1 && cantLibretas < 4)
      {
        int tipoLibreta;
        std::cout << "\n=== Registrar Libreta ===\n";
        std::cout << "0. Moto (Profesional)\n";
        std::cout << "1. Moto (Amateur)\n";
        std::cout << "2. Auto (Profesional)\n";
        std::cout << "3. Auto (Amateur)\n";
        std::cout << "Seleccione el tipo de libreta: ";
        std::cin >> tipoLibreta;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool yaExiste = false;
        if (tipoLibreta == 0)
        {
          if (tieneMotoProfesional)
          {
            yaExiste = true;
          }
          else
          {
            tieneMotoProfesional = true;
            libretas.insert(MotoProfesional);
            cantLibretas++;
          }
        }
        else if (tipoLibreta == 1)
        {
          if (tieneMotoAmateur)
          {
            yaExiste = true;
          }
          else
          {
            tieneMotoAmateur = true;
            libretas.insert(MotoAmateur);
            cantLibretas++;
          }
        }
        else if (tipoLibreta == 2)
        {
          if (tieneAutoProfesional)
          {
            yaExiste = true;
          }
          else
          {
            tieneAutoProfesional = true;
            libretas.insert(AutoProfesional);
            cantLibretas++;
          }
        }
        else if (tipoLibreta == 3)
        {
          if (tieneAutoAmateur)
          {
            yaExiste = true;
          }
          else
          {
            tieneAutoAmateur = true;
            libretas.insert(AutoAmateur);
            cantLibretas++;
          }
        }
        else
        {
          std::cout << "Opcion invalida.\n";
          continue;
        }

        if (yaExiste)
        {
          std::cout << "Esa libreta ya fue ingresada.\n";
        }
        else
        {
          std::cout << "Libreta agregada.\n";
        }

        if (cantLibretas < 4)
        {
          std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
          std::cin >> agregarLibreta;
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
          std::cout << "Se ha alcanzado el limite maximo de libretas.\n";
        }
        }

        if (cantLibretas == 0) {
            std::cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
            return;
        }
        
        //TODO: usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas)
        usuarioOk = controlador->AltaConductor(nickname, nombre, contrasena, email,libretas);
        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int resultadoRegistrarVehiculo = -3;
            //TODO: resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipo) (HECHO!!)
            resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo,(TipoVehiculo)tipo);
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::altaViaje() {
  Fabrica *f = Fabrica::getInstance();
  IAltaViaje *controlador = f->getIAltaViaje();
  std::string nickname, matricula, origen, destino;
  int dia, mes, anio, asientos;
  float precio;

  std::cout << "Ingrese nickname del conductor: ";
  std::getline(std::cin, nickname);
  
  // TODO: Coleccion de DTVehiculosConductor = controlador->listarVehiculosConductor(nickname) (Hecho!!)

  std::vector<DTVehiculosConductor> col = controlador->listarVehiculosConductor(nickname);

  // TODO: Recorrer la coleccion y mostrar "> Matricula: xx, Capacidad: yy, Marca: zzz, Modelo: www, Tipo: ttt" Nota de Joaco: Marca y tipo no están en el DTVehiculosConductor
  for (std::vector<DTVehiculosConductor>::iterator it =col.begin(); it != col.end();++it)
     std::cout << "> Matricula: " << it->getMatricula()
              << ", Modelo: " << it->getModelo()
              << ", Capacidad: " << it->getCapacidad()
              << "\n";

  std::cout << "Ingrese matricula del vehiculo a utilizar: ";
  std::getline(std::cin, matricula);
  bool matriculaValida = false;
  // TODO: Validar matricula en listado (Hecho!!)
  std::vector<DTVehiculosConductor>::iterator it = col.begin();
  while (it!=col.end() && !matriculaValida){
    if (it->getMatricula()==matricula)
      matriculaValida = true;
    else
      ++it;
  }

  if (!matriculaValida)
  {
    std::cout << "Matricula invalida.\n";
    return;
  }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool viajeOk = false;
    //TODO: viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio) (Hecho!!)

    viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);

    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
  //Llamo a la Fábrica
  Fabrica *f = Fabrica::getInstance();
  IGenerarReserva *controlador = f->getIGenerarReserva();
  
  // TODO: Colecion de String = controlador->listarPasajeros() (Hecho!!)
  std::list<std::string> colP = controlador->listarPasajeros();

  // TODO: Recorrer la colección y mostrar "> xx" (Hecho!!)

  for (std::list<std::string>::iterator it = colP.begin(); it != colP.end();++it){
    std::cout << "> " << *it << "\n";
  }
    std::string nickname;
  std::cout << "Ingrese nickname del pasajero: ";
  std::getline(std::cin, nickname);

  bool nicknameValido = false;
 
  // TODO: Validar nickname en listado (Hecho!!)
  std::list<std::string>::iterator it = colP.begin();
  while (it!=colP.end()&& !nicknameValido){
    if (*it==nickname)
      nicknameValido = true;
    else
      ++it;
    }

  if (!nicknameValido)
  {
    std::cout << "Nickname invalido.\n";
    return;
  }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //TODO: Coleccion de DTConsultaViaje = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos) (Hecho!!)

    std::set<DTConsultaViaje> col = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);

    //TODO: Recorrer la coleccion y mostrar: "> Codigo: xx, Marca: yy, Modelo: zzz, Conductor: aaa, CalificacionPromedio: qqq, PrecioTotal: eee" (Hecho!!)

    for (std::set<DTConsultaViaje>::iterator it = col.begin(); it != col.end();++it)
    {
      std::cout << "> Codigo: " << it->getCodigo() << ", Marca: " << it->getMarca() << ", Modelo: " << it->getModelo() << ", Conductor: " << it->getConductor() << ", CalificacionPromedio: " << it->getCalificacionProm() << ", PrecioTotal: " << it->getPrecioTotal() << "\n";
    }

    bool hayViajes = !col.empty(); // TODO: Validar coleccion vacía (Hecho!!)
    if (!hayViajes) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    
    //TODO: Validar codigo en listado (Hecho!!)
    
    std::set<DTConsultaViaje>::iterator i = col.begin();
    while( i !=col.end() && !codigoValido){
      if (i->getCodigo()==codigo)
        codigoValido = true;
        else
          ++i;
    }

      if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = false;
    //TODO: reservaOk = controlador->generarReserva(nickname, codigo, asientos) (Hecho!!)

    reservaOk = controlador->generarReserva(nickname, codigo, asientos);

    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
  //Llamo a la fabrica
  Fabrica *f = Fabrica::getInstance();
  ICalificarUsuario* controlador = f->getICalificarUsuario();
  // TODO: Coleccion de DTUsuario = controlador->listarUsuarios() (Hecho!!)

  std::map<std::string, DTUsuario> colDtU = controlador->listarUsuarios();

  // TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Nombre: yyy" (Hecho!!)

  for(std::map<std::string,DTUsuario>
    ::iterator it = colDtU.begin();it!=colDtU.end();++it)
    std::cout << "> Nickname: " << (it->second).getNickname() << ", Nombre: " << (it->second).getNombre() << "\n";

  std::string nickname;
  std::cout << "Ingrese su nickname: ";
  std::getline(std::cin, nickname);
  bool nicknameValido = false;
  // TODO: Validar nickname en listado (Hecho!!)

  if(colDtU.find(nickname)!=colDtU.end())
    nicknameValido = true;

  if (!nicknameValido)
  {
    std::cout << "Nickname invalido.\n";
    return;
  }

    //TODO: Coleccion de DTListarViaje = controlador->listarViajes(nickname)
   // (Hecho!!)

  std::vector<DTListarViaje> viajes = controlador->listarViajes(nickname);

  // TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa" (Hecho!!)

  for (std::vector<DTListarViaje>::iterator it = viajes.begin(); it != viajes.end();++it)
  {
    std::cout << "> Codigo: " << it->getCodigo() << ", Fecha: " << it->getFecha() << ", Origen: " << it->getOrigen() << ", Destino: " << it->getDestino() << ", Conductor: " << it->getConductor() << "\n";
  }

    int codigo;
  std::cout << "Ingrese codigo del viaje: ";
  std::cin >> codigo;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  bool codigoValido = false;
  
  // TODO: Validar codigo en listado (Hecho!!)

  std::vector<DTListarViaje>::iterator it = viajes.begin();
  while (it != viajes.end() && !codigoValido){
    if (it->getCodigo()==codigo)
      codigoValido = true;
    it++;
  }

    if (!codigoValido)
    {
      std::cout << "Codigo invalido.\n";
      return;
    }

    //TODO: Coleccion de DTUsuarioViaje = Controlador->listarUsuariosViaje(codigo) (Hecho!!)

    std::map<std::string, DTUsuarioViaje> coluv = controlador->listarUsuariosViaje(codigo);

    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Tipo: yyy" (Hecho!!)

    for (std::map<std::string, DTUsuarioViaje>::iterator it = coluv.begin(); it != coluv.end(); ++it)
      if ((it->second).getTipo() == TipoUsuario::Pasajero)
        std::cout << "> Nickname: " << (it->second).getNickname() << ", Tipo: Pasajero\n";
      else
        std::cout << "> Nickname: " << (it->second).getNickname() << ", Tipo: Conductor\n";


    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool nicknameCalificadoValido = false;
    //TODO: Validar nickname en listado (Hecho!!)

    if(coluv.find(nicknameCalificado)!=coluv.end())
      nicknameCalificadoValido = true;

    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = false;
    
    //TODO: calificacionOk = Controlador->calificarUsuario(nicknameCalificado, calificacion) (Hecho!!)

    calificacionOk = controlador->calificarUsuario(nicknameCalificado, 
    calificacion);
    
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {
  //Llamo a la Fábrica
  Fabrica *f = Fabrica::getInstance();
  IEliminarViaje *controlador = f->getIEliminarViaje();

  // TODO: Coleccion de DTListarViaje = controlador->listarViajes() (Hecho!!)

  std::vector<DTListarViaje> colLV = controlador->listarViajes();

  // TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa" (Hecho)!!

  for (std::vector<DTListarViaje>::iterator it = colLV.begin(); it != colLV.end();++it)
  {
    std::cout << "> Codigo: " << it->getCodigo() << ", Fecha: " << it->getFecha() << ", Origen: " << it->getOrigen() << ", Destino: " << it->getDestino() << ", Conductor: " << it->getConductor() << "\n";
  }

  int codigo;
  std::cout << "Ingrese codigo del viaje a eliminar: ";
  std::cin >> codigo;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  bool codigoValido = false;
  
  // TODO: Validar codigo en listado (Hecho!!)

  std::vector<DTListarViaje>::iterator it = colLV.begin();
  while (it!=colLV.end() && !codigoValido){
    if (it->getCodigo()==codigo)
    {
      codigoValido = true;
    }
    it++;
  }


  if (!codigoValido)
  {
    std::cout << "Codigo invalido.\n";
    return;
  }

    //TODO: DTDetalleViaje = controlador->detalleViaje(codigo) (Hecho!!)

  DTDetalleViaje dtDV = controlador->DetalleViaje(codigo);

    // TODO: Mostrar detalle del viaje siguiendo el formato
  //>> Viaje <<
  //--- Codigo: aa, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, AsientosPublicados: bbb, Precio por asiento: qqq
  //>> Vehiculo <<
  //--- Matricula: mm, Capacidad: aa, Marca: bbb, Modelo: ccc, Tipo: ddd
  //>> Reservas <<
  //--- AsientosReservados: xx, Fecha: dd/mm/aaaa, Pasajero: aaa

//(Hecho!!) 
  std::cout << ">> Viaje <<" << "\n";
std::cout << "--- Codigo: " << dtDV.getCodigo()
          << ", Fecha: " << dtDV.getFecha()
          << ", Origen: " << dtDV.getOrigen()
          << ", Destino: " << dtDV.getDestino()
          << ", AsientosPublicados: " << dtDV.getAsientosPublicados()
          << ", Precio por asiento: " << dtDV.getPrecio()
          << "\n"; 

          //imprimo info del vehiculo
std::cout << ">> Vehiculo <<" << "\n";
std::cout << "--- Matricula: " << dtDV.getVehiculo().getMatricula()
          << ", Capacidad: " << dtDV.getVehiculo().getCapacidad()
          << ", Marca: " << dtDV.getVehiculo().getMarca()
          << ", Modelo: " << dtDV.getVehiculo().getModelo();
      if (dtDV.getVehiculo().getTipo()==0)
        std::cout << ", Tipo: Auto\n";
      else
        std::cout << ", Tipo: Moto\n";

// imprimo info de las reservas
std::cout << ">> Reservas <<" << "\n";
std::vector<DTDetalleReserva> res = dtDV.getReservas();
for (std::vector<DTDetalleReserva>::iterator it = res.begin(); it != res.end();++it){
 std::cout << "--- AsientosReservados: " << it->getAsientosReservados()
           << ", Fecha: " << it->getFecha()
           << ", Pasajero: " << it->getPasajero()
           << "\n";
}


  int confirmar;
std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): ";
std::cin >> confirmar;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
if (confirmar == 1)
{
  // TODO: controlador->eliminarViaje() (Hecho!!)
  controlador->eliminarViaje();

  std::cout << "Viaje eliminado exitosamente.\n";
} else {
        //TODO: controlador->cancelarEliminarViaje() (Hecho)!!
        controlador->cancelarEliminarViaje();
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
