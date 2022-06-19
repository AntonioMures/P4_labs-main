# ----- Makefile Grupo 49 -----

OBJETOS = obj/Utils.o obj/DTFecha.o obj/FechaSistema.o obj/DTHuesped.o obj/DTEmpleado.o obj/DTHabitacion.o obj/DTHostal.o obj/DTReserva.o obj/DTReservaGrupal.o obj/DTReservaIndividual.o obj/DTEstadia.o obj/DTCalificacion.o obj/DTrespCalificacion.o obj/Usuario.o obj/Empleado.o obj/Huesped.o obj/Habitacion.o obj/Hostal.o obj/Calificacion.o obj/respCalificacion.o obj/Reserva.o obj/ReservaGrupal.o obj/ReservaIndividual.o obj/Estadia.o obj/IFechaSistema.o obj/IControladorCalificacion.o obj/IControladorHostal.o obj/IControladorReservas.o obj/IControladorUsuarios.o obj/ControladorCalificacion.o obj/ControladorHostal.o obj/ControladorUsuarios.o obj/ControladorReservas.o obj/Fabrica.o obj/DatosDePrueba.o

FUENTES = src/Utils.cpp include/Utils.h \
src/DTFecha.cpp include/DTFecha.h \
src/FechaSistema.cpp include/FechaSistema.h \
src/DTHuesped.cpp include/DTHuesped.h \
src/DTEmpleado.cpp include/DTEmpleado.h \
src/DTHabitacion.cpp include/DTHabitacion.h \
src/DTHostal.cpp include/DTHostal.h \
src/DTReserva.cpp include/DTReserva.h \
src/DTReservaGrupal.cpp include/DTReservaGrupal.h \
src/DTReservaIndividual.cpp include/DTReservaIndividual.h \
src/DTEstadia.cpp include/DTEstadia.h \
src/DTCalificacion.cpp include/DTCalificacion.h \
src/DTrespCalificacion.cpp include/DTrespCalificacion.h \
src/Usuario.cpp include/Usuario.h \
src/Huesped.cpp include/Huesped.h \
src/Empleado.cpp include/Empleado.h \
src/Habitacion.cpp include/Habitacion.h \
src/Hostal.cpp include/Hostal.h \
src/Calificacion.cpp include/Calificacion.h \
src/respCalificacion.cpp include/respCalificacion.h \
src/Reserva.cpp include/Reserva.h \
src/ReservaGrupal.cpp include/ReservaGrupal.h \
src/ReservaIndividual.cpp include/ReservaIndividual.h \
src/Estadia.cpp include/Estadia.h \
src/IFechaSistema.cpp include/IFechaSistema.h \
src/IControladorCalificacion.cpp include/IControladorCalificacion.h \
src/IControladorHostal.cpp include/IControladorHostal.h \
src/IControladorReservas.cpp include/IControladorReservas.h \
src/IControladorUsuarios.cpp include/IControladorUsuarios.h \
src/ControladorCalificacion.cpp include/ControladorCalificacion.h \
src/ControladorHostal.cpp include/ControladorHostal.h \
src/ControladorUsuarios.cpp include/ControladorUsuarios.h \
src/ControladorReservas.cpp include/ControladorReservas.h \
src/Fabrica.cpp include/Fabrica.h \
src/DatosDePrueba.cpp include/DatosDePrueba.h \
main.cpp

CC = g++
OPCIONES = -g -Wall
SINUSO =

main: $(OBJETOS) main.cpp
	$(CC) $(OPCIONES) $(OBJETOS) $(SINUSO) main.cpp -o main

obj/Utils.o: include/Utils.h src/Utils.cpp
	$(CC) $(OPCIONES) -c src/Utils.cpp -o obj/Utils.o

obj/DTFecha.o: include/DTFecha.h src/DTFecha.cpp
	$(CC) $(OPCIONES) -c src/DTFecha.cpp -o obj/DTFecha.o

obj/FechaSistema.o: include/FechaSistema.h src/FechaSistema.cpp
	$(CC) $(OPCIONES) -c src/FechaSistema.cpp -o obj/FechaSistema.o

obj/Usuario.o: include/Usuario.h src/Usuario.cpp
	$(CC) $(OPCIONES) -c src/Usuario.cpp -o obj/Usuario.o

obj/Huesped.o: include/Huesped.h src/Huesped.cpp
	$(CC) $(OPCIONES) -c src/Huesped.cpp -o obj/Huesped.o

obj/Empleado.o: include/Empleado.h src/Empleado.cpp
	$(CC) $(OPCIONES) -c src/Empleado.cpp -o obj/Empleado.o

obj/Habitacion.o: include/Habitacion.h src/Habitacion.cpp
	$(CC) $(OPCIONES) -c src/Habitacion.cpp -o obj/Habitacion.o

obj/Hostal.o: include/Hostal.h src/Hostal.cpp
	$(CC) $(OPCIONES) -c src/Hostal.cpp -o obj/Hostal.o

obj/Calificacion.o: include/Calificacion.h src/Calificacion.cpp
	$(CC) $(OPCIONES) -c src/Calificacion.cpp -o obj/Calificacion.o

obj/respCalificacion.o: include/respCalificacion.h src/respCalificacion.cpp
	$(CC) $(OPCIONES) -c src/respCalificacion.cpp -o obj/respCalificacion.o

