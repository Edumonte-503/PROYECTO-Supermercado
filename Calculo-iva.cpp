
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

bool validarProducto(string codigo)
{
    int posicion = buscarProductoCarrito(codigo);

    if (posicion == -1)
    {
        cout << "El producto no existe en el inventario." << endl;
        return false;
    }
    else
    {
        cout << "Producto encontrado: " << inventario[posicion].nombre << endl;
        return true;
    }
}
