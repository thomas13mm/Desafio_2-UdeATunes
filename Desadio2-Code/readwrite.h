#ifndef READWRITE_H
#define READWRITE_H
#include <iostream>
#include <fstream>
#include <string>
#include <artista.h>
#include <album.h>
#include <cancion.h>
#include <readwrite.h>

using namespace std;

void readArtista(Artista* Artistas, string line);
void contarSeccionesEnArchivo(const char* fileName, unsigned int& numArtistas, unsigned int& numAlbumes, unsigned int& numCanciones);

int splitLinea(const string &linea, char separador, string partes[], int maxPartes) {
    int count = 0;
    string actual = "";

    for (unsigned int i = 0; i <= linea.length(); i++) {
        if (i == linea.length() || linea[i] == separador) {
            // Eliminar espacios al inicio
            while (actual.length() > 0 && actual[0] == ' ')
                actual.erase(0, 1);
            // Eliminar espacios al final
            while (actual.length() > 0 && actual[actual.length() - 1] == ' ')
                actual.erase(actual.length() - 1, 1);

            partes[count++] = actual;
            actual = "";
            if (count >= maxPartes) break;
        } else {
            actual += linea[i];
        }
    }
    return count;
}


bool readArchivo(const char* fileName, Artista* &Artistas, Album* &Albumes, Cancion* &Canciones) {
    Metrica x;
    unsigned int Cant_Artistas;
    unsigned int Cant_Albumes;
    unsigned int Cant_Canciones;

    contarSeccionesEnArchivo(fileName, Cant_Artistas, Cant_Albumes, Cant_Canciones);

    ifstream Archivo(fileName);
    if (!Archivo.is_open()) {
        cout << "Actualmente presentamos problemas para leer nuestros datos, lo sentimos." << '\n';
        return false;
    }

    // Reservar memoria una sola vez
    Artistas  = new Artista[Cant_Artistas];
    Albumes   = new Album[Cant_Albumes];
    Canciones = new Cancion[Cant_Canciones];

    unsigned short int control = 0;
    unsigned int i_artista = 0, i_album = 0, i_cancion = 0;
    string aux;

    while (getline(Archivo, aux)) {
        if (aux == "ARTISTAS") {
            control = 1;
            continue;
        } else if (aux == "ALBUMES") {
            control = 2;
            continue;
        } else if (aux == "CANCIONES") {
            control = 3;
            continue;
        }
        else if(aux==""){
            continue;
        }

        switch (control) {
        case 1: {
            string partes[6];
            splitLinea(aux, '|', partes, 6);
            Artista n(partes[0], stoi(partes[1]), partes[2], stoi(partes[3]), stoi(partes[4]), partes[5]);
            Artistas[i_artista++] = n;
            break;
        }

        case 2: {
            string partes[8];
            splitLinea(aux, '|', partes, 8);
            Album n(partes[5],partes[0],partes[3],stof(partes[4]),partes[2],stoi(partes[7]),x, partes[6]);
            Albumes[i_album++] = n;
            break;
        }

        case 3: {
            string partes[5];
            splitLinea(aux, '|', partes, 5);
            Cancion n(partes[0],partes[1],stof(partes[2]),partes[3],stoi(partes[4]));
            Canciones[i_cancion++] = n;
            break;
        }

        default: {
            break;
        }
        }
    }

    Archivo.close();
    return true;
}

void contarSeccionesEnArchivo(const char* fileName, unsigned int& numArtistas, unsigned int& numAlbumes, unsigned int& numCanciones) {
    ifstream Archivo(fileName);
    if (!Archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo para contar." << '\n';
        numArtistas = numAlbumes = numCanciones = 0;
        return;
    }

    string aux;
    unsigned short int control = 0;
    numArtistas = numAlbumes = numCanciones = 0;

    while (getline(Archivo, aux)) {
        if (aux == "ARTISTAS") {
            control = 1;
            continue;
        } else if (aux == "ALBUMES") {
            control = 2;
            continue;
        } else if (aux == "CANCIONES") {
            control = 3;
            continue;
        }

        // Ignorar líneas vacías
        if (aux.empty())
            continue;

        // Contar según la sección actual
        switch (control) {
        case 1: numArtistas++; break;
        case 2: numAlbumes++; break;
        case 3: numCanciones++; break;
        default: break;
        }
    }

    Archivo.close();
}


#endif // READWRITE_H
