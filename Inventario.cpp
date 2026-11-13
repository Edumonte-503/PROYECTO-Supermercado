#include <iostream>
#include <string>
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
    {10, "Café", "C08", 4.50}
};


int main()
{

    cout << "=====SUPERMERCADO=====" << endl;
    cout << "Sistema de inventario" << endl;

    return 0;
}