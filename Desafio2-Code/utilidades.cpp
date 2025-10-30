#include "utilidades.h"

bool verificar_Existencia(string &nombre, Usuario* &Usuarios, unsigned int Cant_Usuarios, Metrica &x, Usuario* &ActualUser){
    for(unsigned int i = 0; i<Cant_Usuarios;i++){
        if(Usuarios[i].get_nickName()==nombre){
            cout<<"Bienvenid@ "<< Usuarios[i].get_nickName()<<'\n';
            ActualUser=&Usuarios[i];
            return true;
        }
        x.SetIter_IngresoPlataforma();
    }
    cout<<"Credenciales invalidas"<<'\n';
    return false;
}

void printArreglo(Cancion* &n, unsigned int cantcanciones){
    cout<<'\n'<<"================================="<<'\n';
    for(unsigned int i=0; i<cantcanciones;i++){
        cout<<i+1<<". "<<n[i].get_Nombre()<<" "<<n[i].get_IdCanciones()<<'\n';
    }
}

Cancion* BuscarCancionPorID(Cancion* lista, unsigned int tam, string& idBuscado, Metrica &x) {
    for (unsigned int i = 0; i < tam; i++) {
        if (lista[i].get_IdCanciones() == idBuscado) {
            return &lista[i];
        }
        x.SetIter_AgregarCancion();
    }
    return nullptr;
}

Anuncio* anuncioRandom(Anuncio* anuncios){
    random_device rd;  // fuente de entropía
    mt19937 gen(rd()); // generador Mersenne Twister
    uniform_int_distribution<int> dist(0, 49); // rango 1 a 50

    return &anuncios[dist(gen)];
}

