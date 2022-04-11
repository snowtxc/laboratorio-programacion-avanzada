
#ifndef PARTIDAINVIDIDUAL_HEADER
#define PARTIDAINVIDIDUAL_HEADER

#include "../../dataTypes/DtFechaHora/DtFechaHora.h"
#include "../Partida/Partida.h"
#include "../../dataTypes/DtPartidaIndividual/dtpartidaindividual.h"

class PartidaInvididual: public Partida{          //Implementar herencia de clase partida cuando exista
    private:
        bool continuarPartidaAnterior;
    public:
        PartidaInvididual(bool,DtFechaHora * fecha, float);
        bool getContinuarPartidaAnterior();
        void setContinuarPartidaAnterior(bool);
        float darTotalHorasParticipantes();
        DtPartida * darInfo();
       
    
};
#endif
