#include "./PartidaMultijugador.h"
#include "../../dataTypes/DtPartidaMultijugador/dtpartidamultijugador.cpp"

PartidaMultijugador::PartidaMultijugador(bool transmitidaEnVivo,DtFechaHora * fecha, float duracion):Partida(fecha,duracion){
    this->transimitidaEnVivo = transimitidaEnVivo;
}

float PartidaMultijugador::darTotalHorasParticipantes(){
    return 1;   ///Queda por implementar
}

bool PartidaMultijugador::getTransimitidaEnVivo(){
    return this->transimitidaEnVivo;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool transmitidaEnVivo){
    this->transimitidaEnVivo = transimitidaEnVivo;
}

DtPartida * PartidaMultijugador::darInfo(){
    DtPartida * res = new DtPartidaMultijugador(this->transimitidaEnVivo, this->getFecha(), this->getDuracion());
    return res;
}
