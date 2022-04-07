#include<iostream>
#include "./classes/DtFechaHora/DtFechaHora.cpp";
#include "./classes/DtJugador/dtjugador.cpp";

using namespace std;


dtJugador ** obtenerJugadores(int cantJugadores){
     dtJugador ** jugadoresCopy = new dtJugador*[1000];
     for(int i = 0 ;  i < cantJugadores && jugadores[i] != NULL; i ++){
         
         string nickname = jugadores[i]->getNickname();
         int edad = jugadores[i]->getEdad();
         string password = jugadores[i]->getPass();

         dtJugador * jugador = new dtJugador(nickname,edad,password);

         jugadoresCopy[i] = jugador;
     }
     return jugadoresCopy;
}


int main(){
    int a = 0;
    cout << "jajaja";
    return 0;
};