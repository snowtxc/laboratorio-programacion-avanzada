#include<iostream>
#include "../DtVideojuego/DtVideojuego.h"
#include "../DtJugador/dtjugador.h"

using namespace std;

int MAX_JUGADORES = 20;
int MAX_VIDEOJUEGOS= 20;
int MAX_PARTIDAS = 20;

class Sistema {
    private:
      DtVideojuego ** videoJuegos;
      int cantVideoJuegos;
      dtJugador ** jugadores;
      int cantJugadores;
    public:
        Sistema();
};

Sistema::Sistema() {
    this->videoJuegos = new DtVideojuego * [MAX_VIDEOJUEGOS];
    this->jugadores = new dtJugador * [MAX_JUGADORES];
};