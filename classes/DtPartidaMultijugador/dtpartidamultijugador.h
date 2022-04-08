
#ifndef DTPARTIDAMULTIJUGADOR_HEADER
#define DTPARTIDAMULTIJUGADOR_HEADER

#include<string>
#include "../DtPartida/dtpartida.h"
using std::string;

class DtPartidaMultijugador : public DtPartida {
    private:
      bool transmitidoEnVivo;
      string * nicknameJugadoresUnidos;
      int cantidadJugadoresUnidos;
    public:
      DtPartidaMultijugador(bool,DtFechaHora *, int);
      bool getTransmitidoEnVivo();
      string * getNicknameJugadoresUnidos();
      int getCantidadJugadoresUnidos();
      void setTransmitidoEnVivo(bool);
      void setNicknameJugadoresUnidos(string *);
      void setCantidadJugadoresUnidos(int);
      float darTotalHorasParticipantes();
      void agregarJugadorAPartida(string);
};

#endif
