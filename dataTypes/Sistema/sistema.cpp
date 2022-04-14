#include<iostream>
#include <cstdlib> //es para el clear
#include <stdlib.h> // tambien para el clear pero fuera de windows
//#include "../DtVideojuego/DtVideojuego.cpp"
#include "../../Classes/Jugador/Jugador.cpp"
#include "../../Classes/Videojuego/Videojuego.cpp"
#include "../DtFechaHora/DtFechaHora.cpp"
#include "../DtJugador/dtjugador.cpp"
#include "../../Classes/Partida/Partida.cpp"

#include "../../Classes/PartidaIndividual/PartidaIndividual.cpp"
#include "../../Classes/PartidaMultijugador/PartidaMultijugador.cpp"

using namespace std;

int MAX_JUGADORES = 20;
int MAX_VIDEOJUEGOS= 20;
int MAX_PARTIDAS = 20;

class Sistema {
    private:
      Videojuego ** videoJuegos;
      int cantVideoJuegos;
      Jugador ** jugadores;
      int cantJugadores;
    public:
        Sistema();
        DtVideojuego** obtenerVideojuegos(int &);
        void agregarJugador(string, int, string);
        void imprimirJugadores();
        dtJugador ** obtenerJugadores(int&);
        void agregarVideoJuego(string, TipoJuego);
        int getCantVideoJuegos();
        int getCantJugadores();
        Videojuego ** getVideoJuegos();
        Jugador ** getJugadores();
        void imprimirVideoJuegos();
        DtPartida** obtenerPartidas(string, int&);
        void iniciarPartida(string, string, Partida *);
};

Videojuego ** Sistema::getVideoJuegos(){
  return this->videoJuegos;
}

Jugador ** Sistema::getJugadores(){
  return this->jugadores;
}

int Sistema::getCantVideoJuegos() {
  return this->cantVideoJuegos;
}

int Sistema::getCantJugadores() {
  return this->cantJugadores;
}

Sistema::Sistema() {
    this->videoJuegos = new Videojuego * [MAX_VIDEOJUEGOS];
    this->jugadores = new Jugador * [MAX_JUGADORES];
    this->cantJugadores = 0;
    this->cantVideoJuegos = 0;
};


DtVideojuego** Sistema::obtenerVideojuegos(int & cantVideojuegos){
    cantVideojuegos = this->cantVideoJuegos;
    if (cantVideojuegos == 0) {
        return NULL;
    }
    DtVideojuego** res = new DtVideojuego * [cantVideojuegos];


    for (int i = 0; i < cantVideojuegos; i++){
        //string nombre = videoJuegos[i]->getTitulo();
        //TipoJuego genero = videoJuegos[i]->getGenero();
        //float hora = 1;

        //DtVideojuego *videojuego = new DtVideojuego(nombre, genero, hora);

        //res[i] = videojuego; //->darinfo()
        res[i] = videoJuegos[i]->darInfo();
    }
    return res;
}


void Sistema::agregarJugador(string nickname, int edad, string pass){
  if (cantJugadores < MAX_JUGADORES){
    // Validacion rango de edad
    if (edad <= 5 || edad > 110){ 
        throw std::invalid_argument("ERROR: Edad invalida.");
    }
    // Validar si el nickname ya está en el array.
    for (int i = 0; i < cantJugadores; i++){
      if (jugadores[i]->getNickname() == nickname)
        throw std::invalid_argument("ERROR: Ya existe un jugador con ese Nickname.");
    }
    Jugador * nuevoJ = new Jugador(nickname, edad, pass);
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

dtJugador ** Sistema::obtenerJugadores(int& cantJugadores)
{
  cantJugadores = this->cantJugadores;
  dtJugador **jugadoresCopy = new dtJugador *[MAX_JUGADORES];
  for (int i = 0; i < cantJugadores ; i++)
  {
    string nickname = jugadores[i]->getNickname();
    int edad = jugadores[i]->getEdad();
    string password = jugadores[i]->getPass();

    dtJugador *jugador = new dtJugador(nickname, edad);

    jugadoresCopy[i] = jugador;
  }
  return jugadoresCopy;
}


void Sistema::agregarVideoJuego(string nombre , TipoJuego genero) {
  Videojuego * juego = new Videojuego(nombre, genero);
  if(MAX_VIDEOJUEGOS < this->getCantVideoJuegos()) {
    throw invalid_argument("ERROR: No se pueden agregar mas videojuegos");
  };
  for (int i = 0; i < cantVideoJuegos; i++){
      if (videoJuegos[i]->getTitulo() == nombre)
        throw std::invalid_argument("ERROR: Ya existe un juego con ese Titulo.");
  }
  this->videoJuegos[this->cantVideoJuegos++] = juego ;
}

void Sistema::imprimirVideoJuegos() {
  for (int i = 0; i < this->cantVideoJuegos; i++)
  {
    DtVideojuego * juego = this->videoJuegos[i]->darInfo();
    cout << endl;
    cout << "Nombre Juego: " << juego->getTitulo() << endl; 
    cout << "Genero Juego: " << "Test" << endl;
  }
}

DtPartida** Sistema::obtenerPartidas(string videojuego, int& cantPartidas){
  Videojuego * juego = NULL;
  
  for (int i = 0; i < this->cantVideoJuegos; i++){
    if(videoJuegos[i]->getTitulo() == videojuego ){
      juego = videoJuegos[i];
      break;
    }
  }
  if (juego == NULL){
    throw invalid_argument("ERROR: No existe ese videojuego.");
  }

  cantPartidas = juego->getCantPartidas();
  DtPartida** res = new DtPartida * [cantPartidas];
  Partida ** partidasDeJuego = juego->obtenerPartidas();

  for(int x = 0; x < cantPartidas; x++){
    res[x] = partidasDeJuego[x]->darInfo();
  }
  return res;
}


void Sistema::iniciarPartida(string nickname, string videojuego, Partida * datos) {
  Jugador * jugador = NULL;
  Videojuego * juego = NULL;
  for(int i = 0; i < this->cantJugadores; i++){
    if(this->jugadores[i]->getNickname() == nickname){
      jugador = jugadores[i];
    }
  };
  for(int i = 0; i < this->cantVideoJuegos; i++){
   if(this->videoJuegos[i]->getTitulo() == videojuego){
     juego = videoJuegos[i];
   }
  };

  if(juego == NULL || jugador == NULL){
    throw invalid_argument("ERROR: Juego o Jugador invalido al iniciar la partida");
  }
  
  datos->setJugador(jugador);
  juego->agregarPartida(datos);
}
