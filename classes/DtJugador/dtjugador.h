#include <iostream>
using namespace std;

class dtJugador{
private:
    string nickname;
    int edad;
    string password;
public:
    dtJugador(string, int, string);
    string getNickname();
    int getEdad();
    string getPass();
    void setNickname(string);
    void setEdad(int);
    void setPassword(string);
};