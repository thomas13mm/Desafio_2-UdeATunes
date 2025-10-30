#include <iostream>
#include <ReadWrite.h>
#include <metrica.h>
#include <artista.h>
#include <album.h>
#include <cancion.h>
#include <usuario.h>
#include <listarp.h>
#include <anuncio.h>
#include <utilidades.h>

using namespace std;

int main() {
    Metrica x;
    x.ReiniciarMetricas();

    const char* name  = "dataset_AAC.txt";
    const char* name2 = "dataset_ULR.txt";
    const char* name3 = "dataset_An.txt";
    string ubicacion = "/users/storage/";

    unsigned int CArtistas  = 0;
    unsigned int CAlbumes   = 0;
    unsigned int CCanciones = 0;
    unsigned int CUsuarios  = 0;

    Artista* Artistas   = nullptr;
    Album* Albumes      = nullptr;
    Cancion* Canciones  = nullptr;
    Usuario* Usuarios   = nullptr;
    Usuario* ActualUser = nullptr;
    Anuncio* Anuncios   = nullptr;

    Anuncios = new Anuncio[50];

    readArchivo(name, Artistas, Albumes, Canciones, CArtistas, CAlbumes, CCanciones, x);
    readArchivo(name2, Usuarios, CUsuarios, Canciones, CCanciones, x);
    read_Anuncio(name3, Anuncios, x);

    string nickname, password;
    do {
        cout << "Ingrese su nombre de usuario: ";
        cin >> nickname;
        cout << "Ingrese su contrasena: ";
        cin >> password;
    } while (!(verificar_Existencia(nickname, Usuarios, CUsuarios, x, ActualUser)));

    unsigned short int control;
    unsigned short int control2;

    do {
        cout << '\n' << "=================================" << '\n'
             << "Selecciones una opcion: " << '\n'
             << "1. Editar mi lista de favoritos" << '\n'
             << "2. Relacionar usuarios" << '\n'
             << "3. Ejecutar mi lista de favoritos" << '\n'
             << "4. Visualizar Consumo" << '\n'
             << "===> ";
        cin >> control;

        switch (control) {
        case 1: {
            cout << '\n' << "=================================" << '\n'
                 << "Ingrese una opcion: " << '\n'
                 << "1. Agregar canciones a su lista de favoritas" << '\n'
                 << "2. Eliminar canciones de su lista de favoritas" << '\n';
            cin >> control2;

            if (!(ActualUser->get_membresia())) {
                cout << "Actualmente usted no es premium " << '\n';
                break;
            }

            string codeCancionAUX;
            switch (control2) {
            case 1: {
                printArreglo(Canciones, CCanciones);
                cout << '\n' << "Ingrese el codigo de la cancion que desea agregar a su lista de favoritos: ";
                cin >> codeCancionAUX;

                if (ActualUser->get_MiListaRP()->BuscarCancionPorCodigo(codeCancionAUX) != nullptr) {
                    cout << "Esta cancion ya hace parte de sus favoritos" << '\n';
                    break;
                }

                if (ActualUser->get_MiListaRP()->AgregarCancion(
                        BuscarCancionPorID(Canciones, CCanciones, codeCancionAUX, x), x)) {
                    cout << "Se agrego con exito a sus favoritos" << '\n';
                    ActualUser->get_MiListaRP()->MostrarLista();
                } else {
                    cout << "Su lista ya tiene 10.000 canciones";
                }
                break;
            }
            case 2: {
                cout << "Su lista de favoritos es: " << '\n';
                ActualUser->get_MiListaRP()->MostrarLista();

                cout << "Ingrese el codigo de la cancion que desea eliminar de su lista de favoritos: ";
                cin >> codeCancionAUX;

                if (ActualUser->get_MiListaRP()->BuscarCancionPorCodigo(codeCancionAUX) == nullptr) {
                    cout << "La cancion con codigo " << codeCancionAUX
                         << " no se encuentra en su lista de favoritas" << '\n';
                    break;
                }

                ActualUser->get_MiListaRP()->EliminarCancion(
                    ActualUser->get_MiListaRP()->BuscarCancionPorCodigo(codeCancionAUX), x);
                cout << "Eliminada con exito" << '\n';
                ActualUser->get_MiListaRP()->MostrarLista();
                break;
            }
            default:
                cout << "Opcion no disponible" << '\n';
                break;
            }
            break;
        }

        case 2: {
            control = 0;
            string usuario_A_seguir;

            cout << '\n' << "=================================" << '\n'
                 << "Selecciones una opcion: " << '\n'
                 << "1. Seguir un usuario" << '\n'
                 << "2. Dejar de seguir usuario" << '\n'
                 << "===> ";
            cin >> control;

            switch (control) {
            case 1: {
                cout << "Ingrese el nickname del usuario que desea seguir: ";
                cin >> usuario_A_seguir;

                if (ActualUser->seguirUsuario(ActualUser->BuscarUser(Usuarios, CUsuarios, usuario_A_seguir))) {
                    cout << "=================================" << '\n'
                         << "Ahora sigues a " << usuario_A_seguir << " y a todas sus canciones favoritas" << '\n'
                         << "Tu nueva lista de reproduccion es: " << '\n';
                    ActualUser->get_MiListaRP()->MostrarLista();
                } else {
                    cout << "El usuario " << usuario_A_seguir << " no es premium" << '\n';
                }
                break;
            }
            case 2: {
                if (ActualUser->get_siguiendoA() == nullptr) {
                    cout << "Usted actualmente no sigue a ningun usuario" << '\n';
                    break;
                }

                char b;
                cout << "=================================" << '\n'
                     << "Actualmente usted sigue a: " << ActualUser->get_siguiendoA()->get_nickName() << '\n'
                     << "Quiere dejar de seguirl@? (y/n)" << '\n'
                     << "===> ";
                cin >> b;

                if (b == 'n') break;

                if (ActualUser->dejarSeguirUsuario(ActualUser->get_siguiendoA(), x)) {
                    cout << "Lo has dejado de seguir" << '\n';
                    ActualUser->get_MiListaRP()->MostrarLista();
                }
                break;
            }
            default:
                cout << "Opcion no valida" << '\n';
                break;
            }
            break;
        }

        case 3: {
            cout << '\n' << "=================================" << '\n'
                 << "Ingrese una opcion: " << '\n'
                 << "1. Reproducir en orden" << '\n'
                 << "2. Reproducir de forma aleatoria" << '\n'
                 << "===> ";
            control = 0;
            cin >> control;

            switch (control) {
            case 1:
                ActualUser->ReproducirAutomaticamente(ubicacion, Artistas, Albumes, CAlbumes, CArtistas, Anuncios);
                break;
            case 2:
                ActualUser->ReproducirListaRandom(ubicacion, Artistas, Albumes, CAlbumes, CArtistas, Anuncios);
                break;
            default:
                break;
            }
            break;
        }

        case 4: {
            x.IteracionesTotales();
            x.GetMemoriaActual();
            x.MemoriaTotal();
            break;
        }
        default:
            break;
        }
    } while (true);

    delete[] Usuarios;
    delete[] Canciones;
    delete[] Albumes;
    delete[] Artistas;
    delete[] Anuncios;

    return 0;
}


