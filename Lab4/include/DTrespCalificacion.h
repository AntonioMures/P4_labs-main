#include <string>

using namespace std;

#ifndef DTRESPCALIFICACION
#define DTRESPCALIFICACION

class DTrespCalificacion{
    private:
        string respuesta;
    
    public:
        DTrespCalificacion(string respuesta);
        string getRespuesta();
        ~DTrespCalificacion();
};

#endif