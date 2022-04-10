#include<iostream>
#include "Partida.h"
#include "../../dataTypes/DtPartida/dtpartida.cpp"

using namespace std;

Partida::Partida(DtFechaHora * fechaHora,int duracion){
    this->fecha = fechaHora;
    this->duracion = duracion;
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




