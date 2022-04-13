#include<iostream>
//#include "./menu.cpp"
#include <ctime>
#include "./dataTypes/Sistema/sistema.cpp"
//#include "./dataTypes/DtPartidaIndividual/dtpartidaindividual.cpp"

using namespace std;


int main(){
    //menu();
    //Sistema * P1 = new Sistema();
    time_t t = time(0);
    tm* now = localtime(&t);

    int dia = now->tm_mday;
    int mes = 1 + now->tm_mon;
    int anio = 1900 + now->tm_year;
    int hora = now->tm_hour;
    int minuto = now->tm_min;
    DtFechaHora * ahora = new DtFechaHora(dia, mes, anio, hora, minuto);

    DtPartidaMultijugador P(true, ahora, 25.0);
    cout << P;

    return 0;
};