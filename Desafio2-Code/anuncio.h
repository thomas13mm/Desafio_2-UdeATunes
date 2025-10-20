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
    Anuncio(char* Mensaj_Publi, const char* Prioridad_, Metrica &x);
    ~Anuncio();
    char* GetMensaje_Publicitario();
    unsigned short int GetPrioridad();
    void SetPrioridad(char* priori);
    void SetMensaje_Publicitario(char* Mensaje_Publi);
    bool operator >(Anuncio &B);
    bool operator <(Anuncio &B);
    bool operator ==(Anuncio &B);

private:
    char* Mensaje_Publicitario;
    const char* Prioridad;
};

#endif // ANUNCIO_H
