using namespace std;

#include <iostream>
#include <set>
#include <string>

#include "include/Huesped.h"
#include "include/Usuario.h"


int main () {

    int a;
    // Sistema VM;
    
    do {
        cout << "\n1. Crear Usuario<-Huesped (finger=true) \n";
        cout << "2. \n";
        cout << "3. \n";
        cout << "4. \n";
        cout << "5. \n";
        cout << "6. \n";
        cout << "7. \n";
        cout << "8. \n";
        cout << "9. Salir \n \n";

        cout << "Por favor elija una opción: ";
        cin >> a;

            
        string q,b,c;

        switch (a) {
            case 1: 
                cout << "Ingrese nombre, email y password de un finger: ";
                cin >> q;
                cin >> b;
                cin >> c;
                try{
                    Usuario* u=new Huesped(q,b,c,true);
                    cout << u->getNombre() << u->getEmail() << u->getPassword();
                    /*
                    reinterpret_cast<ClasePadre*>(InstanciaHija) se puede usar para acceder a un 
                    método de la clase hija, pero hay que estar seguros de que tiene clase 
                    hija de la clase especificada.
                    */
                    if(!reinterpret_cast<Huesped*>(u)->getFinger()) 
                        cout << " no";
                    cout << " es finger";
                }
                catch(const exception& e){
                    cerr << e.what() << '\n';}
                break;

            case 2: 
                
                
                break;
            case 3: 
                    

                break;
            case 4: 


                break;
  
            case 5: 


            
                break;
            case 6: 



                break;  
            case 7: 



                break;  
            case 8: 


                break;             
            case 9: cout << "Salida exitosa. \n";

                break;
            default: cout << "Por favor elija una opcion entre las disponibles: \n";

                break;
        };

    } while (a != 9);


    return 0;
};







