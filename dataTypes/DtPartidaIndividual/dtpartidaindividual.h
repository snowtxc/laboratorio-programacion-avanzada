#ifndef DTPARTIDAINDIVIDUAL_HEADER
#define DTPARTIDAINDIVIDUAL_HEADER

using namespace std;

#include "../DtPartida/dtpartida.h"
#include <iostream>

class DtPartidaIndividual : public DtPartida{
    private:
        bool continuaPartidaAnterior;
    public:
        DtPartidaIndividual(bool, DtFechaHora * fecha,float duracion);
        bool getContinuaPartidaAnterior();
    protected:
        virtual void printOn(std::ostream& o) const;
        // virtual DtPartidaIndividual getClass();
};

#endif

