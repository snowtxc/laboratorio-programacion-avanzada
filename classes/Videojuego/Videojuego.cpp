#include <iostream>
#include "Videojuego.h"
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

Videojuego** obtenerVideojuegos(int & cantVideojuegos){
    Videojuego * tmp;
    cantVideojuegos = this->cantV;
    for (i = 0; i <= cantVideojuegos, i++){
        res[i] = ...;
    }
    return res;
}