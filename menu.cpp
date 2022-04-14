#include <iostream>
#include <unistd.h>
#include <cstdlib> //es para el clear
#include <stdlib.h> // tambien para el clear pero fuera de windows
#include <string>
#include <limits> // para validar ints en el cin
#include <ctime>
#include "./dataTypes/Sistema/sistema.cpp"

using namespace std;

Sistema * s = new Sistema();

void mostrarMenu();
void agregarVideojuegoMenu();
void obtenerVideojuegosMenu();
void agregarJugadorMenu();
void obtenerJugadoresMenu();
void iniciarPartidaMenu();
void obtenerPartidasMenu();
int leerEntradaInt();
string leerEntradaString();
TipoJuego menuTipoJuego();
Jugador * buscarJugador(string, Jugador **, int);
bool menuMostrarSeguirAgregandoJugador();

void mostrarMenu(){
    system("cls");
    cout <<"******** Menu de Interaccion ********" << endl;
    cout << "Videojuego: " << endl;
    cout << " 1 - Agregar Videojuego." << endl;
    cout << " 2 - Obtener Videojuegos." << endl;
    cout << "Jugadores: " << endl;
    cout << " 3 - Agregar Jugador." << endl;
    cout << " 4 - Obtener Jugadores." << endl;
    cout << "Partidas: " << endl;
    cout << " 5 - Iniciar Partida." << endl;
    cout << " 6 - Obtener Partidas." << endl;
    cout << " 7 - Salir." << endl;
    cout << "*************************************" << endl;
    cout << " Ingrese una opcion: (entre 1-7)" << endl;
}

void menu(){
    int eleccion;
    bool menu = true;

    while (menu){
        mostrarMenu();
        eleccion = leerEntradaInt();
        switch (eleccion){
            case 1: agregarVideojuegoMenu(); break;
            case 2: obtenerVideojuegosMenu();break;
            case 3: agregarJugadorMenu(); break;
            case 4: obtenerJugadoresMenu(); break;
            case 5: iniciarPartidaMenu();break;
            case 6: obtenerPartidasMenu();break;
            case 7: menu = false; system("cls");break;
            default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    }
}

int leerEntradaInt(){
    int eleccion;
    
    while (!(cin >> eleccion)) {
		cout << "Solo numeros por favor..."<< endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
    return eleccion;
}

string leerEntradaString(){
    string eleccion;
    getline(cin >> ws, eleccion); //ws hace que se puedan almacenar espacios.
    return eleccion;
}

TipoJuego menuTipoJuego(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Seleccione el Genero del VideoJuego: "<<endl;
        cout << "1 - Accion." << endl;
        cout << "2 - Aventura." << endl;
        cout << "3 - Deporte." << endl;
        cout << "4 - Otro." << endl;

        int eleccion;
        eleccion = leerEntradaInt();

        switch (eleccion)
        {
        case 1: return Accion; opcionValida = true; break;
        case 2: return Aventura; opcionValida = true;break;
        case 3: return Deporte; opcionValida = true;break;
        case 4: return Otro; opcionValida = true;break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); system("cls"); break;
        }
    } while (opcionValida == false);
    //validar que no salga del while hasta que inserte una opcion valida.
}

