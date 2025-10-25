#include "artista.h"
#include <iostream>
#include <metrica.h>

using namespace std;

Artista::Artista() {
    idArtista = "";
    edadArtista = 0;
    paisOrigen = "";
    cantSeguidores = 0;
    posGlobal = 0;
    cantAlbum = 0;
    for (unsigned int i = 0; i < 20; i++)
        albumIDs[i] = "";
}

Artista::Artista(string _idArtista,
                 unsigned short _edadArtista,
                 string _paisOrigen,
                 unsigned int _cantSeguidores,
                 unsigned int _posGlobal,
                 string _albumIDs, Metrica &x) // <<<<< Recibe solo un string
{
    idArtista = _idArtista;
    edadArtista = _edadArtista;
    paisOrigen = _paisOrigen;
    cantSeguidores = _cantSeguidores;
    posGlobal = _posGlobal;

    // Procesar el string separado por comas
    cantAlbum = 0;
    string temp = "";
    for (size_t i = 0; i <= _albumIDs.size(); i++) {
        if (i == _albumIDs.size() || _albumIDs[i] == ',') {
            if (!temp.empty()) {
                albumIDs[cantAlbum++] = temp;
                temp = "";
            }
        } else {
            temp += _albumIDs[i];
        }
    }

    // Rellenar vacíos
    for (unsigned int i = cantAlbum; i < 20; i++)
        albumIDs[i] = "";

    x.agregarMemoria(sizeof(Artista));
}


Artista::~Artista() {}

string Artista::get_idArtista() { return idArtista; }
unsigned short Artista::get_edadArtista() { return edadArtista; }
string Artista::get_paisOrigen() { return paisOrigen; }
unsigned int Artista::get_cantSeguidores() { return cantSeguidores; }
unsigned int Artista::get_posGlobal() { return posGlobal; }

void Artista::set_edadArtista(unsigned short _edadArtista) { edadArtista = _edadArtista; }
void Artista::set_paisOrigen(string _paisOrigen) { paisOrigen = _paisOrigen; }
void Artista::set_cantSeguidores(unsigned int _cantSeguidores) { cantSeguidores = _cantSeguidores; }
void Artista::set_posGlobal(unsigned int _posGlobal) { posGlobal = _posGlobal; }

void Artista::mostrarAlbum() const {
    cout << "-------------------------------------\n";
    cout << "Álbumes asociados:\n";
    if (cantAlbum == 0) {
        cout << "  (Sin álbumes registrados)\n";
    } else {
        for (unsigned int i = 0; i < cantAlbum; i++) {
            cout << "  - ID Álbum: " << albumIDs[i] << "\n";
        }
    }
    cout << "-------------------------------------\n";
}


