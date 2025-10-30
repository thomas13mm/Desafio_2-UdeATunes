#include "usuario.h"
#include "listarp.h"
#include <iostream>
#include <chrono>
#include <album.h>
using namespace std;

// Constructor por defecto
Usuario::Usuario() {
    nickName = "";
    membresia = false;
    pais = "";
    fechaRegistro = "";
    MiListaRP = nullptr;
    siguiendoA = nullptr;
}

// Constructor con parámetros
Usuario::Usuario(string _nickName,
                 bool _membresia,
                 string _pais,
                 string _fechaRegistro,
                 ListaRP* _MiListaRP, Metrica &x) {
    nickName = _nickName;
    membresia = _membresia;
    pais = _pais;
    fechaRegistro = _fechaRegistro;
    MiListaRP = _MiListaRP;
    siguiendoA = nullptr;

    x.agregarMemoria(sizeof(Usuario));
}

Usuario::~Usuario(){}

// Getters
string Usuario::get_nickName() { return nickName; }
bool Usuario::get_membresia() { return membresia; }
string Usuario::get_pais() { return pais; }
string Usuario::get_fechaRegistro() { return fechaRegistro; }
ListaRP* Usuario::get_MiListaRP() { return MiListaRP; }
Usuario* Usuario::get_siguiendoA() { return siguiendoA; }

// Setters
void Usuario::set_nickName(string _nickName) { nickName = _nickName; }
void Usuario::set_membresia(bool _membresia) { membresia = _membresia; }
void Usuario::set_pais(string _pais) { pais = _pais; }
void Usuario::set_fechaRegistro(string _fechaRegistro) { fechaRegistro = _fechaRegistro; }
void Usuario::set_MiListaRP(ListaRP* _MiListaRP) { MiListaRP = _MiListaRP; }
void Usuario::set_siguiendoA(Usuario* _siguiendoA) { siguiendoA = _siguiendoA; }


bool Usuario::seguirUsuario(Usuario* otro) {
    if (MiListaRP == nullptr) return false;
    if (otro == nullptr) return false;
    if (otro->get_MiListaRP() == nullptr) return false;

    if (!membresia || !otro->get_membresia()) {
        cout << "Solo los usuarios premium pueden seguir a otros premium.\n";
        return false;
    }

    siguiendoA = otro;

    // Tomamos el arreglo de punteros a favoritas
    Cancion** favMias = MiListaRP->GetMisFavoritas();
    Cancion** favOtro = otro->get_MiListaRP()->GetMisFavoritas();
    if (favMias == nullptr || favOtro == nullptr) return false;

    const unsigned int MAX = 10000;

    unsigned int tamUso1 = MiListaRP->GetTamEnUso();
    unsigned int tamUso2 = otro->get_MiListaRP()->GetTamEnUso();

    // Verificar capacidad
    if (tamUso1 + tamUso2 > MAX) return false;

    // Copiar punteros de canciones del otro usuario
    for (unsigned int j = 0; j < tamUso2; ++j) {
        favMias[tamUso1 + j] = favOtro[j];
    }

    // Actualizar tamaño total
    MiListaRP->SetTamEnUso(tamUso1 + tamUso2);

    return true;
}

bool Usuario::dejarSeguirUsuario(Usuario* otro, Metrica &x) {
    if (MiListaRP == nullptr) return false;
    if (otro == nullptr) return false;
    if (otro->get_MiListaRP() == nullptr) return false;
    if (siguiendoA != otro) {
        cout << "El usuario actual no sigue a " << otro->get_nickName() << '\n';
        return false;
    }

    Cancion** favOtro = otro->get_MiListaRP()->GetMisFavoritas();
    if (favOtro == nullptr) return false;

    unsigned int tamUso2 = otro->get_MiListaRP()->GetTamEnUso();

    for (unsigned int j = 0; j < tamUso2; ++j) {
        Cancion* cancionOtro = favOtro[j];
        if (cancionOtro == nullptr) continue;

        MiListaRP->EliminarCancion(cancionOtro, x);
    }
    siguiendoA = nullptr;

    return true;
}



Usuario* Usuario::BuscarUser(Usuario* Usuarios, unsigned int &tam_usuarios, string &nickname){
    for(unsigned int i =0; i< tam_usuarios; i++){
        if(Usuarios[i].get_nickName()==nickname){
            return &Usuarios[i];
        }
    }
    cout<<"El usuario no existe"<<'\n';
    return nullptr;
}


void Usuario::ReproducirAutomaticamente(string ubicacion, Artista* Artistas, Album* Albumes,
                                        unsigned int cantAlbumes, unsigned int cantArtistas) {

    if (!MiListaRP) {
        cout << "No hay lista de reproduccion asociada.\n";
        return;
    }

    Cancion** fav = MiListaRP->GetMisFavoritas();
    if (!fav) {
        cout << "Lista de favoritas no disponible.\n";
        return;
    }

    unsigned int tamUso = MiListaRP->GetTamEnUso();
    if (tamUso == 0) {
        cout << "No hay canciones para reproducir.\n";
        return;
    }

    cout << "=== Reproduccion automatica (cada 5 s) ===\n";

    unsigned int reproducidas = 0;
    for (unsigned int i = 0; i < tamUso; ++i) {
        if (fav[i] == nullptr) continue;

        cout << "\n Cancion " << (reproducidas + 1) << " de " << tamUso << '\n';

        MiListaRP->Reproducir(*fav[i], *this,
                              ubicacion, fav[i]->BuscarDueno(fav[i],Artistas,cantArtistas)->getnombre(),
                                fav[i]->BuscarAlbum(fav[i],Albumes,cantAlbumes)->getnombre());


        reproducidas++;

        auto t0 = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - t0 < std::chrono::seconds(5)) {
        }
    }

    cout << "\n=== Fin de la reproduccion automatica ===\n";
}
