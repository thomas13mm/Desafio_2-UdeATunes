#include "metrica.h"
#include <iostream>
using namespace std;

long Metrica::Iter_EliminarCancion = 0;
long Metrica::Iter_AgregarCancion = 0;
long Metrica::Iter_TomarCancionPrevia = 0;
long Metrica::Iter_MostrarCanciones = 0;
long Metrica::Iter_MostrarRutaCancion = 0;
long Metrica::Iter_MostrarAlbumes = 0;

long Metrica::memoriaActual = 0;

Metrica::Metrica() {}
Metrica::~Metrica() {}

void Metrica::MemoriaTotal() {
    cout << "Memoria Total Actual: " << memoriaActual << " bytes\n";
}

void Metrica::IteracionesTotales() {
    cout << "Iteraciones Totales: "
         << Iter_EliminarCancion + Iter_AgregarCancion + Iter_TomarCancionPrevia
                + Iter_MostrarCanciones + Iter_MostrarRutaCancion + Iter_MostrarAlbumes
         << '\n';
}
