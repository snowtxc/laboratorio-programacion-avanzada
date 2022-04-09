
#ifndef DTPARTIDA_HEADER
#define DTPARTIDA_HEADER

#include<iostream>
#include "../DtFechaHora/DtFechaHora.h"

class DtPartida {
    private:
      DtFechaHora * fecha;
      float duracion;
    public:
      DtPartida();
      DtPartida(DtFechaHora *,int);
      DtFechaHora * getFecha();
      float getDuracion();
      void setFecha(DtFechaHora *);
      void setDuracion(float);
      virtual float darTotalHorasParticipantes() = 0;
};

#endif


