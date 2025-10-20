#ifndef LISTARP_H
#define LISTARP_H
#include <iostream>

using namespace std;


class ListaRP{    
public:
    ListaRP(Cancion* MisFavoritas_, Cancion* FavoritasSeguido_);
    ~ListaRP();
    bool EliminarCancion(Cancion &n);
    void AgregarCancion(Cancion &n);
    Cancion TomarCancionPrevia();
    bool Reproducir();

    Cancion* GetMisFavoritas();
    Cancion* GetFavoritasSeguido();
    unsigned int* GetCancionesPrevias();

    void SetMisFavoritas();
    void SetFavoritasSeguido();
    void SetFavoritasCancionesPrevias();

    bool operator== (ListaRP &list);
    bool operator< ();
    bool operator> ();

private:
    Cancion* MisFavoritas;
    Cancion* FavoritasSeguido;
    unsigned int* CancionesPrevias;
};

#endif // LISTARP_H
