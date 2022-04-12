#include <iostream>
#include "../../Enum/ETipojuego.h"
#include "../../DataTypes/DtVideojuego/DtVideojuego.h"
#include "../Partida/Partida.h"

using namespace std;

class Videojuego {
    private:
        string titulo;
        TipoJuego genero;
        Partida ** partidas;
        int cantPartidas;
    public:
        Videojuego(string, TipoJuego);
        string getTitulo();
        TipoJuego getGenero();
        void setTitulo(string);
        void setGenero(TipoJuego);
        DtVideojuego * darInfo();
        void agregarPartida(Partida *);
        Partida ** obtenerPartidas();
        int getCantPartidas();
};