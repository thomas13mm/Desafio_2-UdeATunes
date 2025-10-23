#ifndef READWRITE_H
#define READWRITE_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool readArchivo(const char* fileName) {
    ifstream Archivo(fileName);
    if (!Archivo.is_open()) {
        cout << "Actualmente presentamos problemas para leer nuestros datos, lo sentimos." << '\n';
        return false;
    }
    string aux;
    while (getline(Archivo, aux)) {

        cout << aux << endl;
    }


    Archivo.close();
    return true;
}

#endif // READWRITE_H
