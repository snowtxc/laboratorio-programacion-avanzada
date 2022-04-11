
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
      DtPartida(DtFechaHora *,float);
      DtFechaHora * getFecha();
      float getDuracion();
};

#endif


