#include "anuncio.h"

Anuncio::Anuncio(){}

Anuncio::Anuncio(string Mensaj_Publi, string  Prioridad_, Metrica &x) {
    Mensaje_Publicitario=Mensaj_Publi;
    Prioridad=Prioridad_;
    x.agregarMemoria(sizeof(Mensaje_Publicitario) + sizeof(Prioridad));
}

Anuncio::~Anuncio(){

}

void Anuncio::SetMensaje_Publicitario(char* Mensaje_Publi){
    this->Mensaje_Publicitario=Mensaje_Publi;
}

void Anuncio::SetPrioridad(char* priori){
    this->Prioridad=priori;
}

string Anuncio::GetMensaje_Publicitario(){
    return Mensaje_Publicitario;
}

unsigned short int Anuncio::GetPrioridad(){
    if (Prioridad=="AAA")return 3;
    else if(Prioridad=="B")return 2;
    else if(Prioridad=="C") return 1;
    return 0;
}

string Anuncio::getPrioridadtext(){
    return Prioridad;
}

bool Anuncio::operator> (Anuncio &B){
    /*Descripcion:
     *  Sirve para comparar la prioridad entre anuncios para saber si un anuncio A tiene mayor prioridad que un anuncio B
     */

    if(this->GetPrioridad() > B.GetPrioridad()) return true;
    else if(this->GetPrioridad() == B.GetPrioridad())return false;
    else if(this->GetPrioridad() < B.GetPrioridad())return false;
    else{ cout<<"Imposible comparar"<<" Error de la clase Anuncio operator>"<<'\n'; return false;
    }
}

bool Anuncio::operator <(Anuncio &B){
    /*Descripcion:
     *  Sirve para comparar la prioridad entre anuncios para saber si un anuncio A tiene menor prioridad de un anuncio B
     */

    if(this->GetPrioridad() < B.GetPrioridad()) return true;
    else if(this->GetPrioridad() == B.GetPrioridad())return false;
    else if(this->GetPrioridad() > B.GetPrioridad())return false;
    else{ cout<<"Imposible comparar"<<" Error de la clase Anuncio operator>"<<'\n'; return false;
    }
}

bool Anuncio::operator ==(Anuncio &B){
    if(this->GetPrioridad()==B.GetPrioridad()) return true;
    else{return false;}
}
