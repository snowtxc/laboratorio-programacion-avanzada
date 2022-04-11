#include<iostream>
#include "./dataTypes/Sistema/sistema.cpp"

using namespace std;


int main(){
    Sistema * sist = new Sistema();
    sist->agregarVideoJuego("Hola", Accion);

    DtFechaHora * fecha = new DtFechaHora(1,2,2000,5,20);
    PartidaInvididual * partida = new PartidaInvididual(true,fecha,50);

    DtPartida * partidita =  partida->darInfo();

    return 0;
   
};