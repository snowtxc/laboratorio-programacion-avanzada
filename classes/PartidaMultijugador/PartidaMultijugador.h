#include "../Partida/Partida.h"
#include "../../dataTypes/DtFechaHora/DtFechaHora.h"
#include "../../dataTypes/DtPartidaMultijugador/dtpartidamultijugador.h"

class PartidaMultijugador: public  Partida{
    private:
      bool transimitidaEnVivo;
      //Implementar arrau pseudoatributo de Usuario
    public:
       PartidaMultijugador(bool,DtFechaHora * ,float);
       bool getTransimitidaEnVivo();
       void setTransmitidaEnVivo(bool);
       float darTotalHorasParticipantes();
        DtPartida *darInfo();
};