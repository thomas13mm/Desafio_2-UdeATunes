#include "listarp.h"

ListaRP::ListaRP(Cancion* MisFavoritas_, Cancion* FavoritasSeguido_): MisFavoritas(MisFavoritas_), FavoritasSeguido(FavoritasSeguido_) {
    CancionesPrevias=new Cancion[4];
}

ListaRP::~ListaRP(){
    delete[] CancionesPrevias;
}

bool ListaRP::EliminarCancion(Cancion &n, Cancion *Canciones_, unsigned int TamCanciones_){
    unsigned int IDSong=n.GetID();
    for(unsigned int i=0; i<TamCanciones_; i++){
        if(IDSong==Canciones_[i].GetID()){
            cout<<"Cancion eliminada con exito"<<'\n';
            return true;
        }
    }
    cout<<"No se pudo encontrar la cancion en su lista, por ende no se elimino"<<'\n';
    return false;
}

bool ListaRP::operator ==(ListaRP &list){
    for(unsigned int i = 0; i< ; i++){
        list.MisFavoritas[i] == this->MisFavoritas[i];
    }
}
