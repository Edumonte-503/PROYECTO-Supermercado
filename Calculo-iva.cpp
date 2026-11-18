
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

bool validarCantidad(int posicion, int cantidad)
{
    if (cantidad <= 0)
    {
        cout << "La cantidad debe ser mayor que cero." << endl;
        return false;
    }
    else if (cantidad > inventario[posicion].cantidad)
    {
        cout << "No hay suficiente inventario." << endl;
        cout << "Unidades disponibles: "
             << inventario[posicion].cantidad << endl;
        return false;
    }
    else
    {
        cout << "Cantidad disponible." << endl;
        return true;
    }
}
