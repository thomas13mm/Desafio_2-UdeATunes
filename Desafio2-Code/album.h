#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include <iostream>
#include <cancion.h>
#include <metrica.h>

using namespace std;

class Album{
public:
    Album(string Nombre, string ID_Album_, string Fecha, unsigned int Duracion, string Generos,
            unsigned short int Puntuacion, Metrica &x);
    ~Album();

    // Getters
    string getnombre();
    string getID_Album();
    string getfecha();
    unsigned int getduracion();
    string* getgeneros();
    string getselloDisquero();
    float getpuntuacion();
    Cancion** getCanciones();

    // Setters
    void setnombre(string Nombre);
    void setID_Album(string ID);
    void setfecha(string Fecha);
    void setduracion(unsigned int Duracion);
    void setgeneros(string g1, string g2, string g3, string g4);
    void setselloDisquero(string sello);
    void setPuntacion(float p);
    void setCanciones(Cancion** canciones);

    // Otros métodos
    void mostrarCanciones();

private:
    string nombre;
    string ID_Album;
    string fecha;
    unsigned int duracion; //en minutos la puse
    string generos[4];
    string selloDisquero;
    string portadaRuta;
    float puntuacion;
    Cancion** Canciones;
    Metrica x;
};

#endif // ALBUM_H
