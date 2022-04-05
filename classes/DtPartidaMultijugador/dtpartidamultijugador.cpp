#include<iostream>
#include "dtpartidamultijugador.h"

using namespace std;


int MAX_JUGADORES = 100;

DtPartidaMultijugador::DtPartidaMultijugador() {
    this->nicknameJugadoresUnidos = new string[MAX_JUGADORES];
}

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