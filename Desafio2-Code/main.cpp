#include <iostream>
#include <ReadWrite.h>
#include <metrica.h>
#include <artista.h>
#include <album.h>
#include <cancion.h>
#include <usuario.h>
#include <listarp.h>

using namespace std;

int main() {
    Metrica x;
    const char* name = "dataset_AAC.txt";
    const char* name2 = "dataset_ULR.txt";

    unsigned int CArtistas = 0;
    unsigned int CAlbumes = 0;
    unsigned int CCanciones = 0;
    unsigned int CUsuarios = 0;

    Artista* Artistas = nullptr;
    Album* Albumes = nullptr;
    Cancion* Canciones = nullptr;
    Usuario* Usuarios = nullptr;

    readArchivo(name, Artistas, Albumes, Canciones, CArtistas, CAlbumes, CCanciones);

    readArchivo(name2, Usuarios, CUsuarios, Canciones, CCanciones, x);

    cout<< " Wait ";

    delete[] Usuarios;
    delete[] Canciones;
    delete[] Albumes;
    delete[] Artistas;

    return 0;
}

