#include<iostream>
#include "dtpartidamultijugador.h"
#include "../DtPartida/dtpartida.h"

using namespace std;


int MAX_JUGADORES_POR_PARTIDA = 100;

DtPartidaMultijugador::DtPartidaMultijugador(bool enVivo,DtFechaHora * fechaHora, int duracion):DtPartida(fechaHora, duracion) {
    this->nicknameJugadoresUnidos = new string[MAX_JUGADORES_POR_PARTIDA];
    this->cantidadJugadoresUnidos = 0;
    this->transmitidoEnVivo = enVivo;
};

void DtPartidaMultijugador::agregarJugadorAPartida(string nickname) {
    if(this->cantidadJugadoresUnidos > MAX_JUGADORES_POR_PARTIDA){
        throw invalid_argument("Esta partida esta llena");
    }
    this->nicknameJugadoresUnidos[this->cantidadJugadoresUnidos++] = nickname;
};

void DtPartidaMultijugador::setTransmitidoEnVivo(bool val) {
    this->transmitidoEnVivo = val;
};
void DtPartidaMultijugador::setNicknameJugadoresUnidos(string * val) {
    this->nicknameJugadoresUnidos = val;
};
void DtPartidaMultijugador::setCantidadJugadoresUnidos(int val) {
    this->cantidadJugadoresUnidos = val;
};

bool DtPartidaMultijugador::getTransmitidoEnVivo() {
    return this->transmitidoEnVivo;
};
string * DtPartidaMultijugador::getNicknameJugadoresUnidos() {
    return this->nicknameJugadoresUnidos;
};
int DtPartidaMultijugador::getCantidadJugadoresUnidos() {
    return this->cantidadJugadoresUnidos;
};

float DtPartidaMultijugador::darTotalHorasParticipantes() {
    return 0.0;
};