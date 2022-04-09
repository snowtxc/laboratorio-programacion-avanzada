#include <iostream>
#include "dtjugador.h"
using namespace std;

dtJugador::dtJugador(string nick, int anios){
    this->nickname = nick;
    this->edad = anios;
}

string dtJugador::getNickname(){
    return this->nickname;
}

int dtJugador::getEdad(){
    return this->edad;
}
