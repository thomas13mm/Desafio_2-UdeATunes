#ifndef READWRITE_H
#define READWRITE_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <artista.h>
#include <usuario.h>
#include <listarp.h>
#include <anuncio.h>
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


bool readArchivo(const char* fileName, Artista* &Artistas, Album* &Albumes, Cancion* &Canciones, unsigned int &Cant_Artistas,
                     unsigned int &Cant_Albumes, unsigned int &Cant_Canciones,Metrica &x) {

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
            string partes[7];
            splitLinea(aux, '|', partes, 7);
            Artista n(partes[0], stoi(partes[1]), partes[2], stoi(partes[3]), stoi(partes[4]), partes[5], partes[6]  ,x);
            Artistas[i_artista++] = n;
            break;
        }

        case 2: {
            string partes[8];
            splitLinea(aux, '|', partes, 8);
            Album n(partes[5],partes[0],partes[3],stof(partes[4]),partes[2],stoi(partes[7]), partes[6],x);
            Albumes[i_album++] = n;
            break;
        }

        case 3: {
            string partes[5];
            splitLinea(aux, '|', partes, 5);
            Canciones[i_cancion++] = Cancion(partes[0],partes[1],stof(partes[2]),partes[3],stoi(partes[4]),x);
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


bool readArchivo(const char* fileName, Usuario*& Usuarios, unsigned int& numUsuarios, Cancion* Canciones, unsigned int numCanciones, Metrica& metrica) {
    ifstream Archivo(fileName);
    if (!Archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo de usuarios.\n";
        return false;
    }

    string linea;
    string partes[4];
    string codigos[10000]; // hasta 10k canciones favoritas por usuario
    numUsuarios = 0;

    // Primera pasada para contar usuarios
    while (getline(Archivo, linea)) {
        if (linea == "-") numUsuarios++;
    }

    if (numUsuarios == 0) {
        cout << "No se encontraron usuarios.\n";
        Archivo.close();
        return false;
    }

    // Crear el arreglo de usuarios
    Usuarios = new Usuario[numUsuarios];

    // Reiniciar archivo
    Archivo.clear();
    Archivo.seekg(0, ios::beg);

    unsigned int indiceUsuario = 0;
    bool leyendoCanciones = false;

    string nick, membresia, ciudadPais, fecha;

    while (getline(Archivo, linea)) {
        if (linea.empty()) continue;

        if (linea == "-") {
            bool esPremium = (membresia == "Premium");

            ListaRP* lista = nullptr;
            if (esPremium) {
                lista = new ListaRP(0,metrica);
                // asociar canciones a la lista
                for (unsigned int i = 0; i < 10000 && !codigos[i].empty(); i++) {
                    for (unsigned int j = 0; j < numCanciones; j++) {
                        if (Canciones[j].get_IdCanciones() == codigos[i]) {
                            lista->AgregarCancion(&Canciones[j], metrica);
                            break;
                        }
                    }
                    codigos[i] = ""; // limpiar
                }
            }

            Usuarios[indiceUsuario] = Usuario(nick, esPremium, ciudadPais, fecha, lista, metrica);
            indiceUsuario++;
            leyendoCanciones = false;
            continue;
        }

        if (!leyendoCanciones) {
            // Línea de datos del usuario
            splitLinea(linea, '|', partes, 4);
            nick = partes[0];
            membresia = partes[1];
            ciudadPais = partes[2];
            fecha = partes[3];
            leyendoCanciones = true;
            for (unsigned int i = 0; i < 10000; i++) codigos[i] = "";
        } else {
            // Línea de códigos
            int n = splitLinea(linea, ' ', codigos, 10000);
        }
    }

    Archivo.close();
    return true;
}


void read_Anuncio(const char* fileName, Anuncio* &Anuncios, Metrica &x){
    ifstream Archivo(fileName);
    unsigned int It_Anuncio=0;
    if (!Archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo de usuarios.\n";
    }
    string linea;
    string partes[2];

    while(getline(Archivo,linea) || It_Anuncio<50){
        if (linea.empty()) continue;
        splitLinea(linea,'|',partes,2);
        Anuncios[It_Anuncio++]=Anuncio(partes[1], partes[0],x);
    }
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
