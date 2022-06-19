#include "../src/FabConHos.cpp"

int main(){
    FabConHos fab = FabConHos();

    IControladorHostal iHostal = fab.getInstanciaConHos();

    return 0;
}