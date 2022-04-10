#include "./PartidaInvididual.h";


PartidaInvididual::PartidaInvididual(bool continuarPartidaAnterior){
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

