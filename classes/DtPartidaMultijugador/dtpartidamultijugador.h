#include "../DtPartida/dtpartida.h"
#include<string>

using std::string;

class DtPartidaMultijugador : public DtPartida {
    private:
      bool transmitidoEnVivo;
      string * nicknameJugadoresUnidos;
      int cantidadJugadoresUnidos;
    public:
      DtPartidaMultijugador();
      bool getTransmitidoEnVivo();
      string * getNicknameJugadoresUnidos();
      int getCantidadJugadoresUnidos();
      void setTransmitidoEnVivo(bool);
      void setNicknameJugadoresUnidos(string *);
      void setCantidadJugadoresUnidos(int);
      float darTotalHorasParticipantes();
};