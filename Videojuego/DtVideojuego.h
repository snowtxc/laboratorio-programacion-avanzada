#include <iostream>
using namespace std;

enum TipoJuego {Accion, Aventura, Deporte, Otro};

class DtVideojuego {
    private:
        string titulo;
        TipoJuego genero;
        float TotalHorasDeJuego;
    public:
        string getTitulo();
        TipoJuego getGenero();
        float getTotalHorasDeJuego();
        void setTitulo(string);
        void setGenero(TipoJuego);
        void setTotalHorasDeJuego(float);
};