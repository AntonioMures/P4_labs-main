#include "../include/ControladorCalificacion.h"
#include "../include/ControladorHostal.h"
#include "../include/ControladorReservas.h"
#include "../include/ControladorUsuarios.h"
#include "../include/DatosDePrueba.h"
#include "../include/DTFecha.h"
#include <iostream> //sólo para testing

using namespace std;

bool YaCargados=false;

/*
Pre: Si algunos de los datos no son correctos y se aborta lanza una excepción.
Post: Se cargan todos los datos de prueba proporcionados
*/
void DatosDePrueba(){
    try {
        ControladorCalificacion* CCal = ControladorCalificacion::getInstancia();
        ControladorHostal* CHos = ControladorHostal::getInstancia();
        ControladorReservas* CRes = ControladorReservas::getInstancia();
        ControladorUsuarios* CUsu = ControladorUsuarios::getInstancia();

        //Empleados
        cout << "Cargando empleados\n";
        CUsu->ConfirmarEmpleado("Emilia","emilia@mail.com","123",true);
        CUsu->ConfirmarEmpleado("Leonardo","leo@mail.com","123",true);
        CUsu->ConfirmarEmpleado("Alina","alina@mail.com","123",true);
        CUsu->ConfirmarEmpleado("Barliman","barli@mail.com","123",true);

        //Huéspedes
        cout << "Cargando huéspedes\n";
        CUsu->ConfirmarHuesped("Sofia","sofia@mail.com","123",true);
        CUsu->ConfirmarHuesped("Frodo","frodo@mail.com","123",true);
        CUsu->ConfirmarHuesped("Sam","sam@mail.com","123",false);
        CUsu->ConfirmarHuesped("Merry","merry@mail.com","123",false);
        CUsu->ConfirmarHuesped("Pippin","pippin@mail.com","123",false);
        CUsu->ConfirmarHuesped("Seba","seba@mail.com","123",true);

        //Hostales
        cout << "Cargando hostales\n";
        CHos->ConfirmarHostal("La posada del finger",99111111,"Av de la playa 123, Maldonado");  //Es el hostal 1
        CHos->ConfirmarHostal("Mochileros",42579512,"Rambla Costanera 333, Rocha"); //Es el hostal 2
        CHos->ConfirmarHostal("El Pony Pisador",0,"Bree (preguntar por Gandalf)"); //Es el hostal 3
        CHos->ConfirmarHostal("Altos de Fing",99892992,"Av del Toro 1424"); //Es el hostal 4
        CHos->ConfirmarHostal("Caverna Lujosa",233233235,"Amaya 2515"); //Es el hostal 5

        //Habitaciones
        cout << "Cargando habitaciones\n";
        CHos->confirmarHabitacion("La posada del finger", 1, 40, 2); // Es del hostal 1
        CHos->confirmarHabitacion("La posada del finger", 2, 10, 7); // Es del hostal 1
        CHos->confirmarHabitacion("La posada del finger", 3, 30, 3); // Es del hostal 1
        CHos->confirmarHabitacion("La posada del finger", 4, 5, 12); // Es del hostal 1
        CHos->confirmarHabitacion("Caverna Lujosa", 1, 3, 2); // Es del hostal 5
        CHos->confirmarHabitacion("El Pony Pisador", 1, 9, 5); // Es del hostal 3

        //Empleado-Hostal
        cout << "Cargando empleado-hostal-cargo\n";
        CHos->asignarEmpleado("emilia@mail.com", "La posada del finger"); //Es del hostal 1
        CUsu->vincularEmpCargo("emilia@mail.com", Recepcion);
        CHos->asignarEmpleado("leo@mail.com", "Mochileros"); //Es del hostal 2
        CUsu->vincularEmpCargo("leo@mail.com", Recepcion);
        CHos->asignarEmpleado("alina@mail.com", "El Pony Pisador");  //Es del hostal 3
        CUsu->vincularEmpCargo("alina@mail.com", Administracion);
        CHos->asignarEmpleado("barli@mail.com", "Altos de Fing");  //Es del hostal 4
        CUsu->vincularEmpCargo("barli@mail.com", Recepcion);

        //Reservas
        cout << "Cargando reservas\n";
        DTFecha* in1, *in2, *in3, *in4;
        DTFecha* out1, *out2, *out3, *out4;

        ////Reserva 1 (individual)
        in1 = new DTFecha(1,5,2022,14);
        out1= new DTFecha(10,5,2022,10);
        CRes->confirmarReservaIndividual("La posada del finger",1,"sofia@mail.com",in1,out1);//Es del hostal 1

        ////Reserva 2 (grupal)
        in2 = new DTFecha(4,1,2001,20);
        out2= new DTFecha(5,1,2001,2);
        map<string,DTHuesped> GrupoR2;
        GrupoR2.insert(make_pair("frodo@mail.com", CUsu->obtenerHuesped("frodo@mail.com")->getDatosHuesped()));
        GrupoR2.insert(make_pair("sam@mail.com", CUsu->obtenerHuesped("sam@mail.com")->getDatosHuesped()));
        GrupoR2.insert(make_pair("merry@mail.com", CUsu->obtenerHuesped("merry@mail.com")->getDatosHuesped()));
        GrupoR2.insert(make_pair("pippin@mail.com", CUsu->obtenerHuesped("pippin@mail.com")->getDatosHuesped()));
        CRes->confirmarReservaGrupal("El Pony Pisador",1,"frodo@mail.com",in2,out2,GrupoR2); //Es del hostal 3

        ////Reserva 3 (individual)
        in3 = new DTFecha(7,6,2022,14);
        out3= new DTFecha(30,6,2022,11);
        CRes->confirmarReservaIndividual("La posada del finger",3,"sofia@mail.com",in3,out3); //Es del hostal 1

        ////Reserva 4 (individual)
        in4 = new DTFecha(10,6,2022,14);
        out4= new DTFecha(30,6,2022,11);
        CRes->confirmarReservaIndividual("Caverna Lujosa",1,"pippin@mail.com",in4,out4);//Es del hostal 5

        //Estadias
        /*
        map<int, Reserva *> reservas=CRes->getReservas();
        Reserva *res1, *res2, *res4;
        
        ////Estadia 1 - Corresponde a la reserva 1
        for (map<int, Reserva *>::iterator it=reservas.begin();it!=reservas.end();++it){
            Reserva *r=it->second;
            if (r->getHuesped()->getEmail()=="sofia@mail.com" 
                && r->getHabitacion()->getHostal()->getNombre()=="La posada del finger"
                && r->getHabitacion()->getNumero()==1 
                && r->getCheckin()==in1
                && r->getCheckOut()==out1 )
                    res1=it->second;
        }
        Estadia* est1 = CRes->DPRegistrarEstadia(res1,"sofia@mail.com",new DTFecha(1,5,2022,18));
        
        ////Estadia 1 a 4 - Corresponden a la reserva 2
        for (map<int, Reserva *>::iterator it=reservas.begin();it!=reservas.end();++it){
            Reserva *r=it->second;
            if (r->getHuesped()->getEmail()=="frodo@mail.com" 
                && r->getHabitacion()->getHostal()->getNombre()=="El Pony Pisador"
                && r->getHabitacion()->getNumero()==1 
                && r->getCheckin()==in2
                && r->getCheckOut()==out2 )
                    res2=it->second;
        }
        Estadia* est2 = CRes->DPRegistrarEstadia(res2,"frodo@mail.com",new DTFecha(1,5,2022,18));
        Estadia* est3 = CRes->DPRegistrarEstadia(res2,"sam@mail.com",new DTFecha(4,1,2001,9));
        Estadia* est4 = CRes->DPRegistrarEstadia(res2,"merry@mail.com",new DTFecha(4,1,2001,9));
        Estadia* est5 = CRes->DPRegistrarEstadia(res2,"pippin@mail.com",new DTFecha(4,1,2001,9));
        
        ////Estadia 1 - Corresponde a la reserva 4
        for (map<int, Reserva *>::iterator it=reservas.begin();it!=reservas.end();++it){
            Reserva *r=it->second;
            if (r->getHuesped()->getEmail()=="pippin@mail.com" 
                && r->getHabitacion()->getHostal()->getNombre()=="Caverna Lujosa"
                && r->getHabitacion()->getNumero()==1 
                && r->getCheckin()==in4
                && r->getCheckOut()==out4 )
                    res4=it->second;
        }
        Estadia* est6 = CRes->DPRegistrarEstadia(res4,"seba@mail.com",new DTFecha(7,6,2022,18));
        */

        //PENDEINTE IMPLEMENTACIÓN DEL CASO DE USO ANTONIOOOOOOOOOOOO!!!!
        //Finalización de estadías 
        cout << "OBSERVACIÓN: No fue posible implementar la finalización de estadías porque Antonio estuvo ausente\n";
        //void CUFinalizarEstadia(Estadia*,DTFecha checkout);
        //CRes->DPFinalizarEstadia(est1,DTFecha(10,5,2022,9));
        //CRes->DPFinalizarEstadia(est2,DTFecha(5,1,2001,2));
        //CRes->DPFinalizarEstadia(est6,DTFecha(15,6,2022,22));

        //est1=est2=est3=est4=est5=est6=NULL; //para evitar el warning al compilar

        //Califiacion de estadías
        //CCal->registrarCalificacion(CHos->getPunteroHostal("La posada del finger"),est1->getCodigo(),3,"Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.");

        //Calificacion* cal1 = CCal->DPCalificarEstadia(est1,,3,DTFecha(11,5,2022,18));
        //Calificacion* cal2 = CCal->DPCalificarEstadia(est2,"Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.",2,DTFecha(5,1,2001,3));
        //Calificacion* cal3 = CCal->DPCalificarEstadia(est6,"Había pulgas en la habitación. Que lugar más mamarracho!!",3,DTFecha(15,6,2022,23));
        
        //Comentarios de calificacion
        //CCal->DPComentarCalifiacion(cal2,"barli@mail.com","Desapareció y se fue sin pagar.",DTFecha(6,1,2001,15));        


    } catch(const exception& e) {
        throw invalid_argument(e.what());
    }
    

}