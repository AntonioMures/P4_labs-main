#include <string>

#ifndef DTHOSTAL
#define DTHOSTAL

using namespace std;

class DTHostal {

    private:
        string nombre;
        int telefono;
        string direccion;
    public:
        DTHostal(string nombre, int telefono, string direccion);
        string getNombre();
        int getTelefono();
        string getDireccion();

};

#endif