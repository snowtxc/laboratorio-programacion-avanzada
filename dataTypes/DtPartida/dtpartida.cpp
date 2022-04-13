#include<iostream>
#include "dtpartida.h"

using namespace std;


DtPartida::DtPartida(DtFechaHora * fechaHora,float duracion){
    this->fecha = fechaHora;
    this->duracion = duracion;
}

DtFechaHora * DtPartida::getFecha() {
    return this->fecha;
}

float DtPartida::getDuracion() {
    return this->duracion;
}