int menuIndividualOmultijugador(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Seleccione el tipo de partida deseado: "<<endl;
        cout << "1 - Individual." << endl;
        cout << "2 - Multijugador." << endl;

        int eleccion;
        eleccion = leerEntradaInt();

        switch (eleccion)
        {
        case 1: return 1; opcionValida = true; break;
        case 2: return 2; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}

int menuIndividualNuevaoContinuar(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Seleccione el tipo de partida deseado: "<<endl;
        cout << "1 - Partida Nueva." << endl;
        cout << "2 - Continuar Partida." << endl;

        int eleccion;
        eleccion = leerEntradaInt();

        switch (eleccion)
        {
        case 1: return 1; opcionValida = true; break;
        case 2: return 2; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}

// si eligió modo multijugador, le preguntamos si va a ser transmitida en vivo o no.
bool menuMultijugadorTransmitidaOno(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Desea transmitir su partida en vivo?"<<endl;
        cout << "1 - Si." << endl;
        cout << "2 - No." << endl;

        int eleccion;
        eleccion = leerEntradaInt();

        switch (eleccion)
        {
        case 1: return true; opcionValida = true; break;
        case 2: return false; opcionValida = true;break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}

void agregarVideojuegoMenu(){
    system("cls");
    string nombreJuego;
    cout << "Ingrese el nombre del Videojuego: "<< endl;
    nombreJuego = leerEntradaString();

    system("cls");
    TipoJuego tipo;
    tipo = menuTipoJuego();

    try{
        s->agregarVideoJuego(nombreJuego, tipo);
        system("cls");
        cout << "Videojuego " << "'" << nombreJuego << "'" << " insertado con EXITO." << endl;
        sleep(2);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void obtenerVideojuegosMenu(){
    system("cls");
    try{
        int cantV;
        DtVideojuego ** videojuegos = s->obtenerVideojuegos(cantV);  


        for (int i = 0; i < cantV; i++)
        {
            string fromtatedGenero = "";
            switch (videojuegos[i]->getGenero())
            {
            case Accion: fromtatedGenero = "Accion"; break;
            case Aventura: fromtatedGenero = "Aventura";break;
            case Deporte: fromtatedGenero = "Deporte";break;
            case Otro:  fromtatedGenero = "Otro";break;
            }

            cout << "Nombre Juego: " << videojuegos[i]->getTitulo() << endl; 
            cout << "Genero Juego: " << fromtatedGenero << endl; // Usar switch
            cout << "Total Horas:" << videojuegos[i]->getTotalHorasDeJuego() << endl;
        }
        sleep(5);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void agregarJugadorMenu(){
    string nick;
    int age;
    string pass;

    system("cls");
    cout << "Ingrese Nickname para el jugador: "<< endl;
    nick = leerEntradaString();

    system("cls");
    cout << "Ingrese Edad del jugador: "<< endl;
    age = leerEntradaInt();

    system("cls");
    cout << "Ingrese Password para el jugador: "<< endl;
    pass = leerEntradaString();

    system("cls");

    try{
        s->agregarJugador(nick, age, pass);
        cout << "Jugador registrado con EXITO"<< endl;
        sleep(2);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void obtenerJugadoresMenu(){
    system("cls");
    try{
        int cantJ = 0;
        dtJugador ** jugadores = s->obtenerJugadores(cantJ);  
        if (cantJ == 0){
            cout << endl <<"No hay jugadores registrados en el sistema." <<endl;
            sleep(3);
        }else{
        cout << "--------- Jugadores ---------" << endl;
        for (int i = 0; i < cantJ; i++)
        {
            cout << "  Jugador " << i + 1 << ": "<<endl
            << "    -Nickname: " << jugadores[i]->getNickname() << endl
            << "    -Edad: " << jugadores[i]->getEdad() << endl;
        }
        cout << "-----------------------------" << endl;
        sleep(6);
        }
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

//le pregunto al jugador si quiere seguir agregando un jugador a la partida
bool menuMostrarSeguirAgregandoJugador(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Desea seguir agregando jugadores a esta partida ?"<<endl;
        cout << "1 - Si." << endl;
        cout << "2 - No." << endl;

        int eleccion;
        eleccion = leerEntradaInt();

        switch (eleccion)
        {
        case 1: return true; opcionValida = true; break;
        case 2: return false; opcionValida = true;break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}


Jugador ** obtenerJugadoresAIniciarPartida(int& cant, string nickCreador){
    Jugador ** jugadoresSistema = jugadoresSistema = s->getJugadores();
    int cantJugadoresSistema = s->getCantJugadores();
    Jugador * creador = buscarJugador(nickCreador, jugadoresSistema,cantJugadoresSistema);
    if(creador == NULL) {
        system("cls");
        throw invalid_argument("Error: El creador para esta partida no existe");
    }
    Jugador ** Jugadores = new Jugador * [MAX_JUGADORES];
    Jugadores[0] = creador; 
    cant ++;
    bool opcion = menuMostrarSeguirAgregandoJugador();
    while (opcion != false)
    {
        system("cls");
        cout << "Ingrese el nickname del jugador que desea agregar a esta partida: " << endl;
        string nick = leerEntradaString();
        Jugador * jugador = buscarJugador(nick, jugadoresSistema, cantJugadoresSistema);

        //Valido si jugador ya existe en la lista que estoy creando
        Jugador * jugadorYaExistente = buscarJugador(nick, Jugadores, cant);
        if(jugadorYaExistente != NULL){
            cout << "Este jugador ya es parte de esta partida" << endl;
            sleep(3);
        }
        else if(jugador == NULL) {
            cout << "El nickname que proporciono no pertenece a ningun jugador en el sistema" << endl;
            sleep(3);
        } else {
            system("cls");
            cout << "El jugador fue agregado a esta partida :)" << endl;
            Jugadores[cant++] = jugador;
            sleep(2);
        }
        opcion = menuMostrarSeguirAgregandoJugador();
    }
    return Jugadores;
}

Jugador * buscarJugador(string nickname, Jugador ** lista, int cant) {
   Jugador * jugador = NULL;
   for(int i = 0; i < cant; i++){
       if(lista[i]->getNickname() == nickname){
           jugador = lista[i];
       }
   }
   return jugador;
}


Videojuego * buscarVideoJuego(string titulo) {
   Videojuego * juego = NULL;
   Videojuego ** juegosSistema = s->getVideoJuegos();
   for(int i = 0; i < s->getCantJugadores(); i++){
       if(juegosSistema[i]->getTitulo() == titulo){
           juego = juegosSistema[i];
       }
   }
   return juego;
}


void iniciarPartidaMenu(){
    time_t t = time(0);
    tm* now = localtime(&t);
    string nickCreador; // NO SE USA AÚN.
    string videojuego;
    int indiviOmultij;
    
    int dia = now->tm_mday;
    int mes = 1 + now->tm_mon;
    int anio = 1900 + now->tm_year;
    int hora = now->tm_hour;
    int minuto = now->tm_min;
    DtFechaHora * ahora = new DtFechaHora(dia, mes, anio, hora, minuto);


    system("cls");
    cout << "Ingrese Videojuego en el que desea iniciar la partida: "<< endl;
    videojuego = leerEntradaString();

    system("cls");
    cout << "Ingrese el jugador que iniciara la partida: "<< endl;
    nickCreador = leerEntradaString();

    int duracion;
    system("cls");
    cout << "Por favor, ingrese la duracion de la partida: (minutos)"<<endl;
    duracion = leerEntradaInt();
    
    indiviOmultij = menuIndividualOmultijugador(); // le preguntamos si quiere individual o multijugador
    Partida * nueva;
    
    try{
        if (indiviOmultij == 1){ // eligió modo individual
        bool continuar;
        system("cls");
        continuar = menuIndividualNuevaoContinuar() == 1 ? true : false;
        nueva = new PartidaIndividual(continuar, ahora, duracion);
        s->iniciarPartida(nickCreador,videojuego, nueva);
        }
        else
        { // si eligió modo multijugador
            bool enVivo;
            enVivo = menuMultijugadorTransmitidaOno(); // preguntamos si quiere transmitirla en vivo o no.
            int cant_jugadores = 0;
            Jugador ** jugadoresEnEstaPartida = obtenerJugadoresAIniciarPartida(cant_jugadores, nickCreador);
            nueva = new PartidaMultijugador(enVivo, ahora, duracion,jugadoresEnEstaPartida, cant_jugadores);
            s->iniciarPartida(nickCreador,videojuego, nueva);
        }
        system("cls");
        cout << "Iniciando partida ... !"<< endl;
        sleep(5);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void obtenerPartidasMenu(){
    // solo consulta
    string juego;
    system("cls");
    cout << "Ingrese nombre del VideoJuego: "<< endl;
    juego = leerEntradaString();
    try{
        int cantP;
        DtPartida ** partidas = s->obtenerPartidas(juego, cantP);
        system("cls");
        cout << "--------- Partidas ---------" << endl;
        for (int i = 0; i < cantP; i++)
        {
            cout << *partidas[i];
            cout << endl << "----------------------------" << endl;
        }
        sleep(5);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}
