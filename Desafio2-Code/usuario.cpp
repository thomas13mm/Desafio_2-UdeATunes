#include "usuario.h"
#include "listarp.h"

#include <iostream>
using namespace std;

// Constructor por defecto
Usuario::Usuario() {
    nickName = "";
    membresia = false;           // estándar por defecto
    pais = "";
    fechaRegistro = "";
    MiListaRP = nullptr;         // sin lista asignada
}

// Constructor con parametros
Usuario::Usuario(string _nickName,
                 bool _membresia,
                 string _pais,
                 string _fechaRegistro,
                 ListaRP* _MiListaRP) {
    nickName = _nickName;
    membresia = _membresia;
    pais = _pais;
    fechaRegistro = _fechaRegistro;
    MiListaRP = _MiListaRP;
}

// getters
string Usuario::get_nickName() { return nickName; }
bool Usuario::get_membresia() { return membresia; }
string Usuario::get_pais() { return pais; }
string Usuario::get_fechaRegistro() { return fechaRegistro; }
ListaRP* Usuario::get_MiListaRP() { return MiListaRP; }


// setters
void Usuario::set_nickName(string _nickName) { nickName = _nickName; }
void Usuario::set_membresia(bool _membresia) { membresia = _membresia; }
void Usuario::set_pais(string _pais) { pais = _pais; }
void Usuario::set_fechaRegistro(string _fechaRegistro) { fechaRegistro = _fechaRegistro; }
void Usuario::set_MiListaRP(ListaRP* _MiListaRP) { MiListaRP = _MiListaRP; }

bool Usuario::seguirUsuario(Usuario& otro) {
    
    // validaciones
    if (MiListaRP == nullptr) return false;
    if (otro.get_MiListaRP() == nullptr) return false;

    // Tomamos el arreglo de punteros a favoritas del otro usuario
    Cancion** favMias  = MiListaRP->GetMisFavoritas();
    Cancion** favOtro = otro.get_MiListaRP()->GetMisFavoritas();
    if (favMias == nullptr || favOtro == nullptr) return false;

    const unsigned int MAX = 10000;

    //obtener tamaños actuales (IMPORTANTE: hacer que la clase ListaRP tenga a usuario como clase amiga)
    unsigned int tamUso1 = MiListaRP->GetTamEnUso();
    unsigned int tamUso2 = otro.get_MiListaRP()->GetTamEnUso();

    // Verificar capacidad (si no caben todas, no seguimos)
    if (tamUso1 + tamUso2 > MAX) { return false; } // no hay espacio suficiente para seguir a 'otro'


    // copia los punteros de las canciones del otro usuario
    for (unsigned int j = 0; j < tamUso2; ++j) {
        favMias[tamUso1 + j] = favOtro[j];
    }

    // actualizar el nuevo tamaño total
    MiListaRP->SetTamEnUso(tamUso1 + tamUso2);


    return true;
}




