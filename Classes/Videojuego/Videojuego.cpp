#include <iostream>
#include "Videojuego.h"
#include "../../DataTypes/DtVideojuego/DtVideojuego.cpp"

using namespace std;

int MAX_JUGADORES_X_PARTIDA = 20;

Videojuego::Videojuego(string t, TipoJuego g) {
    this->titulo = t;
    this->genero = g;
    this->partidas = new Partida * [MAX_JUGADORES_X_PARTIDA];
    this->cantPartidas = 0;
}

string Videojuego::getTitulo() {
    return this->titulo;
}

TipoJuego Videojuego::getGenero(){
    return this->genero;
}


void Videojuego::setTitulo(string t) {
    this->titulo = t;
}

void Videojuego::setGenero(TipoJuego g){
    this->genero = g;
}

DtVideojuego * Videojuego::darInfo(){
    float totalHoras = 0;
    for(int i = 0; i < this->cantPartidas ; i ++){
       totalHoras = totalHoras + this->partidas[i]->darTotalHorasParticipantes();
    }
    DtVideojuego * P1 = new DtVideojuego(this->titulo, this->genero,totalHoras);
    return P1;
}   

void Videojuego::agregarPartida(Partida * partida) {
    if(this->cantPartidas == MAX_JUGADORES_X_PARTIDA) {
        throw invalid_argument("Partida llena");
    }
    this->partidas[this->cantPartidas++] = partida;
}

Partida ** Videojuego::obtenerPartidas(){
    return this->partidas;
}

int Videojuego::getCantPartidas(){
    return this->cantPartidas;
}