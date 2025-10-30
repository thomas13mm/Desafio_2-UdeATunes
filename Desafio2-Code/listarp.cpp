#include "listarp.h"
#include <usuario.h>
#include "utilidades.h"

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

bool ListaRP::AgregarCancion(Cancion* n, Metrica &x) {
    for (unsigned int i = 0; i < MaxSongs; i++) {
        if (MisFavoritas[i] == nullptr) {
            MisFavoritas[i] = n;
            TamEnUso++;
            return true;
        }
        x.SetIter_AgregarCancion();
    }
    return false; // lista llena
}

bool ListaRP::EliminarCancion(Cancion* n, Metrica &x) {
    for (unsigned int i = 0; i < MaxSongs; i++) {
        if (MisFavoritas[i] != nullptr && MisFavoritas[i]->get_IdCanciones() == n->get_IdCanciones()) {
            MisFavoritas[i] = nullptr;
            if (TamEnUso > 0) TamEnUso--;
            return true;
        }
        x.SetIter_EliminarCancion();
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

bool ListaRP::Reproducir(Cancion &n, Usuario &x, string ubicacion, string artista, string album,Anuncio* anuncios) {
    static int contador = 0;
    contador++;

    if(!x.get_membresia() && contador % 2 == 0){
        cout << anuncioRandom(anuncios)->GetMensaje_Publicitario() << '\n';
        cout << "              Prioridad: "<<anuncioRandom(anuncios)->getPrioridadtext() << "\n\n";
    }
    cout << "\n==========================\n"<<'\n';

    cout << "Reproduciendo:\n\n";

    cout << "               " << artista << '\n';
    cout << "              " << album << "\n\n";

    cout << "                " << n.get_Nombre() << '\n';
    n.mostrarRutaCancion(x.get_membresia(),artista ,ubicacion);
    cout << "              Duracion: " << n.get_Duracion() << " min\n";
    cout<<"\n==========================\n"<<'\n';

    SetFavoritasCancionesPrevias(n);
    return true;
}

void ListaRP::MostrarLista(){
    unsigned int i=0;
    while(i<TamEnUso){
        if(this->GetMisFavoritas()[i]!=nullptr){
            cout<<i+1<<". "<<this->GetMisFavoritas()[i]->get_Nombre()<< " "<<
            this->GetMisFavoritas()[i]->get_IdCanciones()<<'\n';
        }
        i++;
    }
}

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
    CancionesPrevias[indicePrevias] = n;
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

Cancion* ListaRP::BuscarCancionPorCodigo(string codigo) {
    for (unsigned int i = 0; i < TamEnUso; i++) {
        if (MisFavoritas[i] != nullptr && MisFavoritas[i]->get_IdCanciones() == codigo) {
            return MisFavoritas[i];
        }

    }


    return nullptr;
}




