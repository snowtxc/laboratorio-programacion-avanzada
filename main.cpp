#include<iostream>
#include "../dataTypes/Sistema/sistema.cpp"

using namespace std;

int main(){
    Sistema * sist = new Sistema();
    sist->agregarVideoJuego("Hola", Accion);
    return 0;
};