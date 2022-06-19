#include <string>

using namespace std;

#ifndef USUARIO
#define USUARIO

class Usuario {
     private:
          string nombre, email, password;
     public:
          Usuario(string n, string email, string pass);
          string getNombre();
          string getEmail();
          string getPassword();
          void setNombre(string);
          void setEmail(string);
          void setPassword(string);
          virtual ~Usuario();
};

#endif