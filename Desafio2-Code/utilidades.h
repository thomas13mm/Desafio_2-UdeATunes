#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <usuario.h>
#include <metrica.h>
#include <anuncio.h>
#include <random>
#include <cancion.h>

bool verificar_Existencia(string &nombre, Usuario* &Usuarios, unsigned int Cant_Usuarios, Metrica &x, Usuario* &ActualUser);

void printArreglo(Cancion* &n, unsigned int cantcanciones);

Cancion* BuscarCancionPorID(Cancion* lista, unsigned int tam, string& idBuscado, Metrica &x);

Anuncio* anuncioRandom(Anuncio* anuncios);

#endif // UTILIDADES_H
