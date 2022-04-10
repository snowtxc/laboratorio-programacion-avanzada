#include "../dataTypes/DtFechaHora/DtFechaHora.cpp";

class PartidaInvididual{          //Implementar herencia de clase partida cuando exista
    private:
        bool continuarPartidaAnterior;
    public:
        PartidaInvididual();
        float darTotalHorasParticipantes();
        bool getContinuarPartidaAnterior();
        void setContinuarPartidaAnterior();
};