obj/Reserva.o: include/Reserva.h src/Reserva.cpp
	$(CC) $(OPCIONES) -c src/Reserva.cpp -o obj/Reserva.o

obj/ReservaGrupal.o: include/ReservaGrupal.h src/ReservaGrupal.cpp
	$(CC) $(OPCIONES) -c src/ReservaGrupal.cpp -o obj/ReservaGrupal.o

obj/ReservaIndividual.o: include/ReservaIndividual.h src/ReservaIndividual.cpp
	$(CC) $(OPCIONES) -c src/ReservaIndividual.cpp -o obj/ReservaIndividual.o

obj/Estadia.o: include/Estadia.h src/Estadia.cpp
	$(CC) $(OPCIONES) -c src/Estadia.cpp -o obj/Estadia.o

obj/DTHuesped.o: include/DTHuesped.h src/DTHuesped.cpp
	$(CC) $(OPCIONES) -c src/DTHuesped.cpp -o obj/DTHuesped.o

obj/DTEmpleado.o: include/DTEmpleado.h src/DTEmpleado.cpp
	$(CC) $(OPCIONES) -c src/DTEmpleado.cpp -o obj/DTEmpleado.o

obj/DTHabitacion.o: include/DTHabitacion.h src/DTHabitacion.cpp
	$(CC) $(OPCIONES) -c src/DTHabitacion.cpp -o obj/DTHabitacion.o

obj/DTHostal.o: include/DTHostal.h src/DTHostal.cpp
	$(CC) $(OPCIONES) -c src/DTHostal.cpp -o obj/DTHostal.o

obj/DTReserva.o: include/DTReserva.h src/DTReserva.cpp
	$(CC) $(OPCIONES) -c src/DTReserva.cpp -o obj/DTReserva.o

obj/DTReservaGrupal.o: include/DTReservaGrupal.h src/DTReservaGrupal.cpp
	$(CC) $(OPCIONES) -c src/DTReservaGrupal.cpp -o obj/DTReservaGrupal.o

obj/DTReservaIndividual.o: include/DTReservaIndividual.h src/DTReservaIndividual.cpp
	$(CC) $(OPCIONES) -c src/DTReservaIndividual.cpp -o obj/DTReservaIndividual.o

obj/DTEstadia.o: include/DTEstadia.h src/DTEstadia.cpp
	$(CC) $(OPCIONES) -c src/DTEstadia.cpp -o obj/DTEstadia.o

obj/DTCalificacion.o: include/DTCalificacion.h src/DTCalificacion.cpp
	$(CC) $(OPCIONES) -c src/DTCalificacion.cpp -o obj/DTCalificacion.o

obj/DTrespCalificacion.o: include/DTrespCalificacion.h src/DTrespCalificacion.cpp
	$(CC) $(OPCIONES) -c src/DTrespCalificacion.cpp -o obj/DTrespCalificacion.o

obj/IFechaSistema.o: include/IFechaSistema.h src/IFechaSistema.cpp
	$(CC) $(OPCIONES) -c src/IFechaSistema.cpp -o obj/IFechaSistema.o

obj/IControladorCalificacion.o: include/IControladorCalificacion.h src/IControladorCalificacion.cpp
	$(CC) $(OPCIONES) -c src/IControladorCalificacion.cpp -o obj/IControladorCalificacion.o

obj/IControladorHostal.o: include/IControladorHostal.h src/IControladorHostal.cpp
	$(CC) $(OPCIONES) -c src/IControladorHostal.cpp -o obj/IControladorHostal.o

obj/IControladorReservas.o: include/IControladorReservas.h src/IControladorReservas.cpp
	$(CC) $(OPCIONES) -c src/IControladorReservas.cpp -o obj/IControladorReservas.o

obj/IControladorUsuarios.o: include/IControladorUsuarios.h src/IControladorUsuarios.cpp
	$(CC) $(OPCIONES) -c src/IControladorUsuarios.cpp -o obj/IControladorUsuarios.o

obj/ControladorCalificacion.o: include/ControladorCalificacion.h src/ControladorCalificacion.cpp
	$(CC) $(OPCIONES) -c src/ControladorCalificacion.cpp -o obj/ControladorCalificacion.o

obj/ControladorHostal.o: include/ControladorHostal.h src/ControladorHostal.cpp
	$(CC) $(OPCIONES) -c src/ControladorHostal.cpp -o obj/ControladorHostal.o

obj/ControladorUsuarios.o: include/ControladorUsuarios.h src/ControladorUsuarios.cpp
	$(CC) $(OPCIONES) -c src/ControladorUsuarios.cpp -o obj/ControladorUsuarios.o

obj/ControladorReservas.o: include/ControladorReservas.h src/ControladorReservas.cpp
	$(CC) $(OPCIONES) -c src/ControladorReservas.cpp -o obj/ControladorReservas.o

obj/Fabrica.o: include/Fabrica.h src/Fabrica.cpp
	$(CC) $(OPCIONES) -c src/Fabrica.cpp -o obj/Fabrica.o

obj/DatosDePrueba.o: include/DatosDePrueba.h src/DatosDePrueba.cpp
	$(CC) $(OPCIONES) -c src/DatosDePrueba.cpp -o obj/DatosDePrueba.o

.PHONY: clean rebuild

clean:
	rm -f $(OBJETOS) main

rebuild:
	make clean
	make