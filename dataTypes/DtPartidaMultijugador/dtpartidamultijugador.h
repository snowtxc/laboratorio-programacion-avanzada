
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
      DtPartidaMultijugador(bool,DtFechaHora *, float,string *,int);
      bool getTransmitidoEnVivo();
      string * getNicknameJugadoresUnidos();
      int getCantidadJugadoresUnidos();
    protected:
      virtual void printOn(std::ostream& o) const;
      // virtual DtPartidaMultijugador getClass();
};

#endif
