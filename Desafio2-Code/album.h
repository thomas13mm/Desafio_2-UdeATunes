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
    void mostrarCanciones();

    string getnombre();
    string getID_Album();
    string getfecha();
    unsigned int getduracion();
    string* getgeneros();
    string getselloDisquero();
    //string getportadaRuta();
    float getpuntuacion();
    Cancion** getCanciones();

    void setnombre();
    void setID_Album();
    void setfecha();
    unsigned int setduracion();
    void setgeneros();
    void setselloDisquero();
    //string setportadaRuta();
    void setPuntacion();
    void setCanciones();


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
