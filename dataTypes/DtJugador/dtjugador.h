#ifndef DTJUGADOR_HEADER
#define DTJUGADOR_HEADER

#include <iostream>
using namespace std;

class dtJugador{
private:
    string nickname;
    int edad;
public:
    dtJugador(string, int, string);
    string getNickname();
    int getEdad();
};

#endif