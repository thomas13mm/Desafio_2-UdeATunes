
#include <string>

class Cancion {
private:

    std::string Nombre;
    unsigned int ID_Canciones;    // 9 dígitos
    unsigned short Duracion;      // en segundos
    std::string Ubicacion_Archivo;
    unsigned int Cant_Reproducciones;

public:

    Cancion();
};
