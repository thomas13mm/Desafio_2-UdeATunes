#ifndef METRICA_H
#define METRICA_H

class Metrica {
public:
    Metrica();
    ~Metrica();

    void agregarMemoria(long bytes) { memoriaActual += bytes; }
    void liberarMemoria(long bytes) { memoriaActual -= bytes; }

    static void SetIter_EliminarCancion() { Iter_EliminarCancion++; }
    static void SetIter_AgregarCancion() { Iter_AgregarCancion++; }
    static void SetIter_TomarCancionPrevia() { Iter_TomarCancionPrevia++; }
    static void SetIter_MostrarCanciones() { Iter_MostrarCanciones++; }
    static void SetIter_MostrarRutaCancion() { Iter_MostrarRutaCancion++; }
    static void SetIter_MostrarAlbumes() { Iter_MostrarAlbumes++; }

    void MemoriaTotal();
    void IteracionesTotales();

private:
    // Contadores de iteraciones por funcionalidad
    static long Iter_EliminarCancion;
    static long Iter_AgregarCancion;
    static long Iter_TomarCancionPrevia;
    static long Iter_MostrarCanciones;
    static long Iter_MostrarRutaCancion;
    static long Iter_MostrarAlbumes;

    // Contadores de memoria
    static long memoriaActual; // total de memoria
};

#endif

