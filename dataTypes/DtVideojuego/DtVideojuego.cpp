#include <iostream>
#include "DtVideojuego.h"

using namespace std;

DtVideojuego::DtVideojuego(string t, TipoJuego g, float thj) {
    this->titulo = t;
    this->genero = g;
    this->TotalHorasDeJuego = thj;
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
