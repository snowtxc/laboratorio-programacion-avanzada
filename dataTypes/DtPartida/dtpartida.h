
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
      friend std::ostream& operator<< (std::ostream& o, DtPartida const& b)
      {
        b.printOn(o);
        return o;
      }
    protected:
      virtual void printOn(std::ostream& o) const = 0;
};

#endif


