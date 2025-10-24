#include <iostream>
#include <ReadWrite.h>
#include <metrica.h>
#include <artista.h>
#include <album.h>
#include <cancion.h>

using namespace std;

int main(){
    const char* name="dataset_AAC.txt";
    Artista* Artistas;
    Album* Albumes;
    Cancion* Canciones;
    readArchivo(name, Artistas, Albumes, Canciones);

    delete[] Artistas;
    delete[] Albumes;
    delete[] Canciones;
    return 0;
}
