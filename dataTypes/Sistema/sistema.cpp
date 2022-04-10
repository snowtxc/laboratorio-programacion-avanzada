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
        DtVideojuego** obtenerVideojuegos(int &);
        void agregarJugador(string, int, string);
        void imprimirJugadores();
        dtJugador ** obtenerJugadores(int&);
        void agregarVideoJuego(string, TipoJuego);
        int getCantVideoJuegos();
        void imprimirVideoJuegos();
};

int Sistema::getCantVideoJuegos() {
  return this->cantVideoJuegos;
}

Sistema::Sistema() {
    this->videoJuegos = new DtVideojuego * [MAX_VIDEOJUEGOS];
    this->jugadores = new dtJugador * [MAX_JUGADORES];
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
        string nombre = videoJuegos[i]->getTitulo();
        TipoJuego genero = videoJuegos[i]->getGenero();
        float hora = 1;

        DtVideojuego *videojuego = new DtVideojuego(nombre, genero, hora);

        res[i] = videojuego; //->darinfo()
    }
    return res;
}

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
  DtVideojuego * juego = new DtVideojuego(nombre, genero, 1.0);
  if(MAX_VIDEOJUEGOS < this->getCantVideoJuegos()) {
    throw invalid_argument("No se pueden agregar mas jugadores");
  };
  for (int i = 0; i < cantVideoJuegos; i++){
      if (videoJuegos[i]->getTitulo() == nombre)
        throw std::invalid_argument("ERROR: Ya existe un juego con ese Titulo.");
  }
  this->videoJuegos[this->cantVideoJuegos++] = juego;
}

void Sistema::imprimirVideoJuegos() {
  for (int i = 0; i < this->cantVideoJuegos; i++)
  {
    DtVideojuego * juego = this->videoJuegos[i];
    cout << endl;
    cout << "Nombre Juego: " << juego->getTitulo() << endl; 
    cout << "Genero Juego: " << "Test" << endl;
  }
}
