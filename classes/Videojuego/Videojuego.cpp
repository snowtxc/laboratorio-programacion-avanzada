#include <iostream>
#include "Videojuego.h"
#include "DtVideojuego.h"

using namespace std;


Videojuego::Videojuego(string t, TipoJuego g) {
    this->titulo = t;
    this->genero = g;
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

