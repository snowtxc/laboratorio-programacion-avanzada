#include<iostream>

class DtPartida {
    private:
      int fecha;
      float duracion;
    public:
      int getFecha();
      float getDuracion();
      void setFecha(int);
      void setDuracion(float);
      virtual float darTotalHorasParticipantes() = 0;
};
