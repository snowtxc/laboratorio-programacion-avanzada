#include<iostream>
#include "../DtVideojuego/DtVideojuego.h"
#include "../DtJugador/dtjugador.h"

using namespace std;

/*


// Array global de Jugadores.
dtJugador **arrJugadores = new dtJugador *[MAX_JUGADORES];
int cant_jugadores = 0;




*/

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
        dtJugador ** obtenerJugadores(int&);
};

Sistema::Sistema() {
    this->videoJuegos = new DtVideojuego * [MAX_VIDEOJUEGOS];
    this->jugadores = new dtJugador * [MAX_JUGADORES];
};

dtJugador ** Sistema::obtenerJugadores(int& cantJugadores)
{
  cantJugadores = this->cantJugadores;
  dtJugador **jugadoresCopy = new dtJugador *[MAX_JUGADORES];
  for (int i = 0; i < cantJugadores ; i++)
  {
    string nickname = jugadores[i]->getNickname();
    int edad = jugadores[i]->getEdad();
    string password = jugadores[i]->getPass();

    dtJugador *jugador = new dtJugador(nickname, edad, password);

    jugadoresCopy[i] = jugador;
  }
  return jugadoresCopy;
}
