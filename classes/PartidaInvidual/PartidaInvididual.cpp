#include "./PartidaInvididual.h"
#include "../../dataTypes/DtPartidaIndividual/dtpartidaindividual.cpp"


PartidaInvididual::PartidaInvididual(bool continuarPartidaAnterior,DtFechaHora * fecha, float duracion):Partida(fecha,duracion){
    this->continuarPartidaAnterior = continuarPartidaAnterior;
}

bool PartidaInvididual::getContinuarPartidaAnterior(){
    return this->continuarPartidaAnterior;
}

void PartidaInvididual::setContinuarPartidaAnterior(bool continuarPartidaAnterior){
    this->continuarPartidaAnterior = continuarPartidaAnterior;
}
/*Queda por implementar FUNCION Dar total Horas participantes */
float PartidaInvididual::darTotalHorasParticipantes(){
    return 1;
}

DtPartida * PartidaInvididual::darInfo(){
    DtPartida *res = new DtPartidaIndividual(this->continuarPartidaAnterior, this->getFecha(), this->getDuracion());
    return res;
}

