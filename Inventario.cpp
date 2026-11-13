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

producto inventario[8] = {
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
    cout << setw(15) << "Código" << setw(15) << "Nombre" << setw(15) << "Cantidad" << setw(15) << "Precio" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << setw(15) << inventario[i].codigo << setw(15) << inventario[i].nombre << setw(15) << inventario[i].cantidad << setw(15) << "$" << fixed << setprecision(2) << inventario[i].precio << endl;
    }
}

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=====SUPERMERCADO=====" << endl;
    cout << "Sistema de inventario" << endl;

    mostrarInventario();

    return 0;
}