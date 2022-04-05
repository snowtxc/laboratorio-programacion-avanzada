#include <iostream>
#include "dtpartidaindividual.h"
using namespace std;

DtPartidaIndividual::DtPartidaIndividual(bool continua){
    this->continuaPartidaAnterior = continua;
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return this->continuaPartidaAnterior;
}
void DtPartidaIndividual::setContinuaPartidaAnterior(bool continua){
    this->continuaPartidaAnterior = continua;
}

/*
float DtPartidaIndividual::darTotalHorasParticipantes(){
    return 0;
}
*/