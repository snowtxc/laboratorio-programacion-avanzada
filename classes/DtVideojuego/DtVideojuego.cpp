#include <iostream>
#include "DtVideojuego.h"
using namespace std;

DtVideojuego::DtVideojuego(string titulo , TipoJuego tipo) {
    this->titulo = titulo;
    this->genero = tipo;
}

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