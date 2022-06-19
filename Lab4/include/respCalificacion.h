#include <string>

using namespace std;

#ifndef RESPCALIFICACION
#define RESPCALIFICACION

class respCalificacion{
    private:
        string respuesta;
    
    public:
        respCalificacion(string respuesta);
        string getRespuesta();
        void setRespuesta(string respuesta);
        ~respCalificacion();
};

#endif