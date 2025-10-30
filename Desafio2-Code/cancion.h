#ifndef _CANCION_H_
#define _CANCION_H_

#include <metrica.h>
#include <string>
#include <artista.h>

using namespace std;

class Album;

class Cancion {
private:
    string nombre;
    string idCanciones;    // 9 dígitos
    string creditos;
    unsigned int cantReproducciones;
    string autor;
    float duracion;

public:
    Cancion(); // constructor por defecto

    // constructor con parametros
    Cancion(string _idCanciones,
            string _nombre,
            float _duracion,
            string Autor,
            unsigned int _cantReproducciones, Metrica &x);

    ~Cancion();

    // getters
    string get_Nombre();
    string get_IdCanciones();
    float get_Duracion();
    string get_UbicacionArchivo();
    string getcreditos();
    unsigned int get_CantReproducciones();

    // setters
    void set_IdCanciones(string _idCanciones);
    void set_Duracion(float _duracion);
    void set_CantReproducciones(unsigned int _cantReproducciones);

    void mostrarRutaCancion(bool esPremium, string nombreArtista, string ubicacionArchivo="/users/storage/Thomas/");
    Artista* BuscarDueno(Cancion* x, Artista* Artistas,unsigned int cantArtist);
    Album* BuscarAlbum(Cancion *x, Album* Albumes, unsigned int cantAlbumes);

};

#endif
