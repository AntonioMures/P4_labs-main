using namespace std;

#include <iostream>
#include <set>
#include <string>

#include "../include/FechaSistema.h"

using namespace std;

int main () {

    int a;
    FechaSistema* FECHA;
    cout << FECHA->getFechaSistema().getDia();
    
    do {
        cout << "\n1. \n";
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







