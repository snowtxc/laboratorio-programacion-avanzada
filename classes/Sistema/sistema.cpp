#include<iostream>
#include "../DtVideojuego/DtVideojuego.h"
#include "../DtJugador/dtjugador.h"

using namespace std;

int MAX_JUGADORES = 20;
int MAX_VIDEOJUEGOS= 20;
int MAX_PARTIDAS = 20;

class Sistema {
    private:
      DtVideojuego ** videoJuegos;
      int cantVideoJuegos;
      dtJugador ** jugadores;
      int cantJugadores;
    public:
        Sistema();
        void agregarJugador(string, int, string);
        void imprimirJugadores();
};

Sistema::Sistema() {
    this->videoJuegos = new DtVideojuego * [MAX_VIDEOJUEGOS];
    this->jugadores = new dtJugador * [MAX_JUGADORES];
};

void Sistema::agregarJugador(string nickname, int edad, string password){
  if (cantJugadores < MAX_JUGADORES){
    // Validacion rango de edad
    if (edad <= 5 || edad > 110){ 
        throw std::invalid_argument("ERROR: Edad inválida.");
    }
    // Validar si el nickname ya está en el array.
    for (int i = 0; i < cantJugadores; i++){
      if (jugadores[i]->getNickname() == nickname)
        throw std::invalid_argument("ERROR: Ya existe un jugador con ese Nickname.");
    }
    dtJugador * nuevoJ = new dtJugador(nickname, edad, password);
    jugadores[cantJugadores++] = nuevoJ;
  }else{ // El array está lleno, no se puede cargar otro player.
      return;
  }
}

void Sistema::imprimirJugadores(){
    cout << "--------- Jugadores ---------" << endl; 
    for (int i = 0; i < cantJugadores; i++) {
        cout << "  Jugador " << i + 1 << ": " << jugadores[i]->getNickname() << " " << jugadores[i]->getEdad() << " " << jugadores[i]->getPass() << endl; 
    }
    cout << "-----------------------------" << endl;
}