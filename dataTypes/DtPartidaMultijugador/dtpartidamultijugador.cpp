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

// DtPartidaMultijugador DtPartidaMultijugador::getClass(){
//   DtPartidaMultijugador p(this->getTransmitidoEnVivo(),this->getFecha(), this->getDuracion());
//   return p;
// }

void DtPartidaMultijugador::printOn(std::ostream& o) const
{
    o << endl;
    o << "Tipo Partida:Multijugador" << endl; 
    o << "Fecha:" << this->fecha->getDay() << "/" << this->fecha->getMonth() << "/" << this->fecha->getYear() << endl;
    o << "Duracion" << this->duracion << endl;
    if (this->transmitidoEnVivo == true) {
      o << "Transmitida en vivo:Si";
    }
    else {
      o << "Transmitida en vivo:No"; 
    }
}
