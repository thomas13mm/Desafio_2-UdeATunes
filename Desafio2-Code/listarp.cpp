#include "listarp.h"

ListaRP::ListaRP(unsigned int TamEnUso_, Metrica &x)
    : TamEnUso(TamEnUso_)
{
    CancionesPrevias = new Cancion[CantMaxPrevias];
    MisFavoritas = new Cancion*[MaxSongs];

    for (unsigned int i = 0; i < MaxSongs; i++) {
        MisFavoritas[i] = nullptr;
    }

    x.agregarMemoria(sizeof(Cancion*) * MaxSongs + sizeof(Cancion) * CantMaxPrevias);
}

ListaRP::~ListaRP() {
    delete[] MisFavoritas;
    delete[] CancionesPrevias;
}

// -------------------------------------
//          FUNCIONES PRINCIPALES
// -------------------------------------

bool ListaRP::AgregarCancion(Cancion &n) {
    for (unsigned int i = 0; i < MaxSongs; i++) {
        if (MisFavoritas[i] == nullptr) {
            MisFavoritas[i] = &n;  // guarda dirección
            TamEnUso++;
            return true;
        }
    }
    return false; // lista llena
}

bool ListaRP::EliminarCancion(Cancion &n) {
    for (unsigned int i = 0; i < MaxSongs; i++) {
        if (MisFavoritas[i] != nullptr && MisFavoritas[i]->get_IdCanciones() == n.get_IdCanciones()) {
            MisFavoritas[i] = nullptr;
            if (TamEnUso > 0) TamEnUso--;
            return true;
        }
    }
    return false;
}

Cancion* ListaRP::TomarCancionPrevia() {
    if (TamEnUso == 0) {
        cout << "No hay canciones previas disponibles.\n";
        return nullptr;
    }

    if (indicePrevias == 0)
        indicePrevias = CantMaxPrevias - 1;
    else
        indicePrevias--;

    return &CancionesPrevias[indicePrevias];
}

bool ListaRP::Reproducir(Cancion &n) {
    cout << "Reproduciendo:\n";
    cout << "  Nombre: " << n.get_Nombre() << '\n';
    //cout << "  Autor: " << n.getcreditos << '\n';
    cout << "  Duración: " << n.get_Duracion() << " min\n";
    //cout << "  Ubicación: " << n.mostrarRutaCancion() << "\n\n";

    SetFavoritasCancionesPrevias(n);
    return true;
}

// -------------------------------------
//               GETTERS
// -------------------------------------

Cancion** ListaRP::GetMisFavoritas() {
    return MisFavoritas;
}

Cancion* ListaRP::GetCancionesPrevias() {
    return CancionesPrevias;
}

unsigned int ListaRP::GetTamEnUso() const {
    return TamEnUso;
}

unsigned int ListaRP::GetMaxSongs() const {
    return MaxSongs;
}

unsigned int ListaRP::GetCantMaxPrevias() const {
    return CantMaxPrevias;
}

unsigned int ListaRP::GetIndicePrevias() const {
    return indicePrevias;
}

// -------------------------------------
//               SETTERS
// -------------------------------------

bool ListaRP::SetFavoritasCancionesPrevias(Cancion &n) {
    CancionesPrevias[indicePrevias] = n; // copia la canción
    indicePrevias = (indicePrevias + 1) % CantMaxPrevias;
    return true;
}

void ListaRP::SetTamEnUso(unsigned int nuevoTam) {
    if (nuevoTam <= MaxSongs) {
        TamEnUso = nuevoTam;
    }
}

void ListaRP::SetIndicePrevias(unsigned int nuevoIndice) {
    if (nuevoIndice < CantMaxPrevias) {
        indicePrevias = nuevoIndice;
    }
}


