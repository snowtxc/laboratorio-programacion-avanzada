#include "./PartidaMultijugador.h";

PartidaMultijugador::PartidaMultijugador(bool transmitidaEnVivo){
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
