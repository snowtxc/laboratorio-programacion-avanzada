#include<iostream>
#include "../DtVideojuego/DtVideojuego.cpp"
#include "../DtJugador/dtjugador.cpp"

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
        dtJugador ** obtenerJugadores(int&);
        void agregarVideoJuego(string, TipoJuego);
        int getCantVideoJuegos();
        void imprimirVideoJuegos();

};

int Sistema::getCantVideoJuegos() {
  return this->cantVideoJuegos;
};

Sistema::Sistema() {
    this->videoJuegos = new DtVideojuego * [MAX_VIDEOJUEGOS];
    this->jugadores = new dtJugador * [MAX_JUGADORES];
    this->cantJugadores = 0;
    this->cantVideoJuegos = 0;
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

void Sistema::agregarVideoJuego(string nombre , TipoJuego genero) {
  DtVideojuego * juego = new DtVideojuego(nombre, genero);
  if(MAX_VIDEOJUEGOS < this->getCantVideoJuegos()) {
    throw invalid_argument("No se pueden agregar mas jugadores");
  };
  this->videoJuegos[this->cantVideoJuegos++] = juego;
};

void Sistema::imprimirVideoJuegos() {
  for (int i = 0; i < this->cantVideoJuegos; i++)
  {
    DtVideojuego * juego = this->videoJuegos[i];
    cout << endl;
    cout << "Nombre Juego: " << juego->getTitulo() << endl; 
    cout << "Genero Juego: " << "Test" << endl;
  }
}
