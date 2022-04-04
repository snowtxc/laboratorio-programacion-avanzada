#include <iostream>
#include "classes/DtPartida/dtpartida.h"
using namespace std;

class DtPartidaIndividual : public DtPartida{
    private:
        bool continuaPartidaAnterior;
    public:
        DtPartidaIndividual(bool);
        bool getContinuaPartidaAnterior();
        void setContinuaPartidaAnterior(bool);
        float darTotalHorasParticipantes();
};