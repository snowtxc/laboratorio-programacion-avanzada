#ifndef PARTIDA_HEADER
#define PARTIDA_HEADER

#include<iostream>
#include "../../dataTypes/DtFechaHora/DtFechaHora.h"
#include "../../dataTypes/DtPartida/dtpartida.h"

class Partida {
    private:
      DtFechaHora * fecha;
      float duracion;
      Jugador * creadorPartida = NULL;
    public:
      Partida();
      Partida(DtFechaHora *,float, Jugador *);
      DtFechaHora * getFecha();
      float getDuracion();
      void setFecha(DtFechaHora *);
      void setDuracion(float);
      virtual float darTotalHorasParticipantes() = 0;
      virtual DtPartida * darInfo() = 0;
};

#endif
