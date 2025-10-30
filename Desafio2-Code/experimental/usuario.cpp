#include "usuario.h"
#include "listarp.h"
#include <iostream>
#include <random>

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

    // Ya no sigo a nadie
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


void Usuario::ReproducirAutomaticamente() {

    if (!MiListaRP) {
        cout << "No hay lista de reproducción asociada.\n";
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

    cout << "=== Reproducción automática (cada 5 s) ===\n";

    unsigned int reproducidas = 0;
    for (unsigned int i = 0; i < tamUso; ++i) {
        if (fav[i] == nullptr) continue;

        cout << "\n Canción " << (reproducidas + 1) << " de " << tamUso << '\n';

        MiListaRP->Reproducir(*fav[i]);

        reproducidas++;

        // 3) Espera de 5 segundos usando SOLO <chrono> (busy-wait)
        auto t0 = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - t0 < std::chrono::seconds(5)) {
            // espera activa
        }
    }

    cout << "\n=== Fin de la reproducción automática ===\n";
}

void Usuario::ReproducirListaRandom() {

    if (MiListaRP == nullptr) {
        cout << "El usuario no tiene lista de reproducción.\n";
        return;
    }

    Cancion** fav = MiListaRP->GetMisFavoritas();
    if (fav == nullptr) {
        cout << "No se encontraron canciones favoritas.\n";
        return;
    }

    unsigned int tamUso = MiListaRP->GetTamEnUso();
    if (tamUso == 0) {
        cout << "No hay canciones en la lista.\n";
        return;
    }

    cout << "=== Reproducción aleatoria manual ===\n";
    cout << "Presiona ENTER para reproducir una canción aleatoria.\n";
    cout << "Escribe 0 y presiona ENTER para detener.\n\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, tamUso - 1);

    string entrada;
    while (true) {
        cout << ">>> ";
        getline(cin, entrada);

        if (entrada == "0") {
            cout << "\n=== Reproducción detenida ===\n";
            break;
        }

        unsigned int indice = dist(gen);
        while (fav[indice] == nullptr) {
            indice = dist(gen);
        }

        MiListaRP->Reproducir(*fav[indice]);
    }
}

