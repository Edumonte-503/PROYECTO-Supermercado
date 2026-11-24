#include <iostream>
#include <windows.h>
#include "inventario.h"
#include "Carrito.h"
#include "Factura.h"

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
        cout << "Agregar producto al carrito--> 4" << endl;
        cout << "Mostrar carrito--> 5" << endl;
        cout << "Procesar compra--> 6" << endl;
        cout << "Menú de gerente--> 7" << endl;
        cout << "Salir--> 8" << endl;
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
    agregarCarrito();
    break;

case 5:
    mostrarCarrito();
    break;

case 6:
    procesarCompra();
    break;

case 7:
    MenuGerente();
    break;

case 8:
    cout << "Saliendo del supermercado" << endl;
    break;

default:
    cout << "Opcion invalida. Intentar otra vez" << endl;
    break;
}
    } while (opcion != 8);

    return 0;
}