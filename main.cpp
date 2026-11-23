#include <iostream>
#include <windows.h>
#include "inventario.h"

using namespace std;

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // Configuración de la consola para mostrar caracteres UTF-8, como tilde y ñ

    int opcion;
    do
    {
        cout << "===Sistema de inventario===" << endl; // Menu principal del sistema de inventario
        cout << "Mostrar inventario--> 1" << endl;
        cout << "Buscar producto nombre--> 2" << endl;
        cout << "Buscar producto codigo--> 3" << endl;
        cout << "Menú de gerente--> 4" << endl;
        cout << "Salir--> 5" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            mostrarInventario();
            break;
        case 2:
            BuscarProductoNombre();
            break;
        case 3:
            BuscarProductoCodigo();
            break;
        case 4:
            MenuGerente();
            break;
        case 5:
            cout << "Saliendo del sistema de inventario" << endl;
            break;
        default:
            cout << "Opción inválida. Intentar otra vez" << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}