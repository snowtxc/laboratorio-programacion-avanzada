#include "../Partida/Partida.h"
#include "../Jugador/Jugador.h"
#include "../../dataTypes/DtFechaHora/DtFechaHora.h"
#include "../../dataTypes/DtPartidaMultijugador/dtpartidamultijugador.h"

class PartidaMultijugador: public  Partida {
    private:
      bool transimitidaEnVivo;
      Jugador ** jugadores;
      int max_jugadores = 20;
      unsigned cant_jugadores;
    public:
       PartidaMultijugador(bool,DtFechaHora * ,float);
       PartidaMultijugador(bool,DtFechaHora * ,float, Jugador **, int);
       bool getTransimitidaEnVivo();
       void setTransmitidaEnVivo(bool);
       float darTotalHorasParticipantes();
       DtPartida *darInfo();
       void agregarJugador(Jugador *);
};