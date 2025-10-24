#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
using namespace std;

class Artista {
private:
    string idArtista;
    unsigned short edadArtista;
    string paisOrigen;
    unsigned int cantSeguidores;
    unsigned int posGlobal;
    unsigned int cantAlbum;     // se calcula automáticamente
    string albumIDs[20];        // máximo 20 álbumes

public:
    // Constructor recibe un SOLO string con álbums separados por coma
    Artista(string _idArtista,
            unsigned short _edadArtista,
            string _paisOrigen,
            unsigned int _cantSeguidores,
            unsigned int _posGlobal,
            string _albumIDs);  // <<<<< CAMBIO AQUÍ

    Artista();
    ~Artista();

    // getters
    string get_idArtista();
    unsigned short get_edadArtista();
    string get_paisOrigen();
    unsigned int get_cantSeguidores();
    unsigned int get_posGlobal();

    // setters
    void set_edadArtista(unsigned short _edadArtista);
    void set_paisOrigen(string _paisOrigen);
    void set_cantSeguidores(unsigned int _cantSeguidores);
    void set_posGlobal(unsigned int _posGlobal);

    void mostrarAlbum() const;
};
#endif

