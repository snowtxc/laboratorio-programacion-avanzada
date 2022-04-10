#include <iostream>
#include "jugador.h"
using namespace std;

Jugador::Jugador(string nick, int anios, string passwd){
    this->nickname = nick;
    this->edad = anios;
    this->password = passwd;
}

string Jugador::getNickname(){
    return this->nickname;
}

int Jugador::getEdad(){
    return this->edad;
}

string Jugador::getPass(){
    return this->password;
}

void Jugador::setNickname(string a){
    this->nickname = a;
}

void Jugador::setEdad(int b){
    this->edad = b;
}

void Jugador::setPassword(string c){
    this->password = c;
}
