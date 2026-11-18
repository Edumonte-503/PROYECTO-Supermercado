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
void MenuGerente(){
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
            cout << "1. Agregar producto" << endl;
            cout << "2. Eliminar producto" << endl;
            cout << "3. Modificar producto" << endl;
            cout << "4. Mostrar inventario" << endl;
            cout << "5. Salir" << endl;
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

    cout << "=====SUPERMERCADO=====" << endl;
    cout << "==Sistema de inventario==" << endl;

    mostrarInventario();

    return 0;
}