CXX = g++
CXXFLAGS = -Wall -Wextra -I./src

#estructura proyecto
SRCS = src/main.cpp \
       src/Menu.cpp \
       src/Calificacion.cpp \
       src/CargaDatos.cpp \
       src/Conductor.cpp \
       src/ControladorFechaActual.cpp \
       src/ControladorReserva.cpp \
       src/ControladorUsuario.cpp \
       src/ControladorViaje.cpp \
       src/DTConsultaViaje.cpp \
       src/DTDetalleReserva.cpp \
       src/DTDetalleVehiculo.cpp \
       src/DTDetalleViaje.cpp \
       src/DTFecha.cpp \
       src/DTListarViaje.cpp \
       src/DTUsuario.cpp \
       src/DTUsuarioViaje.cpp \
       src/DTVehiculosConductor.cpp \
       src/Fabrica.cpp \
       src/ManejadorUsuario.cpp \
       src/ManejadorVehiculo.cpp \
       src/ManejadorViaje.cpp \
       src/Pasajero.cpp \
       src/Reserva.cpp \
       src/Usuario.cpp \
       src/Vehiculo.cpp \
       src/Viaje.cpp

OBJS = $(SRCS:.cpp=.o)

# name ejecutable
TARGET = 58_lab4

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)