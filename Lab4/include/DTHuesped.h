#include <string>

using namespace std;

#ifndef DTHUESPED
#define DTHUESPED

class DTHuesped {
    private:
        string nombre, email, password;
        bool esFinger;
    public:
        DTHuesped(string nombre,string email, string pass, bool esFinger);
        string getNombre();
        string getEmail();
        string getPassword();
        bool getFinger();
        ~DTHuesped();
};

#endif