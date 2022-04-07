#include<iostream>
#include "./classes/Sistema/sistema.cpp"
#include "./classes/DtFechaHora/DtFechaHora.cpp"
#include "./classes/DtPartidaMultijugador/dtpartidamultijugador.cpp"
#include "./classes/DtPartidaIndividual/dtpartidaindividual.cpp"
#include "./classes/DtPartida/dtpartida.cpp"

using namespace std;


int main(){
    int a = 0;
    Sistema * sist = new Sistema();
    
    DtFechaHora * fecha = new DtFechaHora(1,1,2022,1,1);
    DtPartidaMultijugador * test = new DtPartidaMultijugador(true,fecha,5);
    DtPartidaIndividual * test2 = new DtPartidaIndividual(true,fecha,6);


    cout << "jajaja";
    return 0;
};