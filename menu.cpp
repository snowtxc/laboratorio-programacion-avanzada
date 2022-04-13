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
    // validar que haga loop hasta recibir opcion valida.
    cout << "Seleccione el tipo de partida deseado: "<<endl;
    cout << "1 - Individual." << endl;
    cout << "2 - Multijugador." << endl;

    int eleccion;
    eleccion = leerEntradaInt();

    switch (eleccion)
    {
    case 1: return Accion; break;
    case 2: return Aventura;break;
    default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
    }
    } while (opcionValida == false);
    //validar que no salga del while hasta que inserte una opcion valida.
}

int menuIndividual(){
    bool opcionValida = false;
    do{
    cout << "Seleccione el tipo de partida deseado: "<<endl;
    cout << "1 - Partida Nueva." << endl;
    cout << "2 - Continuar Partida." << endl;

    int eleccion;
    eleccion = leerEntradaInt();

    switch (eleccion)
    {
    case 1: return Accion; break;
    case 2: return Aventura;break;
    default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
    }
    } while (opcionValida == false);
}

// si eligió modo multijugador, le pedimos los nicknames de los jugadores q la van a formar y si va a ser transmitida en vivo o no.
int menuMultijugadorPedirJugadores(){
    bool opcionValida = false;
    do{
    // validar que haga loop hasta recibir opcion valida.
    cout << "Ingrese los nicknames: "<<endl;
    cout << "1 - Partida Nueva." << endl;
    cout << "2 - Continuar Partida." << endl;

    int eleccion;
    eleccion = leerEntradaInt();

    switch (eleccion)
    {
    case 1: return Accion; break;
    case 2: return Aventura;break;
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
        cout << "Videojuego " << "'" << nombreJuego << "'" << " insertado con EXITO." << endl;
        sleep(2);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void obtenerVideojuegosMenu(){
    // solo consulta
    system("cls");
    try{
        int cantV;
        DtVideojuego ** videojuegos = s->obtenerVideojuegos(cantV);  
        for (int i = 0; i < cantV; i++)
        {
            cout << "Nombre Juego: " << videojuegos[i]->getTitulo() << endl; 
            cout << "Genero Juego: " << videojuegos[i]->getGenero() << endl; // Usar switch
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
        cout << "JUGADOR REGISTRADO CON EXITO"<< endl;
        sleep(2);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void obtenerJugadoresMenu(){
    // solo consulta
    system("cls");
    try{
        s->imprimirJugadores();
        sleep(5);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void iniciarPartidaMenu(){
    time_t t = time(0);
    tm* now = localtime(&t);
    string nickCreador;
    string videojuego;
    int indiviOmultij;
    int multijugador;
    
    int dia = now->tm_mday;
    int mes = 1 + now->tm_mon;
    int anio = 1900 + now->tm_year;
    int hora = now->tm_hour;
    int minuto = now->tm_min;
    DtFechaHora * ahora = new DtFechaHora(dia, mes, anio, hora, minuto);

    system("cls");
    indiviOmultij = menuIndividualOmultijugador(); // le preguntamos si quiere individual o multijugador
    if (indiviOmultij == 1){ // eligió modo individual
        int individual;
        system("cls");
        individual = menuIndividual(); // le preguntamos si quiere una nueva partida o continuar una ya registrada
        if (individual == 1){ //eligió crear PARTIDA NUEVA, le pedimos la duracion y creamos una instancia
            int duracion;
            system("cls");
            cout << "Por favor, ingrese la duracion de la partida: "<<endl;
            duracion = leerEntradaInt();
            DtPartida * nueva = new DtPartidaIndividual(false, ahora, duracion); //está mal
        }else{ // eligió continuar PARTIDA ANTERIOR
            int duracion;
            system("cls");
            cout << "Por favor, ingrese la duracion de la partida: "<<endl;
            duracion = leerEntradaInt();
            DtPartida * nueva = new DtPartidaIndividual(true, ahora, duracion); //está mal
        }
    }else{ // si eligió modo multijugador
        
    }


    system("cls");
    cout << "Ingrese Videojuego para el que desea iniciar la partida: "<< endl;
    videojuego = leerEntradaString();


/*
    try{
        //s->iniciarPartida(nickCreador, videojuego, ahora);
        cout << "PARTIDA INICIADA CON EXITO"<< endl;
        sleep(2);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }

    cout << "Partida iniciada, disfruta!"<< endl;
    sleep(2);
*/
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
        for (int i = 0; i < cantP; i++)
        {
            cout << "Duracion: " << partidas[i]->getDuracion() << endl; 
            cout << "Fecha de Creacion: " << partidas[i]->getFecha() << endl;
        }
        sleep(5);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}
