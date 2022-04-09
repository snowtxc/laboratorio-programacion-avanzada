#ifndef DTVIDEOJUEGO_HEADER
#define DTVIDEOJUEGO_HEADER

#include <iostream>
#include "../Enum/ETipojuego.h"
using namespace std;

class DtVideojuego {
    private:
        string titulo;
        TipoJuego genero;
        float TotalHorasDeJuego;
    public:
        DtVideojuego(string, TipoJuego);
        string getTitulo();
        TipoJuego getGenero();
        float getTotalHorasDeJuego();
        void setTitulo(string);
        void setGenero(TipoJuego);
        void setTotalHorasDeJuego(float);
};

#endif


