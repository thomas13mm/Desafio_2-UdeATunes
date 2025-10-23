#include "artista.h"

#include <iostream>
using namespace std;

Artista::Artista() {
    idArtista = "";
    edadArtista = 0;
    paisOrigen = "";
    cantSeguidores = 0;
    posGlobal = 0;
    cantAlbum = 0;

    // Inicializamos el arreglo con cadenas vacias
    for (unsigned int i = 0; i < 20; i++) {
        albumIDs[i] = "";
    }
}

Artista::Artista(string _idArtista,
                 unsigned short _edadArtista,
                 string _paisOrigen,
                 unsigned int _cantSeguidores,
                 unsigned int _posGlobal,
                 unsigned int _cantAlbum,
                 string _albumIDs[])
{
    idArtista = _idArtista;
    edadArtista = _edadArtista;
    paisOrigen = _paisOrigen;
    cantSeguidores = _cantSeguidores;
    posGlobal = _posGlobal;
    cantAlbum = _cantAlbum;

    // Copiar los IDs al arreglo interno (máx. 20)
    for (unsigned int i = 0; i < 20; i++) {
        if (i < cantAlbum)
            albumIDs[i] = _albumIDs[i];
        else
            albumIDs[i] = "";
    }
}

// Getters
string Artista::get_idArtista() { return idArtista; }
unsigned short Artista::get_edadArtista() { return edadArtista; }
string Artista::get_paisOrigen() { return paisOrigen; }
unsigned int Artista::get_cantSeguidores() { return cantSeguidores; }
unsigned int Artista::get_posGlobal() { return posGlobal; }
unsigned int Artista::get_cantAlbum() { return cantAlbum; }

// Setters
void Artista::set_edadArtista(unsigned short _edadArtista) { edadArtista = _edadArtista; }
void Artista::set_paisOrigen(string _paisOrigen) { paisOrigen = _paisOrigen; }
void Artista::set_cantSeguidores(unsigned int _cantSeguidores) { cantSeguidores = _cantSeguidores; }
void Artista::set_posGlobal(unsigned int _posGlobal) { posGlobal = _posGlobal; }
void Artista::set_cantAlbum(unsigned int _cantAlbum) { cantAlbum = _cantAlbum; }


// Método para mostrar los álbumes del artista
void Artista::mostrarAlbum() {
    cout << "-------------------------------------" << endl;
    cout << "Albumes asociados:" << endl;

    if (cantAlbum == 0) {
        cout << "  (Sin albumes registrados)" << endl;
        return;
    }

    for (unsigned int i = 0; i < cantAlbum; i++) {
        cout << "  - ID Album: " << albumIDs[i] << endl;
    }

    cout << "-------------------------------------" << endl;
}





