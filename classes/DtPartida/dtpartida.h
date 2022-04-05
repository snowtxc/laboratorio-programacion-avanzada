#include<iostream>
#include "../DtFechaHora/DtFechaHora.h"

class DtPartida {
    private:
      DtFechaHora fecha;
      float duracion;
    public:
      DtFechaHora getFecha();
      float getDuracion();
      void setFecha(DtFechaHora);
      void setDuracion(float);
      virtual float darTotalHorasParticipantes() = 0;
};
