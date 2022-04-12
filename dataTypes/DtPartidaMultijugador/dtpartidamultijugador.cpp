#include<iostream>
#include "dtpartidamultijugador.h"
#include "../DtPartida/dtpartida.h"

using namespace std;



DtPartidaMultijugador::DtPartidaMultijugador(bool enVivo,DtFechaHora * fechaHora, float duracion,string * jugadoresUnidos,int cantidadJugadoresUnidos):DtPartida(fechaHora, duracion) {
    this->nicknameJugadoresUnidos = jugadoresUnidos;
    this->transmitidoEnVivo = enVivo;
    this->cantidadJugadoresUnidos = cantidadJugadoresUnidos;
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

