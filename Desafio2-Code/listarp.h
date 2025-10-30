#ifndef LISTARP_H
#define LISTARP_H

#include <iostream>
#include "cancion.h"
#include "metrica.h"
#include <usuario.h>

using namespace std;

class ListaRP {
public:
    // --- Constructor y destructor ---
    ListaRP(unsigned int TamEnUso_, Metrica &x);
    ~ListaRP();

    // --- Funcionalidad principal ---
    bool EliminarCancion(Cancion* n, Metrica &x);
    bool AgregarCancion(Cancion* n, Metrica &x);
    Cancion* TomarCancionPrevia();
    bool Reproducir(Cancion &n, Usuario &x, string ubicacion, string artista, string album);
    void MostrarLista();

    // --- Getters ---
    Cancion** GetMisFavoritas();
    Cancion* GetCancionesPrevias();
    Cancion* BuscarCancionPorCodigo(string codigo);
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
    const unsigned int CantMaxPrevias = 6;
    unsigned int indicePrevias = 0;
};

#endif // LISTARP_H
