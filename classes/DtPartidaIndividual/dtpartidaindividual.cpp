#include <iostream>
#include "./dtpartidaindividual.h"
using namespace std;

DtPartidaIndividual::DtPartidaIndividual(bool continua, DtFechaHora * fecha,int duracion):DtPartida(fecha, duracion) {
    this->continuaPartidaAnterior = continua;
    this->setFecha(fecha);
    this->setDuracion(duracion);
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return this->continuaPartidaAnterior;
}
void DtPartidaIndividual::setContinuaPartidaAnterior(bool continua){
    this->continuaPartidaAnterior = continua;
}

float DtPartidaIndividual::darTotalHorasParticipantes(){
    return 0;
}