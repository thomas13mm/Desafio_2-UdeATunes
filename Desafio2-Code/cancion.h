#ifndef _CANCION_H_
#define _CANCION_H_

#include <string>
using namespace std;

class Cancion {
private:
    string nombre;
    string idCanciones;    // 9 dígitos
    float duracion;      // en minutos
    string ubicacionArchivo;
    unsigned int cantReproducciones;

public:
    Cancion(); // constructor por defecto


    // constructor con parametros
    Cancion(string _idCanciones,
            string _nombre,
            float _duracion,
            string _ubicacionArchivo,
            unsigned int _cantReproducciones);

    // getters
    string get_Nombre();
    string get_IdCanciones();
    float get_Duracion();
    string get_UbicacionArchivo();
    unsigned int get_CantReproducciones();

    // setters
    void set_IdCanciones(string _idCanciones);
    void set_Duracion(float _duracion);
    void set_CantReproducciones(unsigned int _cantReproducciones);

    // Muestra la ruta completa de la cancion, recibiendo el artista
    void mostrarRutaCancion(bool esPremium, string nombreArtista);

};

#endif
