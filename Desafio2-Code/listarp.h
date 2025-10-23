#ifndef LISTARP_H
#define LISTARP_H
#include <iostream>
#include <cancion.h>
#include <metrica.h>

using namespace std;

class ListaRP{    
public:
    ListaRP(unsigned int TamEnUso_,Metrica &x); //listo
    ~ListaRP();//listo
    bool EliminarCancion(Cancion &n);//listo
    bool AgregarCancion(Cancion &n);//listo
    Cancion* TomarCancionPrevia();//listo
    bool Reproducir(Cancion &n); //listo

    Cancion** GetMisFavoritas();//Listo
    Cancion* GetCancionesPrevias();//listo

    //void SetMisFavoritas();
    //void SetFavoritasSeguido();
    bool SetFavoritasCancionesPrevias(Cancion &n);//listo

    //bool operator== (ListaRP &list);
    //bool operator< ();
    //bool operator> ();

private:
    Cancion** MisFavoritas;
    Cancion* CancionesPrevias;
    unsigned int TamEnUso;
    const unsigned int MaxSongs=10000;
    const unsigned int CantMaxPrevias=4;
    unsigned int indicePrevias = 0;
};

#endif // LISTARP_H
