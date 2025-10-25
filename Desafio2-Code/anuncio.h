#ifndef ANUNCIO_H
#define ANUNCIO_H
#include <iostream>
#include <metrica.h>

using namespace std;

class Anuncio{

    /*Descripcion:
     *  Clase encargada de gestionar los anuncios del programa de straming musical guardando el mensaje y la prioridad que cada
     *  uno de estos posee
     */

public:
    Anuncio(string Mensaj_Publi, string Prioridad_, Metrica &x);
    Anuncio();
    ~Anuncio();
    string GetMensaje_Publicitario();
    unsigned short int GetPrioridad();
    void SetPrioridad(char* priori);
    void SetMensaje_Publicitario(char* Mensaje_Publi);
    string getPrioridadtext();
    bool operator >(Anuncio &B);
    bool operator <(Anuncio &B);
    bool operator ==(Anuncio &B);

private:
    string Mensaje_Publicitario;
    string  Prioridad;
};

#endif // ANUNCIO_H
