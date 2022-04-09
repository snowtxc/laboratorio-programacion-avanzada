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
        DtVideojuego** obtenerVideojuegos(int &);
};

Sistema::Sistema() {
    this->videoJuegos = new DtVideojuego * [MAX_VIDEOJUEGOS];
    this->jugadores = new dtJugador * [MAX_JUGADORES];
};

DtVideojuego** Sistema::obtenerVideojuegos(int & cantVideojuegos){
    cantVideojuegos = this->cantVideoJuegos;
    if (cantVideojuegos == 0) {
        return NULL;
    }
    DtVideojuego** res = new DtVideojuego * [cantVideojuegos];


    for (int i = 0; i < cantVideojuegos; i++){
        string nombre = videoJuegos[i]->getTitulo();
        TipoJuego genero = videoJuegos[i]->getGenero();
        float hora = 1;

        DtVideojuego *videojuego = new DtVideojuego(nombre, genero, hora);

        res[i] = videojuego; //->darinfo()
    }
    return res;
}