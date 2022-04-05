#include <iostream>
#include "dtjugador.h"
using namespace std;

dtJugador::dtJugador(string nick, int anios, string passwd){
    this->nickname = nick;
    this->edad = anios;
    this->password = passwd;
}

string dtJugador::getNickname(){
    return this->nickname;
}

int dtJugador::getEdad(){
    return this->edad;
}

string dtJugador::getPass(){
    return this->password;
}

void dtJugador::setNickname(string a){
    this->nickname = a;
}

void dtJugador::setEdad(int b){
    this->edad = b;
}

void dtJugador::setPassword(string c){
    this->password = c;
}