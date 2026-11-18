#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

struct producto
{
    int cantidad;
    string nombre, codigo;
    float precio;
};

const int MAX_PRODUCTOS = 50;
int NumProductos = 8;

producto inventario[MAX_PRODUCTOS] = {
    {20, "Arroz", "A01", 1.50},
    {15, "Frijoles", "F02", 1.25},
    {25, "Leche", "L03", 1.75},
    {12, "Huevos", "H04", 3.50},
    {30, "Azúcar", "AZ05", 1.20},
    {18, "Aceite", "AC06", 3.25},
    {40, "Pan", "P07", 0.75},
    {10, "Café", "C08", 4.50}};

void mostrarInventario()
{
    cout << setw(18) << "Código" << setw(18) << "Nombre" << setw(18) << "Cantidad" << setw(18) << "Precio" << endl;
    for (int i = 0; i < NumProductos; i++)
    {
        cout << setw(16) << inventario[i].codigo << setw(18 + (inventario[i].nombre == "Azúcar" || inventario[i].nombre == "Café")) << inventario[i].nombre << setw(16) << inventario[i].cantidad << setw(16) << "$" << fixed << setprecision(2) << inventario[i].precio << endl;
    }
}
void BuscarProductoCodigo()
{
    string codigo;
    bool encontrado = false;
    cout << "=====BÚSQUEDA DE PRODUCTO POR CÓDIGO=====" << endl;
    cout << "Ingrese el código del producto: ";
    cin >> codigo;

    for (int i = 0; i < NumProductos; i++)
    {
        if (inventario[i].codigo == codigo)
        {
            cout << "Producto encontrado:" << endl;
            cout << "Código: " << inventario[i].codigo << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            cout << "Precio: $" << fixed << setprecision(2) << inventario[i].precio << endl;
            encontrado = true;
            break;
        }
    }

    if (encontrado==false)
    {
        cout << "Producto no encontrado" << endl;
    }
}
void MenuGerente()
{
    string contrasena;
    int opcion;
    cout << "=====MENÚ DE GERENTE=====" << endl;
    cout << "Ingrese la contraseña de gerente: ";
    cin >> contrasena;

    if (contrasena == "uca123")
    {
        do
        {
            cout << "=====MENÚ DE GERENTE=====" << endl;
            cout << "Agregar producto --> 1" << endl;
            cout << "Eliminar producto --> 2" << endl;
            cout << " Modificar producto --> 3" << endl;
            cout << "Mostrar inventario --> 4" << endl;
            cout << "Salir --> 5" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                mostrarInventario();
                break;
            case 5:
                cout << "Saliendo del menú de gerente" << endl;
                break;
            default:
                cout << "Opción inválida. Intentar nuevamente" << endl;
                break;
            }
        } while (opcion != 5);
    }
    else
    {
        cout << "Contraseña inválida. Acceso denegado" << endl;
    }
}
int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcion;
    do
    {
        cout << "Sistema de inventario" << endl; 
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