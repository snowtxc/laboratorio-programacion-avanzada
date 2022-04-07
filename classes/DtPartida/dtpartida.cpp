#include<iostream>
#include "dtpartida.h"

using namespace std;


DtPartida::DtPartida(DtFechaHora * fechaHora,int duracion){
    this->fecha = fechaHora;
    this->duracion = duracion;
}

DtFechaHora * DtPartida::getFecha() {
    return this->fecha;
}

float DtPartida::getDuracion() {
    return this->duracion;
}

void DtPartida::setFecha(DtFechaHora * val) {
   this->fecha = val;
}

void DtPartida::setDuracion(float val) {
   this->duracion = val;
}




