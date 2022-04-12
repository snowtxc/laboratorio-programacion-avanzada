#ifndef PartidaIndividual_HEADER
#define PartidaIndividual_HEADER

#include "../../dataTypes/DtFechaHora/DtFechaHora.h"
#include "../Partida/Partida.h"
#include "../../dataTypes/DtPartidaIndividual/dtpartidaindividual.h"

class PartidaIndividual: public Partida {
    private:
        bool continuarPartidaAnterior;
    public:
        PartidaIndividual(bool,DtFechaHora * fecha, float, Jugador *);
        bool getContinuarPartidaAnterior();
        void setContinuarPartidaAnterior(bool);
        float darTotalHorasParticipantes();
        DtPartida * darInfo();
};
#endif