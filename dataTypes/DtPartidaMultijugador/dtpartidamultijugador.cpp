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

bool DtPartidaMultijugador::getTransmitidoEnVivo() {
    return this->transmitidoEnVivo;
};
string * DtPartidaMultijugador::getNicknameJugadoresUnidos() {
    return this->nicknameJugadoresUnidos;
};
int DtPartidaMultijugador::getCantidadJugadoresUnidos() {
    return this->cantidadJugadoresUnidos;
};

