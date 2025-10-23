#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

//declaracion recursiva para el apuntador a tipo ListaRP
class ListaRP {};

class Usuario {
private:
    string nickName;
    bool membresia;
    string pais;
    string fechaRegistro;
    ListaRP* MiListaRP;

public:

    // Getters
    string get_nickName();
    bool get_membresia();
    string get_pais();
    string get_fechaRegistro();
    ListaRP get_MiListaRP();

    // Setters
    void set_nickName(string _nickName);
    void set_membresia(bool _membresia);
    void set_pais(string _pais);
    void set_fechaRegistro();
    void set_MiListaRP(ListaRP* _MiListaRP);

    void seguirUsuario();
    void SiguienteCancion();
    void AnteriorCancion();
    void RepetirCancionActual();
    void ReproducirAutomaticamente(); //chronos
    void ReproducirListaOrden();
    void ReproducirListaRandom();

};

#endif // USUARIO_H
