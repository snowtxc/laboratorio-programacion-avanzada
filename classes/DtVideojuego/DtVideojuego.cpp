#include <iostream>
#include "DtVideojuego.h"
using namespace std;

string DtVideojuego::getTitulo() {
    return this->titulo;
}

TipoJuego DtVideojuego::getGenero(){
    return this->genero;
}

float DtVideojuego::getTotalHorasDeJuego(){
    return this->TotalHorasDeJuego;
}

void DtVideojuego::setTitulo(string uTitulo) {
    this->titulo = uTitulo;
}

void DtVideojuego::setGenero(TipoJuego uGenero) {
    this->genero = uGenero;
}

void DtVideojuego::setTotalHorasDeJuego(float uHoras) {
    this->TotalHorasDeJuego = uHoras;
}

DtVideojuego** obtenerVideojuegos(int& cantVideojuegos){
    //contar videojuego y almacenarlos en cantVideojuegos
    
    DtVideojuego** videojuegos[MAX_VIDEOJUEGOS];

    arr[0] = v1;
    arr[1] = v2;
    arr[2] = v3;
    arr[3] = v4;
    arr[4] = v5;
    arr[5] = v6;
    arr[6] = v7;
    arr[7] = v8;
    arr[8] = v9;
    arr[9] = v10;
    
    cantVideojuegos = 2394;
    return cantVideojuegos;
}