#include "listarp.h"

ListaRP::ListaRP(unsigned int TamEnUso_, Metrica &x):TamEnUso(TamEnUso_) {
    CancionesPrevias=new Cancion[CantMaxPrevias];
    MisFavoritas=new Cancion*[MaxSongs];
    x.agregarMemoria(sizeof(CancionesPrevias));
}

ListaRP::~ListaRP(Metrica &x){
    for(unsigned int i=0; i<TamEnUso; i++){
        delete MisFavoritas[i];
    }
    delete[] CancionesPrevias;
}

bool ListaRP::EliminarCancion(Cancion &n){
    for(unsigned int i = 0; i<TamEnUso; i++){
        if((this->MisFavoritas[i]->ID_Canciones)==(n.ID_Canciones)){   //deberia ser un getter de id_canciones
            this->MisFavoritas[i]=nullptr;
            return true;
        }
    }
    return false;
}

bool ListaRP::AgregarCancion(Cancion &n){
    unsigned int i=0;
    while(i<MaxSongs){
        if(this->MisFavoritas[i]!=nullptr){
            this->MisFavoritas[i]=n;
            return true;
        }
        i++;
    }
    return false;
}

Cancion* ListaRP::TomarCancionPrevia(){
    for(unsigned int n=0; n<CantMaxPrevias; n++){
        if(this->CancionesPrevias[n]!=nullprt){
            return this->CancionesPrevias[n];
        }
    }
    cout<<"No puede regresar mas de 4 canciones"<<'\n';
    return nullptr;
}

void ListaRP::Reproducir(Cancion &n){//podria recibir el album y el artista para intentar reproducir todo de una
    cout<<n.Nombre<<'\n';
    cout<<n.Ubicacion_Archivo<<'\n';
    cout<<n.Duracion<<'\n';
}

Cancion** ListaRP::GetMisFavoritas(){
    return this->MisFavoritas;
}

Cancion* ListaRP::GetCancionesPrevias(){
    return this->CancionesPrevias;
}

bool ListaRP::SetFavoritasCancionesPrevias(Cancion &n) {
    this->CancionesPrevias[indicePrevias] = &n;
    indicePrevias = (indicePrevias + 1) % CantMaxPrevias;

    return true;
}

