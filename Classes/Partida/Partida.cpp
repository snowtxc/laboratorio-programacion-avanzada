#include<iostream>
#include "Partida.h"
#include "../../dataTypes/DtPartida/dtpartida.cpp"

using namespace std;

Partida::Partida(DtFechaHora * fechaHora,float duracion, Jugador * creadorPartida){
    this->fecha = fechaHora;
    this->duracion = duracion;
    this->creadorPartida = creadorPartida;
}

DtFechaHora * Partida::getFecha() {
    return this->fecha;
}

float Partida::getDuracion() {
    return this->duracion;
}

void Partida::setFecha(DtFechaHora * val) {
   this->fecha = val;
}

void Partida::setDuracion(float val) {
   this->duracion = val;
}
