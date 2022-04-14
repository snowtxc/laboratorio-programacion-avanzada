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


void DtPartidaIndividual::printOn(std::ostream& o) const
{
    o << "Tipo Partida:Individual" << endl; 
    o << "Fecha:" << this->fecha->getDay() << "/" << this->fecha->getMonth() << "/" << this->fecha->getYear() << endl;
    o << "Duracion:" << this->duracion << endl;
    if (this->continuaPartidaAnterior == true) {
      o << "Continuacion de una partida anterior:Si";
    }
    else {
      o << "Continuacion de una partida anterior:No";  
    }
}