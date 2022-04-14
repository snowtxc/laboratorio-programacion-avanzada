#include "./PartidaMultijugador.h"
#include "../../dataTypes/DtPartidaMultijugador/dtpartidamultijugador.cpp"

PartidaMultijugador::PartidaMultijugador(bool transmitidaEnVivo,DtFechaHora * fecha, float duracion):Partida(fecha,duracion){
    this->transimitidaEnVivo = transimitidaEnVivo;
    this->jugadores = new Jugador *[this->max_jugadores];
    this->cant_jugadores = 0;
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
    string * jugadores_unidos = new string[this->max_jugadores];
    for(int i = 0 ; i < this->cant_jugadores ; i++){
        jugadores_unidos[i] = jugadores[i]->getNickname();
    }
    DtPartida * res = new DtPartidaMultijugador(this->transimitidaEnVivo,this->getFecha(),this->getDuracion(),jugadores_unidos,this->cant_jugadores);
    return res;
}

void PartidaMultijugador::agregarJugador(Jugador * jugador){
    if(this->cant_jugadores >= this->max_jugadores){
        throw invalid_argument("Lo siento la partida esta llena de jugadores");
    }
    this->jugadores[this->cant_jugadores] = jugador;
    this->cant_jugadores ++;
}

