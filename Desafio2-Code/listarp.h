#ifndef LISTARP_H
#define LISTARP_H

#include <iostream>
#include "cancion.h"
#include "metrica.h"

using namespace std;

class ListaRP {
public:
    // --- Constructor y destructor ---
    ListaRP(unsigned int TamEnUso_, Metrica &x);
    ~ListaRP();

    // --- Funcionalidad principal ---
    bool EliminarCancion(Cancion &n);
    bool AgregarCancion(Cancion &n);
    Cancion* TomarCancionPrevia();
    bool Reproducir(Cancion &n);

    // --- Getters ---
    Cancion** GetMisFavoritas();
    Cancion* GetCancionesPrevias();
    unsigned int GetTamEnUso() const;
    unsigned int GetMaxSongs() const;
    unsigned int GetCantMaxPrevias() const;
    unsigned int GetIndicePrevias() const;

    // --- Setters ---
    bool SetFavoritasCancionesPrevias(Cancion &n);
    void SetTamEnUso(unsigned int nuevoTam);
    void SetIndicePrevias(unsigned int nuevoIndice);

private:
    Cancion** MisFavoritas;         // Arreglo de punteros a canciones favoritas
    Cancion* CancionesPrevias;      // Arreglo de canciones reproducidas recientemente
    unsigned int TamEnUso;          // Cantidad de canciones actualmente en uso
    const unsigned int MaxSongs = 10000;
    const unsigned int CantMaxPrevias = 4;
    unsigned int indicePrevias = 0;
};

#endif // LISTARP_H
