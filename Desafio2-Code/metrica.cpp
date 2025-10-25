#include "metrica.h"
#include <iostream>
using namespace std;

// Inicialización de las variables estáticas
long Metrica::Iter_EliminarCancion = 0;
long Metrica::Iter_AgregarCancion = 0;
long Metrica::Iter_IngresoPlataforma = 0;
long Metrica::memoriaActual = 0;

Metrica::Metrica() {}
Metrica::~Metrica() {}

void Metrica::MemoriaTotal() {
    cout << "Memoria actual utilizada: " << memoriaActual << " bytes" << endl;
}

void Metrica::IteracionesTotales() {
    cout << "Iteraciones registradas:" << endl;
    cout << "  Eliminar Cancion: " << Iter_EliminarCancion << endl;
    cout << "  Agregar Cancion: " << Iter_AgregarCancion << endl;
    cout << "  Ingreso Plataforma: " << Iter_IngresoPlataforma << endl;
}

void Metrica::ReiniciarMetricas() {
    Iter_EliminarCancion = 0;
    Iter_AgregarCancion = 0;
    Iter_IngresoPlataforma = 0;
    memoriaActual = 0;
}
