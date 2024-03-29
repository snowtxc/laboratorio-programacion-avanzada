#include "./PartidaIndividual.h"
#include "../../dataTypes/DtPartidaIndividual/dtpartidaindividual.cpp"


PartidaIndividual::PartidaIndividual(bool continuarPartidaAnterior,DtFechaHora * fecha, float duracion):Partida(fecha,duracion){
    this->continuarPartidaAnterior = continuarPartidaAnterior;
}

bool PartidaIndividual::getContinuarPartidaAnterior(){
    return this->continuarPartidaAnterior;
}

void PartidaIndividual::setContinuarPartidaAnterior(bool continuarPartidaAnterior){
    this->continuarPartidaAnterior = continuarPartidaAnterior;
}
/*Queda por implementar FUNCION Dar total Horas participantes */
float PartidaIndividual::darTotalHorasParticipantes(){
    return this->getDuracion();
}

DtPartida * PartidaIndividual::darInfo(){
    DtPartida *res = new DtPartidaIndividual(this->continuarPartidaAnterior, this->getFecha(), this->getDuracion());
    return res;
}
