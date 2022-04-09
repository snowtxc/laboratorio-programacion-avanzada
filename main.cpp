#include<iostream>
#include "./classes/DtFechaHora/DtFechaHora.cpp";
#include "./classes/DtJugador/dtjugador.cpp";

using namespace std;

const int MAX_JUGADORES = 5;

// Array global de Jugadores.
dtJugador **arrJugadores = new dtJugador *[MAX_JUGADORES];
int cant_jugadores = 0;

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
    agregarJugador("Pepe", 17, "pepe123");
    agregarJugador("Jose", 82, "josesito123");
    agregarJugador("Alberto", 35, "alberto123");
    agregarJugador("Jose", 10, "jose123");
    agregarJugador("Toto", 9, "toto123");


    cout << "------ Datos del Sistema ------" << endl;
    for (int i = 0; i < cant_jugadores; i++)
    {
        cout << "   Jugador " << i + 1 << ": " << arrJugadores[i]->getNickname() << " " << arrJugadores[i]->getEdad() << " " << arrJugadores[i]->getPass() << endl;
    }

    cout <<  arrJugadores[4]->getNickname();
    cout << "------------------------------" << endl;

    
    return 0;
};