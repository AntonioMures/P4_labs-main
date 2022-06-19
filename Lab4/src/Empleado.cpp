#include <string>
#include <set>
#include "../include/Empleado.h"
#include "../include/ControladorHostal.h"


Empleado::Empleado(string nom, string email, string pass, DTCargoEmpleado car,bool recibeNotif):Usuario(nom,email,pass){
    Cargo=car;
    recibeNotificaciones=recibeNotif;
};

DTCargoEmpleado Empleado::getCargo(){
    return Cargo;
};

bool Empleado::getRecibeNotificaciones(){
    return recibeNotificaciones;
};

void Empleado::setCargo(DTCargoEmpleado c){
    Cargo=c;
};

DTEmpleado Empleado::getDatosEmpleado(){
    DTEmpleado dte = DTEmpleado(getNombre(),getEmail(),getPassword(),Cargo,recibeNotificaciones);
    return dte;
};

void Empleado::setRecibeNotificaciones(bool n){
    if (n && Cargo!=Desempleado){
        recibeNotificaciones=n;
        //además hay que agregar todas las califiaciones sin respuesta ( void notificar() )
        ControladorHostal* ich=ControladorHostal::getInstancia();
        string nombreHostal = ich->getHostalDeEmpleado(dynamic_cast<Usuario*>(this)->getEmail());
        map<int, Calificacion *> califs = ich->calificacionesHostal(nombreHostal);
        for (map<int, Calificacion *>::iterator it=califs.begin();it!=califs.end();++it)
            notificar(it->second,ich->getPunteroHostal(nombreHostal));
    } else if (n && Cargo==Desempleado)
        throw invalid_argument("No se puede suscribir a notifiaciones pues no es empleado de un Hostal");
    else
        CalifPendientes.clear();
};

void Empleado::notificar(Calificacion* c, Hostal* h){
    map<string, Empleado*> empleadosHostal = h->getEmpleados();
    //Si el empleado está en .setEmpleados() de h, agrega c
    string email = this->getEmail();
    if (empleadosHostal[email]!= NULL && !c->CalificacionConRespuesta())
        CalifPendientes.insert(make_pair(c->getId(),c));
    
};

void Empleado::removerNotif(Calificacion* c, Hostal* h){
    map<string, Empleado*> empleadosHostal = h->getEmpleados();
    //Si el empleado está en .setEmpleados() de h, elimina c
    string email = this->getEmail();
    if (empleadosHostal[email]!= NULL && !c->CalificacionConRespuesta())
                CalifPendientes.erase(c->getId());
};

map<int,Calificacion*> Empleado::consultarNotificaiones(){
    return CalifPendientes;
};

Empleado::~Empleado(){};
