#include <iostream>
#include "./dtpartidaindividual.h"
using namespace std;

DtPartidaIndividual::DtPartidaIndividual(bool continua, DtFechaHora * fecha,float duracion):DtPartida(fecha, duracion) {
    this->continuaPartidaAnterior = continua;
  //  this->setFecha(fecha);
   // this->setDuracion(duracion);
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return this->continuaPartidaAnterior;
}

