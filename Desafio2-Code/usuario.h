#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

//declaracion recursiva para el apuntador a tipo ListaRP
class ListaRP;

class Usuario {
private:
    string nickName;
    bool membresia; // true = premium, false = estándar
    string pais;
    string fechaRegistro;
    ListaRP* MiListaRP; // puntero a la lista del usuario

public:
    Usuario(); // constructor por defecto

     // constructor por parametros
    Usuario(string _nickName,
            bool _membresia,
            string _pais,
            string _fechaRegistro,
            ListaRP* _MiListaRP);


    // Getters
    string get_nickName();
    bool get_membresia();
    string get_pais();
    string get_fechaRegistro();
    ListaRP* get_MiListaRP();

    // Setters
    void set_nickName(string _nickName);
    void set_membresia(bool _membresia);
    void set_pais(string _pais);
    void set_fechaRegistro(string _fechaRegistro);
    void set_MiListaRP(ListaRP* _MiListaRP);

    bool seguirUsuario(Usuario& otro);
    void SiguienteCancion();
    void AnteriorCancion();
    void RepetirCancionActual();
    void ReproducirAutomaticamente(); //chronos
    void ReproducirListaOrden();
    void ReproducirListaRandom();

};

#endif // USUARIO_H
