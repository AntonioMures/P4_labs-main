 #include "../include/ControladorCalificacion.h"
#include "../include/ControladorReservas.h"
#include "../include/Calificacion.h"
#include "../include/Empleado.h"
#include "../include/FechaSistema.h"
#include "../include/ReservaGrupal.h"
#include "../include/ReservaIndividual.h"

// CONSTRUCTOR
ControladorCalificacion * ControladorCalificacion::instancia = NULL;

ControladorCalificacion::ControladorCalificacion(){
     maxIdCalif=0;
};

ControladorCalificacion * ControladorCalificacion::getInstancia(){
     if(instancia == NULL)
          instancia = new ControladorCalificacion();
     return instancia;
};
// DESTRUCTOR
ControladorCalificacion::~ControladorCalificacion(){};

int ControladorCalificacion::getIDCalif(){
     return maxIdCalif++;
};

// Listar Comentarios
map<int, DTCalificacion> ControladorCalificacion::listarComentarios(string email){
     ControladorUsuarios* conUsu = ControladorUsuarios::getInstancia();
     string nomHos = conUsu->buscarHostal(email);
     ControladorHostal conHos = ControladorHostal();

     calificacionesHostal = conHos.calificacionesHostal(nomHos);
     map<int, DTCalificacion> dc;

     for(map<int, Calificacion*>::iterator iter = calificacionesHostal.begin(); iter != calificacionesHostal.end(); ++iter){
          dc.insert(map<int, DTCalificacion>::value_type(iter->first, iter->second->getDatosCalificacion()));
     }

     return dc;
};

// Guardo en memoria la calificacion que voy a comentar
void ControladorCalificacion::elegirCalificacion(int opcion){
     cal = calificacionesHostal.find(opcion)->second; 
     if (cal==NULL)
          throw invalid_argument("La califiacaión elegida no es correcta");
};

// Creo la respuesta y limpio la memoria usada
void ControladorCalificacion::registrarComentario(string respuesta){
     respCalificacion* resp = new respCalificacion(respuesta);

     cal->agregarRespuesta(resp);

     calificacionesHostal.clear();
     cal = nullptr;
};


void ControladorCalificacion::registrarCalificacion(Hostal* host, int identificadorEstadia, int puntuacion, string comentario){
    
     FechaSistema* ifs=FechaSistema::getInstancia();

     DTFecha fecha = ifs->getFechaSistema();

     DTFecha* fechaActual = new DTFecha(fecha.getDia(),fecha.getMes(),fecha.getAnio(),fecha.getHora());     
     
     Calificacion* cal = new Calificacion(puntuacion, fechaActual, comentario, NULL);

     ControladorReservas* iEst = ControladorReservas::getInstancia();

     iEst->getEstadia(identificadorEstadia)->setCalificacion(cal);

     calificacionesHostal.insert(map<int, Calificacion*>::value_type(this->getIDCalif(), cal));

     ControladorUsuarios* iUs = ControladorUsuarios::getInstancia();

     map<string,Empleado*> observers = iUs->getObservers();

     if(!observers.empty()){
          map<string, Empleado*>::iterator iter = observers.begin();
          while(iter != observers.end()){
               iter->second->notificar(cal, host);
          }
     }

};


void ControladorCalificacion::RemoverNotificaion(Calificacion* c,Hostal* h){
     ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
     map<string, Empleado *> observers=icu->getObservers();
     for (map<string, Empleado *>::iterator it=observers.begin(); it!=observers.end(); ++it)
          it->second->removerNotif(c,h);
};

void ControladorCalificacion::EliminarCalificacion(Calificacion* c,Estadia* e){
     //1.*.3.1
     respCalificacion* resp=c->getRespuesta();
     if (resp!=NULL){
          //1.*.3.2
          c->DesvincularRespuesta();
          //1.*.3.3
          delete resp;
     }
     
     //Desvinculaciones que faltaban en el DiagCom:
     //se ve desde Hostal y Estadia
     Hostal* h;
     Reserva *r= e->getRes();
     ReservaGrupal* rg=reinterpret_cast<ReservaGrupal*>(r);
     if (rg!=NULL)
          h=rg->getHabitacion()->getHostal();
     else
          h=reinterpret_cast<ReservaIndividual*>(r)->getHabitacion()->getHostal();
     h->removerCalifiacion(c,e);
     e->setCalificacion(NULL);

     //1.*.3.4
     delete c;
};