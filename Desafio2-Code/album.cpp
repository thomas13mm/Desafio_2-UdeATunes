#include "album.h"

Album::Album(string Nombre, string ID_Album_, string Fecha,
             float Duracion, string Generos, unsigned short Puntuacion, Metrica &x):
    nombre(Nombre), ID_Album(ID_Album_), fecha(Fecha), duracion(Duracion),puntuacion(Puntuacion), generos(Generos){

    //portadaRuta="/users/storage/+Artista/+audio/image/"+Nombre;
}

Album::~Album(){}


// Getters
string Album::getnombre() { return nombre; }
string Album::getID_Album() { return ID_Album; }
string Album::getfecha() { return fecha; }
float Album::getduracion() { return duracion; }
string* Album::getgeneros() { return generos; } // devuelve el array directamente
string Album::getselloDisquero() { return selloDisquero; }
float Album::getpuntuacion() { return puntuacion; }
Cancion** Album::getCanciones() { return Canciones; }

// Setters
void Album::setnombre(string Nombre) { nombre = Nombre; }
void Album::setID_Album(string ID) { ID_Album = ID; }
void Album::setfecha(string Fecha) { fecha = Fecha; }
void Album::setduracion(float Duracion) { duracion = Duracion; }
void Album::setgeneros(string g1, string g2, string g3, string g4) {
    generos[0] = g1;
    generos[1] = g2;
    generos[2] = g3;
    generos[3] = g4;
}
void Album::setselloDisquero(string sello) { selloDisquero = sello; }
void Album::setPuntacion(float p) { puntuacion = p; }
void Album::setCanciones(Cancion** canciones) {
    for(int i = 0; i < 10; i++) { // ajusta según el tamaño
        Canciones[i] = canciones[i];
    }
}

