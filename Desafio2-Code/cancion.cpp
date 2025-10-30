#include "cancion.h"
#include <iostream>
#include <string>
#include <album.h>

using namespace std;

// Constructor por defecto: inicializa con valores seguros
Cancion::Cancion()
    : nombre(""),
    idCanciones(""),
    duracion(0),
    cantReproducciones(0) {}


// Constructor con parámetros
Cancion::Cancion(string _idCanciones,
                 string _nombre,
                 float _duracion,
                 string Autor,
                 unsigned int _cantReproducciones, Metrica &x)
    : nombre(_nombre),
    idCanciones(_idCanciones),
    duracion(_duracion),
    autor(Autor),
    cantReproducciones(_cantReproducciones) {
    x.agregarMemoria(sizeof(Cancion));
}

Cancion::~Cancion(){}

// getters
string Cancion::get_Nombre() { return nombre; }
string Cancion::get_IdCanciones() { return idCanciones; }
float Cancion::get_Duracion() { return duracion; }
unsigned int Cancion::get_CantReproducciones() { return cantReproducciones; }
string Cancion::getcreditos(){return autor;}

// setters
void Cancion::set_IdCanciones(string _idCanciones) { idCanciones = _idCanciones; }
void Cancion::set_Duracion(float _duracion) { duracion = _duracion; }
void Cancion::set_CantReproducciones(unsigned int _cantReproducciones) { cantReproducciones = _cantReproducciones; }


Artista* Cancion::BuscarDueno(Cancion* x, Artista*  Artistas, unsigned int cantArtist){
    for(unsigned int i=0; i<cantArtist;i++){
        if(Artistas[i].get_idArtista()==x->get_IdCanciones().substr(0,5))return &Artistas[i];
    }
    return nullptr;
}

Album* Cancion::BuscarAlbum(Cancion *x, Album *Albumes, unsigned int cantAlbumes){
    for(unsigned int i=0; i<cantAlbumes; i++){
        if(Albumes[i].getID_Album()==x->get_IdCanciones().substr(7,7))return &Albumes[i];
    }
    return nullptr;
}

void Cancion::mostrarRutaCancion(bool esPremium, string nombreArtista, string ubicacionArchivo) {

    // Determinar calidad
    string calidad = esPremium ? "_320.ogg" : "_128.ogg";

    // Convertir artista y cancion a minusculas
    for (unsigned int i = 0; i < nombreArtista.size(); i++) {
        if (nombreArtista[i] >= 'A' && nombreArtista[i] <= 'Z') {
            nombreArtista[i] = nombreArtista[i] + 32;
        }
    }

    string nombreCancion = nombre;
    for (unsigned int i = 0; i < nombreCancion.size(); i++) {
        if (nombreCancion[i] >= 'A' && nombreCancion[i] <= 'Z') {
            nombreCancion[i] = nombreCancion[i] + 32;
        }
    }

    // Reemplazar espacios por "\ "
    string artistaEscapado;
    for (unsigned int i = 0; i < nombreArtista.size(); i++) {
        if (nombreArtista[i] == ' ') {
            artistaEscapado += "\\ ";
        } else {
            artistaEscapado += nombreArtista[i];
        }
    }

    string cancionEscapada;
    for (unsigned int i = 0; i < nombreCancion.size(); i++) {
        if (nombreCancion[i] == ' ') {
            cancionEscapada += "\\ ";
        } else {
            cancionEscapada += nombreCancion[i];
        }
    }

    // Construir la ruta completa
    string ruta = ubicacionArchivo + artistaEscapado + "/audio/" + cancionEscapada + calidad;
    cout << ruta << endl;

}





