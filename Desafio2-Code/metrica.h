#ifndef METRICA_H
#define METRICA_H

class Metrica {

    /* Descripcion:
     * Clase encargada de la medicion de recursos utilizados durante el tiempo de ejecucion del programa
     * basandose en el numero de iteraciones por funcionalidad requerida, y la memoria ocupada a lo largo
     * del tiempo de ejecucion por cada una de los tipos de datos altamente estructurados creados por nosotros.
     *
     * Utiliza un costructor por defecto pues solo esta pensada para utilizar un unico objeto de la clase
     * Metrica para la medicion del programa completo.
     */

public:
    Metrica();
    ~Metrica();

    // Manejo de memoria
    void agregarMemoria(long bytes) { memoriaActual += bytes; }
    void liberarMemoria(long bytes) { memoriaActual -= bytes; }

    // Incremento de iteraciones
    static void SetIter_EliminarCancion() { Iter_EliminarCancion++; }
    static void SetIter_AgregarCancion() { Iter_AgregarCancion++; }
    static void SetIter_IngresoPlataforma() { Iter_IngresoPlataforma++; }

    // Mostrar totales
    void MemoriaTotal();
    void IteracionesTotales();

    // --- Getters individuales ---
    long GetIter_EliminarCancion() const { return Iter_EliminarCancion; }
    long GetIter_AgregarCancion() const { return Iter_AgregarCancion; }
    long GetIter_IngresoPlataforma() const { return Iter_IngresoPlataforma; }
    long GetMemoriaActual() const { return memoriaActual; }
    void ReiniciarMetricas();


private:
    // Contadores de iteraciones por funcionalidad
    static long Iter_EliminarCancion;
    static long Iter_AgregarCancion;
    static long Iter_IngresoPlataforma;

    // Contador de memoria total
    static long memoriaActual;
};

#endif




