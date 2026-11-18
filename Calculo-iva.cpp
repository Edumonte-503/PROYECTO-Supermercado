
#include <iostream>
#include <string>
using namespace std;


int productosCarrito[50];
int cantidadesCarrito[50];

int numCarrito = 0;

int buscarProductoCarrito(string codigo)
{
    for (int i = 0; i < NumProductos; i++)
    {
        if (inventario[i].codigo == codigo)
        {
            return i;
        }
    }

    return -1;
}
