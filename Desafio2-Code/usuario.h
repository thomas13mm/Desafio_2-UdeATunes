#ifndef USUARIO_H
#define USUARIO_H

#include <metrica.h>
#include <string>
#include <chrono>
using namespace std;

// Declaración anticipada
class ListaRP;

class Usuario {
private:
    string nickName;
    bool membresia; // true = premium, false = estándar
    string pais;
    string fechaRegistro;
    ListaRP* MiListaRP; // puntero a la lista del usuario
    Usuario* siguiendoA; // 🔹 nuevo: usuario al que sigue (solo premium)

public:
    Usuario(); // constructor por defecto

    Usuario(string _nickName,
            bool _membresia,
            string _pais,
            string _fechaRegistro,
            ListaRP* _MiListaRP,
            Metrica &x);

    ~Usuario();

    // Getters
    string get_nickName();
    bool get_membresia();
    string get_pais();
    string get_fechaRegistro();
    ListaRP* get_MiListaRP();
    Usuario* get_siguiendoA(); // 🔹 nuevo getter

    // Setters
    void set_nickName(string _nickName);
    void set_membresia(bool _membresia);
    void set_pais(string _pais);
    void set_fechaRegistro(string _fechaRegistro);
    void set_MiListaRP(ListaRP* _MiListaRP);
    void set_siguiendoA(Usuario* _siguiendoA); // 🔹 nuevo setter

    bool seguirUsuario(Usuario* otro);
    bool dejarSeguirUsuario(Usuario* otro, Metrica &x);
    void SiguienteCancion();
    void AnteriorCancion();
    void RepetirCancionActual();
    void ReproducirAutomaticamente(); // chronos
    void ReproducirListaOrden();
    void ReproducirListaRandom();
    Usuario* BuscarUser(Usuario* Usuarios, unsigned int &tam_usuarios, string &nickname);
};

#endif

