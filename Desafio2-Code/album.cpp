#include "album.h"

Album::Album(string Nombre, string ID_Album_, string Fecha,
             unsigned int Duracion, string Generos, unsigned short Puntuacion, Metrica &x):
    nombre(Nombre), ID_Album(ID_Album_), fecha(Fecha), duracion(Duracion),puntuacion(Puntuacion), generos(Generos){

    //portadaRuta="/users/storage/+Artista/+audio/image/"+Nombre;
}

Album::~Album(){}


