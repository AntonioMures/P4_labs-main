#include "include/DatosDePrueba.h"
#include "include/DTHostal.h"
#include "include/DTEstadia.h"
#include "include/DTEmpleado.h"
#include "include/DTCalificacion.h"
#include "include/DTHabitacion.h"
#include "include/DTHuesped.h"
#include "include/IControladorCalificacion.h"
#include "include/IControladorHostal.h"
#include "include/IControladorReservas.h"
#include "include/IControladorUsuarios.h"
#include "include/Fabrica.h"
#include "include/Utils.h"

#include <map>
#include <string>
#include <iostream>
//#include "include/DTCargoEmpleado.h"

const string LINEA="------------------------------";

using namespace std;

Fabrica fab = Fabrica();
IControladorHostal* iHostal = fab.getInstanciaConHos();
IControladorUsuarios* iUsuario = fab.getInstanciaConUsu();
IControladorReservas* iEstadia = fab.getInstanciaConRes();
IControladorCalificacion* iCalificacion = fab.getInstanciaConCal();
IFechaSistema* iFechaSistema = fab.getInstanciaFechaSis();


//En el merge se generó este alias
IControladorReservas* iReserva = iEstadia;

DTFecha fechaNula=DTFecha();
DTFecha * CrearFechaPorConsola(DTFecha cotaInferior){
     DTFecha* nueva;
     int d,m,a,h;
     bool cota = false;
     //while (nueva <= &cotaInferior){
     while ( !cota ){
          cout << "Ingrese el día: ";
          cin >> d;
          cout << "Ingrese el mes: ";
          cin >> m;
          cout << "Ingrese el año: ";
          cin >> a;
          cout << "Ingrese la hora: ";
          cin >> h;
          nueva = new DTFecha(d,m,a,h);
          
          if (nueva <= &cotaInferior)
               throw invalid_argument("La fecha ingresada no es correcta o supera la cota fijada");
          else
               cota = true;
     }
     return nueva;
}

//Pre: h es un DTHuesped válido
void mostrarDatosCompletosHuesped(DTHuesped h){
     cout << "email: " << h.getEmail() << "\n";
     cout << "Nombre: " << h.getNombre() << "\n";
     if (h.getFinger())
          cout << "Es Finger\n";
     else  cout << "No es Finger\n"; 
     cout << "Password: " << h.getPassword() <<"\n";
     cout << "---\n";
}

//Pre: e es un DTEmpleado válido
void mostrarDatosCompletosEmpleado(DTEmpleado e){
     cout << "email: " << e.getEmail() << "\n";
     cout << "Nombre: " << e.getNombre() << "\n";
     cout << "Cargo: " << CargoEmpleadoString(e.getCargo())<<"\n";
     cout << "Suscrpto a notificaciones: ";
     if (e.getRecibeNotificaciones())
          cout <<"SI\n";
     else
          cout <<"NO\n";
     cout << "Password: " << e.getPassword()<<"\n";
     cout << "---\n";
}

void mostrarHuespedes(bool soloMail){
     cout << "Huéspedes:\n";
     map<string, DTHuesped> listaHuespedes = iUsuario->listarHuespedes();
     for (map<string, DTHuesped>::iterator itu=listaHuespedes.begin();itu!=listaHuespedes.end();++itu){
          if (soloMail){
               cout << "email: ";
               cout << itu->first <<"\n";
          } else
               mostrarDatosCompletosHuesped(itu->second);
     }
     cout << "---\n";
}

void mostrarEmpleados(bool soloMail){
     cout << "Empleados:\n";
     map<string, DTEmpleado> listaEmpleados = iUsuario->listarEmpleados();
     for (map<string, DTEmpleado>::iterator itu=listaEmpleados.begin();itu!=listaEmpleados.end();++itu){
          if (soloMail){
               cout << "email: ";
               cout << itu->first <<"\n";
          } else
               mostrarDatosCompletosEmpleado(itu->second);
     }
     cout << "---\n";
}

void mostrarReserva(DTReserva r){
     cout << "Código: " << r.getCodigo() << "\n";
     cout << "Estado: " << estadoReservaString(r.getEstado()) << "\n";
     cout << "CheckIn: " << r.getCheckIn() << "\n";
     cout << "CheckOut: " << r.getCheckOut() << "\n";
     cout << "Costo total de la reserva: $" << r.getCosto() << "\n";
     cout << "---\n";
}

void mostrarHostales(){
     //Mostrar Hostales
     cout << "-- Lista de Hostales --" << endl;
     map<string,DTHostal> hostales=iHostal->listarHostales();
     for (map<string,DTHostal>::iterator it=hostales.begin();it!=hostales.end();++it){
          cout << "---> " << it->first << endl;
     }
}

