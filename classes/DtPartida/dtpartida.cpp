#include<iostream>
#include "dtpartida.h"

using namespace std;

DtFechaHora DtPartida::getFecha() {
    return this->fecha;
}

float DtPartida::getDuracion() {
    return this->duracion;
}

void DtPartida::setFecha(DtFechaHora val) {
   this->fecha = val;
}

void DtPartida::setDuracion(float val) {
   this->duracion = val;
}




