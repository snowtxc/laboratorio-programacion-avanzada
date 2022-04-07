#ifndef DTPARTIDAINDIVIDUAL_HEADER
#define DTPARTIDAINDIVIDUAL_HEADER

using namespace std;

#include "../DtPartida/dtpartida.h"
#include <iostream>

class DtPartidaIndividual : public DtPartida{
    private:
        bool continuaPartidaAnterior;
    public:
        DtPartidaIndividual(bool, DtFechaHora * fecha,int duracion);
        bool getContinuaPartidaAnterior();
        void setContinuaPartidaAnterior(bool);
        //float darTotalHorasParticipantes();
};

#endif

