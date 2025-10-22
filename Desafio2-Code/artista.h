#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
using namespace std;

class Artista {
private:
    string idArtista; // 5 digitos
    unsigned short edadArtista;
    string paisOrigen;
    unsigned int cantSeguidores;
    unsigned int posGlobal;
    unsigned int cantAlbum; // cantidad de albumes
    string albumIDs[20]; // arreglo tipo string de ID de albumes

public:
    Artista(); // constructor por defecto

    // constructor con parametros
    Artista(string _idArtista,
            unsigned short _edadArtista,
            string _paisOrigen,
            unsigned int _cantSeguidores,
            unsigned int _posGlobal,
            unsigned int _cantAlbum,
            string _albumIDs[]);

    // getters
    string get_idArtista();
    unsigned short get_edadArtista();
    string get_paisOrigen();
    unsigned int get_cantSeguidores();
    unsigned int get_posGlobal();
    unsigned int get_cantAlbum();

    // setters
    void set_edadArtista(unsigned short _edadArtista);
    void set_paisOrigen(string _paisOrigen);
    void set_cantSeguidores(unsigned int _cantSeguidores);
    void set_posGlobal(unsigned int _posGlobal);
    void set_cantAlbum(unsigned int _cantAlbum);


    void mostrarAlbum();
};

#endif // ARTISTA_H
