#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include <iostream>
using namespace std;

class Jugador{
private:
    string nickname;
    int edad;
    string password;
public:
    Jugador(string, int, string);
    string getNickname();
    int getEdad();
    string getPass();
    void setNickname(string);
    void setEdad(int);
    void setPassword(string);
};

#endif