//Se cambió la lógica, se limpió recursividad
void altaDeUsuario(){
     try {
          string nombre, email, password;
     
          bool esFinger;

          bool seguir=true;

          while (seguir){
               cout << "Ingresar Email: ";
               cin >> email;
               if (iUsuario->existeUsuario(email)){
                    seguir=false;
                    throw invalid_argument("Usuario existente en el sistema");
               }
               
               cout << "Ingresar Nombre: "<< endl;
               cin >> nombre;
               cout << "Ingresar password: "<< endl;
               cin >> password;
               cout << "¿Desea agregar un Huesped o un Empleado?" << endl;
               cout << "1. Huesped" << endl;
               cout << "2. Empleado" << endl;
               int eleccion;
               cin >> eleccion;
               if(eleccion == 1){
                    cout << "Ingresar 1 si es Finger, 0 sino: ";
                    cin >> esFinger;
                    cout << "- Información del Huesped -" << endl;
                    cout << "Nombre: " << nombre << endl;
                    cout << "Email: " << email << endl;
                    cout << "Password: " << password << endl;
                    cout << "¿Finger?: " << (esFinger ? "Si" : "No") << endl;
                    cout << "¿Desea confirmar el huesped?" << endl;
                    cout << "1. SI" << endl;
                    cout << "2. NO" << endl;
                    int agregar_h;
                    cin >> agregar_h;
                    if(agregar_h == 1){
                         try{
                              iUsuario->ConfirmarHuesped(nombre,email, password, esFinger);
                              cout << "Huesped ingresado correctamente" << endl;
                         }catch(const std::exception& err){
                              cout << err.what() << endl;
                              return;
                         }   
                    } else {
                         cout << "Huesped no ingresado" << endl;
                         return;
                    }
               } else if(eleccion == 2){
                    cout << "- Información del Empleado -" << endl;
                    cout << "Nombre: " << nombre << endl;
                    cout << "Email: " << email << endl;
                    cout << "Password: " << password << endl;
                    cout << "¿Desea confirmar el empleado?" << endl;
                    cout << "1. SI" << endl;
                    cout << "2. NO" << endl;
                    int agregar_e;
                    cin >> agregar_e;
                    if(agregar_e == 1){
                         try{
                              iUsuario->ConfirmarEmpleado(nombre,email, password, false); 
                              cout << "Empleado ingresado correctamente" << endl;
                         }catch(const std::exception& err){
                              cout << err.what() << endl;
                              return;
                         }   
                    } else 
                         cout << "Empleado no ingresado" << endl;
               } else 
                    cout << "Opción incorrecta" << endl;

               cout << "¿Desea continuar agregando usuarios?" << endl;
               cout << "1. SI" << endl;
               cout << "2. NO" << endl;
               int resp;
               cin >> resp;
               if (resp!=1)
                    seguir=false;
               


          /*
          bool agregado_u = true;
          while(agregado_u){
               cout << "Ingresar Email: ";
               cin >> email;
               try{
                    if(iUsuario->existeUsuario(email)){ 
                         throw invalid_argument("Usuario existente en el sistema");
                    } 
                    else{
                         agregado_u = false; 
                    }
               }
               catch(const invalid_argument& err){
                    cout << err.what() << endl;
                    
                    if (resp == 1) {
                         altaDeUsuario();
                         agregado_u = false;
                         return;
                    } else {
                         return;
                    }
               }
          }*/
          
          }

     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
};


void altaDeHostal(){
          string nombre, direccion;
          int telefono;
          
          cout << "Ingrese el nombre del Hostal: ";
          cin >> nombre;
          cout << "Ingrese telefono: "<< endl;
          cin >> telefono;
          cout << "Ingrese direccion: "<< endl;
          cin >> direccion;
          cout<< "- Informacion del Hostal -" << endl;
          cout<< "Nombre: " << nombre << endl;
          cout<< "Telefono: " << telefono << endl;
          cout<< "Direccion: " << direccion << endl;
          cout << "¿Desea confirmar el hostal?" << endl;
          cout << "1. SI" << endl;
          cout << "2. NO" << endl;
          int agregar_host;
          cin >> agregar_host;
          if(agregar_host == 1){
               try{
                    iHostal->ConfirmarHostal(nombre, telefono, direccion);
                    cout << "Hostal ingresado correctamente" << endl;
               }catch(const std::exception& err){
                    cout << err.what() << endl;
                    return;
               }
          } else{
               cout << "Hostal no ingresado" << endl;
               return;
          }
     }

void realizarReserva(){
     try{
          mostrarHostales();

          //Elegir Hostal
          string eleccionHostal;
          cin >> eleccionHostal;
          if (!iHostal->existeHostal(eleccionHostal))
               throw invalid_argument("El hostal no existe");
 
          //Ingresar Datos de Reserva
          cout << "Por favor ingrese una fecha para el CheckIn";
          DTFecha *in=CrearFechaPorConsola(fechaNula);
          cout << "Por favor ingrese una fecha para el CheckOut";
          DTFecha *out=CrearFechaPorConsola(*in);
          string tipo;
          while (tipo!="i" && tipo!="I" && tipo!="g" && tipo!="G"){
               cout << "¿Es una reserva Individual o Grupal? (I/G)";
               cin >> tipo;
          }
          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
          if (tipo=="i" || tipo =="I" || tipo=="g" || tipo =="G"){
               if (in>out)
                    throw invalid_argument("La fecha de CheckIn no puede ser mayor que la fecha de Check Out");
          } else
               throw invalid_argument("Ha ingresado un tipo de reserva no válido");

          //map<NumeroHab,CapacidadDisponible> de habitaciones disponibles para esa fecha
          map<int,int> habs=iHostal->listarHabitacionesDisponibles(eleccionHostal,*in,*out);
          cout << "Por favor, indique la habitación de su preferencia:\n";
          cout << "(digite el número de habitación) \n";
          for (map<int,int>::iterator ith=habs.begin();ith!=habs.end();++ith){
               if (ith->second!=0){
                    DTHabitacion h=iHostal->mostrarDatosHabitacion(eleccionHostal,ith->first);
                    cout << "Habitación " << ith->first << ": \n";
                    cout << "    Capacidad: " << h.getCapacidad() << "huéspedes\n";
                    cout << "    Quedan  " << ith->second << " camas disponibles para las fechas elegidas\n";
                    cout << "    Precio: $" << h.getPrecio() << "\n";
               }
          }
          
          //Elegir Habitación
          int numHab;
          cin >> numHab;
          if (!iHostal->existeHabitacion(numHab,eleccionHostal))
               throw invalid_argument("La habitación elegida no es correcta");
          int camasDisponiblesHab=iReserva->CamasDispEnHab(eleccionHostal,numHab,*in,*out);
          if (camasDisponiblesHab==1 && (tipo=="g" || tipo =="G")){
               cout << "IMPORTANTE: La habitación elegida sólo tiene 1 cama disponible para ese período\n Se continuará como reserva individual";
               tipo="i";
          }
          camasDisponiblesHab--;
               

          //Listar Huéspedes
          map<string, DTHuesped> listaHuespedes=iUsuario->listarHuespedes();

          //Para filtrar que no agreguen en Reserva Grupal mails no válidos o del que hace la reserva
          set<string> mailsHuespedesDisponibles;

          cout << "Por favor, indique el huésped que realiza la reserva:\n(digite el email) \n";
          for (map<string, DTHuesped>::iterator itu=listaHuespedes.begin();itu!=listaHuespedes.end();++itu){
               cout << "---\nemail: " << itu->first <<"\n";
               cout << "Nombre: " << itu->second.getNombre() <<"\n";
               if (itu->second.getFinger())
                    cout << "Es Finger\n---\n";
               else  cout << "No es Finger\n---\n";
               mailsHuespedesDisponibles.insert(itu->first);
          }

          //Elegir Huésped que realiza la reserva
          string mail;
          cin >> mail;
          if (!iUsuario->existeHuesped(mail))
               throw invalid_argument("El mail no corresponde a un usuario");
          mailsHuespedesDisponibles.erase(mail);

          //Elegir los demás huéspedes para reserva grupal, del conjunto construido quedará una copia en la reserva grupal, si corresponde
          map<string,DTHuesped> conjHuespedes;
          //Agrego al huésped que reservó
          conjHuespedes.insert(make_pair(mail, iUsuario->datosHuesped(mail) ));
          string mas="s";
          while ((tipo=="g" || tipo =="G") && camasDisponiblesHab!=0 && (mas=="s" || mas=="S")){
               string otro;
               cout << "Digite el email del siguiente huésped: ";
               cin >> otro;
               if (mailsHuespedesDisponibles.find(otro)==mailsHuespedesDisponibles.end())
                    cout << "No se puede agregar " << otro << ", el huesped no existe o ya fué agregado\n";
               else {
                    conjHuespedes.insert(make_pair(otro,iUsuario->datosHuesped(otro)));
                    mailsHuespedesDisponibles.erase(otro);
                    camasDisponiblesHab--;
               }
               if (camasDisponiblesHab!=0){
                    cout << "¿Desea agregar más huéspedes a la reserva? (S/N)";
                    cin >> mas;
               }
          }

          //Confirmación de nueva reserva
          string ok;
          cout << "¿Desea confirmar esta reserva? (S/N)";
          cin >> ok;
          if (ok=="s" || ok=="S")
               if (tipo=="i" || tipo=="I")
                    iReserva->confirmarReservaIndividual(eleccionHostal,numHab,mail,in,out);
               else 
                    iReserva->confirmarReservaGrupal(eleccionHostal,numHab,mail,in,out,conjHuespedes);
          else
               iReserva->LiberarMemoria();  


     } catch(const std::exception& e) {
          
          cout << e.what() << '\n';
     }
}

void registrarEstadia(){
     try {
          //Mostrar Hostales
          cout << "Por favor, elija un hostal:\n";
          map<string,DTHostal> hostales=iHostal->listarHostales();
          for (map<string,DTHostal>::iterator it=hostales.begin();it!=hostales.end();++it)
               cout << "* " << it->first << "\n";

          //Elegir Hostal
          string eleccionHostal;
          cin >> eleccionHostal;
          if (!iHostal->existeHostal(eleccionHostal))
               throw invalid_argument("El hostal no existe");

          //Ingreso de email de un huésped
          cout << "Por favor, elija el email del huésped que inicia su estadía:\n";
          string emailHuesped;
          mostrarHuespedes(true);
          cin >> emailHuesped;
          if (!iUsuario->existeHuesped(emailHuesped))
               throw invalid_argument("El mail no corresponde a un usuario");

          //Muestra la lista de reservas no canceladas del huésped en las cuales el huésped está registrado como parte de la reserva en ese hostal
          cout << "Se muestran las reservas de " << iUsuario->listarHuespedes().find(emailHuesped)->second.getNombre() << "\n";
          map<int,DTReserva> res = iReserva->listarReservasNoCanceladasDelHuesped(emailHuesped);
          for (map<int,DTReserva>::iterator it=res.begin(); it!=res.end(); ++it)
               mostrarReserva(it->second);
          cout << "---\n";
          
          cout << "Ingrese el código de la reserva:\n";
          int codReserva;
          cin >> codReserva;

          //altaEstadia
          iReserva->altaEstadia(codReserva,emailHuesped);

    } catch(const std::exception& e) {
     cout << e.what() << '\n';
    }
};

void calificarEstadia(){
          
     string nombre, email, comentario;
          
     int identificador, puntuacion;
          
     cout << "Lista de hostales: "<< endl;

     map<string, DTHostal> hostales = iHostal->listarHostales();
     
     map<string, DTHostal>::iterator iter = hostales.begin();
     while(iter != hostales.end()){
          cout << "Nombre:" << iter->second.getNombre() << endl;
          ++iter;
     }

     cout << "Ingrese el Nombre del Hostal que desea elegir: "<< endl;
     cin >> nombre;

     Hostal* hostElegido = iHostal->getPunteroHostal(nombre); 

     cout << "Lista de huespedes: "<< endl;

     map<string, DTHuesped> huespedes = iUsuario->listarHuespedes();
     
     map<string, DTHuesped>::iterator iterH = huespedes.begin();
     while(iterH != huespedes.end()){
          cout << "Email:" << iterH->second.getEmail() << endl;
          ++iterH;
     }

     cout << "Ingrese el email del huesped al cual quiere consultar las estadias: "<< endl;
     cin >> email;

     map<int, DTEstadia> estadias = iEstadia->listarEstadiasHuesped(email, nombre);
     if(!estadias.empty()){
          map<int, DTEstadia>::iterator iterEs = estadias.begin();
          while(iterEs != estadias.end()){
               cout << "Fecha de check in:" << iterEs->second.getCheckInEstadia()->getDia() << "/" << iterEs->second.getCheckInEstadia()->getMes() << "/" << iterEs->second.getCheckInEstadia()->getAnio() << endl;
               cout << "Promo:" << iterEs->second.getPromo() << endl;
               cout << "Puntuacion:" << iterEs->second.getCal() << endl;
               cout << "Identificador de la estadia:" << iterEs->first << endl;
               ++iterEs;
          }
     } else {
          cout << "No se encontraron estadias: "<< endl;
          return;
     }
     
     cout << "Ingrese el Identificador de la estadia que desea elegir: "<< endl;
     cin >> identificador;
     
     cout << "Ingrese la puntuacion de la calificacion a la estadia: "<< endl;  
     cin >> puntuacion;

     cout << "Ingrese el comentario de la calificacion a la estadia: ";
     getline(cin, comentario);

     iCalificacion->registrarCalificacion(hostElegido, identificador, puntuacion, comentario);

     }

/*--------------------------------
--------Alta de Habitacion--------
----------------------------------*/
void altaDeHabitacion(){
     string hostal, op;
     int numHab, capacidad;
     float precio;
     
     /*map<string, DTHostal> listaHost = iHostal->listarHostales();
     
     cout << "-- LISTA DE HOSTALES --" << endl;
     for (map<string, DTHostal>::iterator it = listaHost.begin(); it != listaHost.end(); ++it) {
          cout << (it->first) << endl;
     }*/
     mostrarHostales();

     cout << "Por favor escriba el nombre del hostal seleccionado: " << endl;
     cin >> hostal;

     //Habria que poner esto en un try-catch
     //if (iHostal->existeHostal(hostal))
     //     throw invalid_argument("El hostal no existe");

     cout << "Ingrese numero de habitacion: ";
     cin >> numHab;
     cout << "Ingrese precio de habitacion: ";
     cin >> precio;
     cout << "Ingrese capacidad de habitacion: ";
     cin >> capacidad;

     cout << "-- Datos ingresados --" << endl;
     cout << "Numero: " << numHab << endl << "Precio: " << precio << endl << "Capacidad: " << capacidad << endl;

     cout << "Confirmar habitacion? S/N: ";
     cin >> op;

     if( op == "S" || op== "s" ){
          try{
               iHostal->confirmarHabitacion(hostal, numHab, precio, capacidad);
          }catch(const std::exception& err){
               cout << err.what() << endl;
               return;
          }
     }
}

/*--------------------------------
--------Consulta de Estadia-------
----------------------------------*/

void consultaEstadia() {

     try {

          string hostal;
          int estadia;

          map<string, DTHostal> listaHost = iHostal->listarHostales();

          cout << "-- LISTA DE HOSTALES --" << endl;
          int i = 1;
          for (map<string, DTHostal>::iterator y = listaHost.begin(); y != listaHost.end(); ++y) {
               cout << i << ". "<< (y->first) << endl;
               i++;
          }
               
          cout << "Por favor escriba el nombre del hostal seleccionado: " << endl;
          cin >> hostal;

          map<int, DTEstadia> listaEst = iEstadia->listarEstadiasHostal(hostal);
          cout << "-- LISTA DE ESTADIAS --" << endl << endl;
          if (listaEst.empty() == true) {
               return;
          } else {
               for (map<int, DTEstadia>::iterator t = listaEst.begin(); t != listaEst.end(); ++t) {
                    cout << "Estadia numero: " << (t->first) << endl;
                    cout << "Huesped de la estadia: " << (t->second.getHues()) << endl << endl;
               }
          }     

          cout << "Por favor escriba el numero de la estadía seleccionada: " << endl;
          cin >> estadia;

          DTEstadia esta = iEstadia->mostrarDatosEstadia(estadia);
          cout << "-- INFORMACION AMPLIADA --" << endl;
          cout << "Hostal: " << (hostal) << endl;
          cout << "Habitacion: " << (esta.getHab()) << endl;
          cout << "Huesped de la estadia: " << (esta.getHues()) << endl;
          cout << "Codigo de la reserva asociada: " << (estadia) << endl;
          cout << "CheckIn: " << (esta.getCheckInEstadia()->getDia()) << "/" << (esta.getCheckInEstadia()->getMes()) << "/" << (esta.getCheckInEstadia()->getAnio()) << endl;
          if (esta.getCheckOutEstadia() == nullptr) {
               cout << "CheckOut: Esta estadía aun no ha efectuado el checkout" << endl;
          } else {
               cout << "CheckOut: " << (esta.getCheckOutEstadia()->getDia()) << "/" << (esta.getCheckOutEstadia()->getMes()) << "/" << (esta.getCheckOutEstadia()->getAnio()) << endl;
          }
          cout << "Promoción: " << (esta.getPromo()) << endl;
          cout << "Consumos: No aplica" << endl;
          cout << "Costo total: " << (esta.getCosto()) << endl;
          cout << "--------" << endl;

          cout << "Desea ver informacion sobre la calificacion de la estadia? (S/N)" << endl;
          string resp;
          cin >> resp;
          if ((resp == "S") || (resp == "s")) {
               string resp = "";
               DTCalificacion cal = iEstadia->verCalificaion(estadia, resp);
               if (cal.getPuntuacion() == 0) {
                    cout << "Esta estadia aun no ha sido calificada" << endl;
               } else {
                    cout << "-- CALIAFICACION DE LA ESTADIA --" << endl;
                    cout << "Puntuacion: " << (cal.getPuntuacion()) << endl;
                    cout << "Fecha de la calificacion: " << (cal.getFecha()->getDia()) << "/" << (cal.getFecha()->getMes()) << "/" << (cal.getFecha()->getAnio()) << endl;
                    cout << "Comentario: " << (cal.getComentario()) << endl;
                    cout << "Respuesta: " << (resp) << endl;
               }
          }
          resp = "N";

          cout << "Desea ver informacion sobre la reserva asociada a la estadia? (S/N)" << endl;
          cin >> resp;
          if ((resp == "S") || (resp == "s")) {
               DTReserva res = iEstadia->reservaAsociada(estadia);
               cout << "-- RESERVA ASOCIADA --" << endl;
               cout << "Hostal: " << (hostal) << endl;
               cout << "Habitacion: " << (esta.getHab()) << endl;
               cout << "Huesped de la estadia: " << (esta.getHues()) << endl;
               cout << "Checkin de reserva: " << (res.getCheckIn()->getDia()) << "/" << (res.getCheckIn()->getMes()) << "/" << (res.getCheckIn()->getAnio()) << endl;
               cout << "Checkout de reserva: " << (res.getCheckOut()->getDia()) << "/" << (res.getCheckOut()->getMes()) << "/" << (res.getCheckOut()->getAnio()) << endl;

          }
     } catch (const std::exception& err) {
               cout << err.what() << endl;
               return;
     }
}



/*-------------------------------
------Comentar Calificacion------
---------------------------------*/
void comentarCalificacion(){
     mostrarEmpleados(true);
     string emailEmpleado, respuesta;
     int opcion;

     cout << "Ingrese email de empleado:" << endl;
     cin >> emailEmpleado;

     map<int, DTCalificacion> comentarios = iCalificacion->listarComentarios(emailEmpleado);
     if (comentarios.size()==0)
          cout << "El hostal al que pertenece el empleado no tiene comentarios por calificar\n";
     else 
          try {
               
               for(map<int, DTCalificacion>::iterator iter = comentarios.begin(); iter != comentarios.end(); ++iter){
                    cout << "-- Calificacion: " << iter->first << " --" << endl;
                    cout << "Puntuacion: " << iter->second.getPuntuacion() << endl;
                    cout << "Comentario: " << iter->second.getComentario() << endl;
                    cout << "Fecha: " << iter->second.getFecha()->getDia() << "/" << iter->second.getFecha()->getMes() << "/" << iter->second.getFecha()->getAnio() << " - " << iter->second.getFecha()->getHora() << endl;
               }

               cout << "Que calificacion desea comentar? ";
               cin >> opcion;
               iCalificacion->elegirCalificacion(opcion);

               cout << "Respuesta:" << endl;
               cin >> respuesta;

               iCalificacion->registrarComentario(respuesta);

          } catch(const std::exception& e)  {
               cout << e.what() << '\n';
          }
          
}

void consultaDeUsuario(){
     try {
          
          //Listar Usuarios
          cout << "Por favor ingrese el email del usuario que desea consultar:\n";
          mostrarHuespedes(true);
          mostrarEmpleados(true);
          cout << "Ingrese el email del empleado a consultar: ";

          //Elegir usuario
          string email;
          cin >> email;
          map<string, DTHuesped> listaHuespedes = iUsuario->listarHuespedes();
          map<string, DTHuesped>::iterator itLHsp=listaHuespedes.find(email);
          map<string, DTEmpleado> listaEmpleados = iUsuario->listarEmpleados();
          map<string, DTEmpleado>::iterator itLEmp=listaEmpleados.find(email);
          if (itLHsp!=listaHuespedes.end())
               mostrarDatosCompletosHuesped(itLHsp->second);
          else if (itLEmp!=listaEmpleados.end())
               mostrarDatosCompletosEmpleado(itLEmp->second);
          else
               throw invalid_argument("El email ingresado no corresponde a un usuario");

     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
};



/*--------------------------------
--------Consulta de Hostal-------
----------------------------------*/
void ConsultaDeHostal() {
    /*El sistema lista todos los hostales registrados y el usuario selecciona uno. A
    continuación, el sistema lista la información básica del hostal (pero incluyendo
    también promedio de calificaciones, así como los comentarios y calificaciones de las
    habitaciones), así como la información de las habitaciones que posee y sus tipos de
    consumo. Además, lista las reservas que se han hecho en ese hostal, sea cual sea su estado*/

    //Mostrar Hostales
    cout << "Por favor, elija un hostal:\n";
    map<string,DTHostal> hostales=iHostal->listarHostales();
    for (map<string,DTHostal>::iterator it=hostales.begin();it!=hostales.end();++it)
        cout << "* " << it->first << "\n";

    //Elegir Hostal
    string eleccionHostal;
    cin >> eleccionHostal;  
    cout << "Mostrando Informacion basica del hostal.\n";
    cout << "Promedio de calificaciones :" << iHostal->getPunteroHostal(eleccionHostal)->calificacionPromedio() << "\n";
    cout << "Mostrando habitaciones del hostal.\n";
    map<int, DTHabitacion> habitaciones = iHostal->getPunteroHostal(eleccionHostal)->mostrarHabitaciones();
    for (map<int, DTHabitacion>::iterator it=habitaciones.begin(); it!= habitaciones.end();++it){
        cout << "Numero de habitacion: " << it->second->getNumero() << "\n";
        cout << "Precio de la habitacion: " << it->second->getPrecio() << "\n";
        cout << "Capacidad de la habitacion: " << it->second->getCapacidad() << "\n";
    }
    iReserva->elegirHostal(eleccionHostal); 

    map<int, DTReserva> reservas=iReserva->listarReservasHostal();
    if (reservas.size()==0)
    cout << "El hostal " << eleccionHostal << " aún no tiene reservas\n";
    else {
        //Listar reservas
        cout << "Reservas del hostal " << eleccionHostal << "\n";
        for (map<int, DTReserva>::iterator it=reservas.begin(); it!=reservas.end(); ++it)
        mostrarReserva(it->second);
        cout << "---\n";
    }
}



/*--------------------------------
--------Finalizar Estadia-------
----------------------------------*/
void finalizarEstadia(){
    //Mostrar Hostales
    cout << "Por favor, elija un hostal:\n";
    map<string,DTHostal> hostales=iHostal->listarHostales();
    for (map<string,DTHostal>::iterator it=hostales.begin();it!=hostales.end();++it)
        cout << "* " << it->first << "\n";

    //Elegir Hostal
    string eleccionHostal;
    cin >> eleccionHostal;
    iHostal->elegirHostal(eleccionHostal);

    //Indicar Mail del huesped 
    cout << "Por favor, elija su Mail\n";
    string emailHuesped;
    mostrarHuespedes(true);
    cin >> emailHuesped;

    //Buscar estadia activa
    DTEstadia estadiaActiva = estadiaActivaHuesped(emailHuesped);

    //Ingresar Fecha checkOut
    cout << "Por favor ingrese una fecha para el CheckOut";
    DTFecha *out=CrearFechaPorConsola(*in);
    DTFecha checkIn = estadiaActiva->getCheckInEstadia();
    if (CheckIn > out)
        throw invalid_argument("La fecha de CheckIn no puede ser mayor que la fecha de Check Out");
    finalizarEstadiaActiva(out,estadiaActiva);
    cout << "Estadia finalizada correctamente.";
}



/*--------------------------------
---------Consulta Top 3-----------
----------------------------------*/

void consultaTop3() {
     try {
          
          map<string,float> total = iHostal->mostrarTop3Hostales();
          cout << "-- TOP 3 HOSTALES --" << endl << endl;

          //nueva lógica, vienen todos los hostales a mostrar desde el controlador
          map<string,float>::iterator t = total.end();
          //--t;
          //for (int i=1; i<=3; i++) {
          //     DTHostal actual = t->second;
          //     cout << i <<".Nombre: " << (actual.getNombre()) << endl;
          //     cout << "Calificacion: " << (t->first) << endl << endl;
          //     --t;
          //}
          //t = total.end();
          int i=1;
          for (map<string,float>::iterator it=total.begin();it!=total.end();++it){
               cout << "HOSTAL NÚMERO " << i <<":\n";
               cout << "Nombre: " << it->first << endl;
               cout << "Calificacion: " << it->second << endl << endl;
          }

          cout << "¿Desea ampliar la informacion de alguno de ellos? (S/N)" << endl;
          string resp;
          cin >> resp;

          if ((resp == "S") || (resp == "s")) {
               cout << "Por favor elija 1, 2 o 3 para ampliar informacion" << endl;
               int elec;
               cin >> elec;
               for (int i=1; i<=elec; i++) {
                    --t;       
               }
               DTHostal elegido = iHostal->datosHostal(t->first);//Cambió porque se usa el nombre como clave
               map<int,DTCalificacion> cali = iHostal->datosCalificacionesHostal(elegido.getNombre());
               cout << "-- CALIFICACIONES DE HOSTAL --" << endl << endl;
               for (map<int,DTCalificacion>::iterator t = cali.begin(); t != cali.end(); ++t) {
                    DTCalificacion actual = t->second;
                    cout << "Calificacion: " << (actual.getPuntuacion()) << endl;
                    cout << "Comentario: " << (actual.getComentario()) << endl << endl;
               }
          }
     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
};

/*--------------------------------
----Asignar empleado a Hostal-----
----------------------------------*/

void asignarEmpleadoHostal() {
     try {
          string hostal, empleado, resp, email;
          int cargo;
          map<string, DTHostal> listaHost = iHostal->listarHostales();
          map<string,DTEmpleado> listaEmp = iUsuario->listarEmpleados();
          if (listaEmp.empty() || listaHost.empty())
               throw invalid_argument("La opción no está disponible pues no hay empleados u hostales en el sistema");

          cout << "-- LISTA DE HOSTALES --" << endl;
          int i = 1;
          for (map<string, DTHostal>::iterator y = listaHost.begin(); y != listaHost.end(); ++y) {
               cout << i << ". "<< (y->first) << endl;
               i++;
          }
               
          cout << "Por favor escriba el nombre del hostal seleccionado: " << endl;
          cin >> hostal;


          cout << "-- LISTA DE EMPLEADOS --" << endl;
          i=1;
          for (map<string,DTEmpleado>::iterator u = listaEmp.begin(); u != listaEmp.end(); ++u) {
               DTEmpleado actual = u->second;
               if (iHostal->getHostalDeEmpleado(actual.getEmail()) != hostal) {
                    cout << i << ". Nombre: "<< (actual.getNombre()) << "// Mail: " << (actual.getEmail()) << endl << endl;
               }
               i++;
          }

          cout << "Por favor escriba el Email del empleado seleccionado: " << endl;
          cin >> empleado;
          email = listaEmp.find(empleado)->second.getEmail();
          

          cout << "Por favor selecccione el cargo designado mediante su numero correspondiente: " << endl;
          cout << "1 - Administracion" << endl;
          cout << "2 - Limpieza" << endl;
          cout << "3 - Recepcion" << endl;
          cout << "4 - Infraestructura" << endl;

          cin >> cargo;
          DTCargoEmpleado cargEm = static_cast<DTCargoEmpleado>(cargo);

          cout << endl << "Los datos ingrasados hasta el momento son: " << endl << endl;
          cout << "Hostal: " << hostal << endl;
          cout << "Empleado: " << empleado << endl;
          cout << "Cargo: " << cargo << endl << endl; // BUG: Revisar salida del enum

          cout << endl << "¿Desea proceder con la asignacion (S/N)?"<< endl << endl;
          cin >> resp;
          if ((resp != "S") || (resp != "s")) {

               iHostal->asignarEmpleado(email, hostal);
               iUsuario->vincularEmpCargo(email, cargEm);

          }

          cout << endl << "¿Desea continuar asignando empleados (S/N)?"<< endl << endl;
          string resp_aux;
          cin >> resp_aux;
          if ((resp_aux != "S") || (resp_aux != "s")) {
               asignarEmpleadoHostal();

          } else {
               return;
          }

     } catch(const std::exception& e) {

          cout << e.what() << '\n';
     
     }
};


/*--------------------------------
---------Consulta Reserva---------
----------------------------------*/
void consultaReserva(){
     try {

     // Lista hostales
     mostrarHostales();

     string eleccionHostal, res;

     //Elegir Hostal
     cout << endl << "Ingrese nombre del hostal: ";
     cin >> eleccionHostal;
     if (!iHostal->existeHostal(eleccionHostal))
          throw invalid_argument("El hostal no existe");

     // Listar reservas de hostal seleccionado
     map<int, DTReserva> listaRes = iEstadia->listarReservasHostalSeleccionado(eleccionHostal);
     cout << endl <<"-- Lista de Reservas --" << endl << endl;
     if (listaRes.empty() == true) {
          cout << "No hay reservas" << endl;
          return;
     } else {
          for (map<int, DTReserva>::iterator t = listaRes.begin(); t != listaRes.end(); ++t) {
               cout << "-- Informacion detallada --" << endl << endl;
               cout << "Habitacion: " << (t->second.getHabitacion()) << endl;
               cout << "Codigo de la reserva asociada: " << (t->second.getCodigo()) << endl;
               cout << "CheckIn: " << (t->second.getCheckIn()->getDia()) << "/" << (t->second.getCheckIn()->getMes()) << "/" << (t->second.getCheckIn()->getAnio()) << " - " << t->second.getCheckIn()->getHora() << endl;
               cout << "CheckOut: " << (t->second.getCheckOut()->getDia()) << "/" << (t->second.getCheckOut()->getMes()) << "/" << t->second.getCheckOut()->getAnio() << " - " << t->second.getCheckOut()->getHora() << endl;
               cout << "Costo total: " << (t->second.getCosto()) << endl;
               cout << "--------" << endl;
          }
     }

     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
     
}


void bajaDeReserva(){
     try {
         //Mostrar Hostales
          cout << "Por favor, elija un hostal:\n";
          map<string,DTHostal> hostales=iHostal->listarHostales();
          for (map<string,DTHostal>::iterator it=hostales.begin();it!=hostales.end();++it)
               cout << "* " << it->first << "\n";

          //Elegir Hostal
          string eleccionHostal;
          cin >> eleccionHostal;
          if (!iHostal->existeHostal(eleccionHostal))
               throw invalid_argument("El hostal no existe");

          map<int, DTReserva> reservas=iReserva->listarReservasHostal();
          if (reservas.size()==0)
               cout << "El hostal " << eleccionHostal << " aún no tiene reservas\n";
          else {
               //Listar reservas
               cout << "Reservas del hostal " << eleccionHostal << "\n";
               for (map<int, DTReserva>::iterator it=reservas.begin(); it!=reservas.end(); ++it)
                    mostrarReserva(it->second);
               cout << "---\n";

               //Seleccionar reserva
               int codReserva;
               cout << "Escriba el código de la reserva: ";
               cin >> codReserva;
               if (!iReserva->existeReserva(codReserva))
                    throw invalid_argument("El código de reserva no es correcto");

               //Pide confirmación
               string confirmacion;
               cout << "Se borrará la reserva y toda la información asociada a esta.\n";
               cout << "Escriba SI para confirmar la baja\n";
               cin >> confirmacion;
               if (confirmacion=="SI" || confirmacion=="si" || confirmacion=="Si"){
                    //Baja de reseva
                    iReserva->eliminarReserva(codReserva);
                    cout << "La reserva se ha eliminado con éxito\n";
               } else {
                    iReserva->LiberarMemoria(); 
                    cout << "El usuario ha cancelado la baja de la reserva\n";
               }
          }


     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
};


void actualizarFechaDelSistema(){
     try
     {
          int d,m,a,h;
          cout << "-- ACTUALIZANDO FECHA DE SISTEMA --" << endl;
          cout << "Dia actual: ";
          cin >> d;
          cout << "Mes actual: ";
          cin >> m;
          cout << "Año actual: ";
          cin >> a;
          cout << "Hora actual: ";
          cin >> h;
          DTFecha fecha=DTFecha(d,m,a,h);
          iFechaSistema->ActualizarFechaSistema(fecha);
          cout << LINEA;
     }
     catch(const std::exception& e)
     {
          cout << e.what() << '\n';
     }
     

}

//Post: Si existe el mail del empleado digitado, éste será suscripto a notificaciones
void suscribirseANotificaciones(){
     try {

          mostrarEmpleados(true);
          string mail;
          cout << "Por favor ingrese el email del nuevo suscriptor: ";
          cin >> mail;
          iUsuario->suscribirse(mail);
          cout << "Ahora el usuario recibirá notificaciones de calificaiciones\n";

     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
}


void consultaDeNotifiaciones(){
     try {

          mostrarEmpleados(true);
          string mail;
          cout << "Por favor ingrese el email del empleado: ";
          cin >> mail;
          map<int,DTCalificacion> listado = iUsuario->consultarNotificaciones(mail);

     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
};


//Post: Si existe el mail del empleado digitado, éste será suscripto a notificaciones
void eliminarSuscripcion(){
     try {

          mostrarEmpleados(true);
          string mail;
          cout << "Por favor ingrese el email del suscriptor: ";
          cin >> mail;
          iUsuario->eliminarSuscripcion(mail);
          cout << "El usuario ya no recibirá notificaciones de calificaiciones\n";

     } catch(const std::exception& e) {
          cout << e.what() << '\n';
     }
}

void consultarFechaDelSistema(){
     DTFecha f=iFechaSistema->getFechaSistema();
     cout << "El sistema tiene la fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << " " << f.getHora() << " hs.\n";
};


void InicializarFechaMedianteConsola(){
     cout << "La fecha del sistema está sin inicializar, ingrese por favor:\nDía actual: ";
     actualizarFechaDelSistema();
};



int main(){
     cout << LINEA << "\n¡BIENVENIDO!\n" << LINEA << endl;

     //necesario arrancar con esto antes del menú
     actualizarFechaDelSistema();

     bool salida = false;
     int opcion;
     while( !salida ){
          cout << LINEA << endl;;
          cout << "Ahora si, Bienvenido! \nPor favor ingrese una opción:\n";
          cout << "0. Precargar datos iniciales\n";
          cout << "1. Alta de un Usuario\n";
          cout << "2. Alta de un Hostal\n";
          cout << "3. Alta de una Habitación\n";
          cout << "4. Asignar empleado a un hostal\n";
          cout << "5. Realizar una Reserva\n";
          cout << "6. Consultar Top 3 de hostales\n";
          cout << "7. Registrar una Estadía\n";
          cout << "8. Finalizar una Estadia\n";
          cout << "9. Calificar una Estadía\n";
          cout << "10. Comentar la Calificación de una Estadía\n";
          cout << "11. Consultar información de un Usuario\n";
          cout << "12. Consulta información de un Hostal\n";
          cout << "13. Consulta información de una Reserva\n";
          cout << "14. Consultar una Estadía\n";
          cout << "15. Baja de Reserva\n";
          cout << "16. Suscribirse a Notificaciones\n";
          cout << "17. Consulta de Notificaciones\n";
          cout << "18. Eliminar Suscripción\n";
          cout << "19. Modificar Fecha del Sistema\n";
          cout << "20. Consultar Fecha del Sistema\n";
          cout << "21. Salir\n \n";
          cout << "Escriba el número de su opción: ";

          cin >> opcion;
          switch(opcion){
               case 0:
                    DatosDePrueba();
                    break;
               case 1:
                    altaDeUsuario();
                    break;
               case 2:
                    altaDeHostal();
                    break;
               case 3:
                    altaDeHabitacion();
                    break;
               case 4: 
                    asignarEmpleadoHostal();
                    break;
               case 5: 
                    realizarReserva();
                    break;
               case 6: 
                    consultaTop3();
                    break;
               case 7: 
                    registrarEstadia();
                    break;
               case 8: 
                    finalizarEstadia(); 
                    break;
               case 9: 
                    calificarEstadia();
                    break;
               case 10:
                    comentarCalificacion();
                    break;
               case 11:
                    consultaDeUsuario();
                    break;
               case 12:
                    ConsultaDeHostal();
                    break;
               case 13:
                    consultaReserva();
                    break;
               case 14:
                    consultaEstadia();
                    break;
               case 15:
                    bajaDeReserva();
                    break;
               case 16:
                    suscribirseANotificaciones();
                    break;
               case 17:
                    consultaDeNotifiaciones();
                    break;
               case 18:
                    eliminarSuscripcion();
                    break;
               case 19:
                    actualizarFechaDelSistema();
                    break;
               case 20:
                    consultarFechaDelSistema();
                    break;
               case 21:
                    salida = true;
               break;
               default:
                    cout << "La opción elegida no existe\n";
               break;
          }
     }

     delete iHostal;
     delete iUsuario;
     delete iEstadia;
     delete iReserva;
     delete iFechaSistema;

     return 0;
}