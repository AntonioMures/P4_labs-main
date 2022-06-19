
#include "../include/DTCargoEmpleado.h"
#include "../include/ControladorUsuarios.h"
#include "../include/DTEmpleado.h"
#include "../include/Empleado.h"
#include "../include/Huesped.h"
#include "../include/DTHuesped.h"
#include <iostream> //para testing solamente
//using namespace std;

ControladorUsuarios * ControladorUsuarios::instancia = NULL;

ControladorUsuarios::ControladorUsuarios(){};

ControladorUsuarios * ControladorUsuarios::getInstancia(){
    if( instancia == NULL )
        instancia = new ControladorUsuarios();
    return instancia;
};

ControladorUsuarios::~ControladorUsuarios(){};

//FUNCIONES
string ControladorUsuarios::buscarHostal(string email){
    ControladorHostal conHos = ControladorHostal();
    return conHos.getHostalDeEmpleado(email);
}

map<string,DTHuesped> ControladorUsuarios::listarHuespedes(){
    map<string, DTHuesped> res;
    for (map<string,Usuario*>::iterator it=Usuarios.begin(); it!=Usuarios.end(); ++it){
        Huesped* hue = dynamic_cast<Huesped*>(it->second);
        if( hue != NULL ){
            DTHuesped dhue = hue->getDatosHuesped();
            res.insert(map<string, DTHuesped>::value_type(it->first, dhue));
        }
    }
    return res;
};


map<string,DTEmpleado> ControladorUsuarios::listarEmpleados(){
    map<string,DTEmpleado> res;
    for (map<string,Usuario*>::iterator it=Usuarios.begin(); it!=Usuarios.end(); ++it){
        Empleado* emp = dynamic_cast<Empleado*>(it->second);
        if( emp != NULL ){
            DTEmpleado demp = emp->getDatosEmpleado();
            res.insert(map<string, DTEmpleado>::value_type(it->first, demp));
        }
    }
    return res;
};

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorUsuarios::elegirHuesped(string email){
//
//};

Huesped* ControladorUsuarios::obtenerHuesped(string email){
    Usuario* u=Usuarios.find(email)->second;
    Huesped* h=dynamic_cast<Huesped*>(u);
    if (u==NULL || h==NULL)
        throw invalid_argument("El email no corresponde a un huésped");
    else
        return h;
};

DTHuesped ControladorUsuarios::datosHuesped(string email){
    return obtenerHuesped(email)->getDatosHuesped();
};

Empleado* ControladorUsuarios::obtenerEmpleado(string email) {
    Usuario* u=Usuarios.find(email)->second;
    Empleado* h=dynamic_cast<Empleado*>(u);
    if (u==NULL || h==NULL)
        throw invalid_argument("El email no corresponde a un empleado");
    else
        return h;
};

string ControladorUsuarios::getEmHuesped(){
    return this->emHuesped;
};

    bool ControladorUsuarios::existeUsuario(string email){
        if(!this->Usuarios.empty()){
            if(this->Usuarios.find(email) != this->Usuarios.end()){
               return true;    
            } else return false;   
        } else return false;
    };

    bool ControladorUsuarios::existeHuesped(string email){
        if(!this->Usuarios.empty()){ 
            if(this->Usuarios.find(email) != this->Usuarios.end()){
               Usuario* u = Usuarios.find(email)->second;
               Huesped* h = dynamic_cast<Huesped*>(u);
               if(h != NULL){
                return true;
               } else return false;
                   
            } else return false;   
        } else return false;
    };

	void ControladorUsuarios::ConfirmarHuesped(string nombre, string email, string password, bool esFinger){
        if(!existeUsuario(email)){
            Huesped* hues = new Huesped(nombre, email, password, esFinger);
            this->Usuarios.insert(std::make_pair(email, hues)); //revisar ese make pair
        } else throw std::invalid_argument("El email ya registrado");
    };

	void ControladorUsuarios::ConfirmarEmpleado(string nombre, string email, string password, bool recibeNotificaciones){
        if(!existeUsuario(email)){
            Empleado* emp = new Empleado(nombre, email, password, Desempleado, recibeNotificaciones);
            this->Usuarios.insert(std::make_pair(email, emp));//revisar ese make pair
        } else throw std::invalid_argument("El email ya registrado");
    };




map<string,DTEmpleado> ControladorUsuarios::listarEmpleadosSinAsignar(){
    map<string, DTEmpleado> lista;
    return lista;
};
    
void ControladorUsuarios::vincularEmpCargo(string email, DTCargoEmpleado cargo) {
    Empleado* emp = this->obtenerEmpleado(email);
    emp->setCargo(cargo);
};

void ControladorUsuarios::vincularReserva(Reserva* res,string email){
    Usuario* u=Usuarios.find(email)->second;
    if (Huesped* h=dynamic_cast<Huesped*>(u))
        h->vincularReserva(res);
    else
        throw invalid_argument("La reserva o el email no son válidos");
};

map<string,Empleado*> ControladorUsuarios::getObservers(){
    return observers;
};

void ControladorUsuarios::suscribirse(string email){
    if (Usuarios.find(email)->second!=NULL && dynamic_cast<Empleado*>(Usuarios.find(email)->second)!=NULL){
        Empleado* e=dynamic_cast<Empleado*>(Usuarios.find(email)->second);
        if (!e->getRecibeNotificaciones()){
            observers.insert(make_pair(email,e));
            e->setRecibeNotificaciones(true);
        }
    } else //Caso en el cual el email no corresponde a un empleados, lanza la excepción
        throw invalid_argument("El email ingresado no corresponde a un empleado del sistema");
};

void ControladorUsuarios::eliminarSuscripcion(string email){
    if (Usuarios.find(email)->second!=NULL && dynamic_cast<Empleado*>(Usuarios.find(email)->second)!=NULL){
        Empleado* e=dynamic_cast<Empleado*>(Usuarios.find(email)->second);
        if (e->getRecibeNotificaciones()){
            observers.erase(email);
            e->setRecibeNotificaciones(false);
        }
    } else //Caso en el cual el email no corresponde a un empleados, lanza la excepción
        throw invalid_argument("El email ingresado no corresponde a un empleado del sistema");
};

map<int,DTCalificacion> ControladorUsuarios::consultarNotificaciones(string email){
    Empleado* e=dynamic_cast<Empleado*>(Usuarios.find(email)->second);
    map<int,DTCalificacion> resultado;
    if (Usuarios.find(email)->second!=NULL && e!=NULL && e->getRecibeNotificaciones())
        for (map<int,Calificacion *>::iterator it=e->consultarNotificaiones().begin();it!=e->consultarNotificaiones().end();++it)
            resultado.insert(map<int, DTCalificacion>::value_type(it->first,  it->second->getDatosCalificacion()));
    else //Caso en el cual el email no corresponde a un empleados, lanza la excepción
        throw invalid_argument("El email ingresado no corresponde a un empleado suscripto del sistema");
    return resultado;
};

void ControladorUsuarios::cancelarAsignacion(){};
void ControladorUsuarios::liberarMemoria(){};
