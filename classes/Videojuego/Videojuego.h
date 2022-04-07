#include <iostream>
#include "ETipojuego.h"
using namespace std;

class Videojuego {
    private:
        string titulo;
        TipoJuego genero;
    public:
        Videojuego(string, TipoJuego);
        string getTitulo();
        TipoJuego getGenero();
        void setTitulo(string);
        void setGenero(TipoJuego);
};