

#include <iostream>
#include <string>
#include "Inventario.h"

using namespace std;


string productosCarrito[50];
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
        cout << "El producto no existe." << endl;
        return false;
    }
    else
    {
        cout << "Producto encontrado: "
             << inventario[posicion].nombre << endl;
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

    int cantidadEnCarrito = 0;

    for (int i = 0; i < numCarrito; i++)
    {
        if (productosCarrito[i] == inventario[posicion].codigo)
        {
            cantidadEnCarrito = cantidadesCarrito[i];
        }
    }

    if (cantidad + cantidadEnCarrito > inventario[posicion].cantidad)
    {
        cout << "No hay suficiente inventario." << endl;
        cout << "Unidades disponibles para agregar: "
             << inventario[posicion].cantidad - cantidadEnCarrito
             << endl;
        return false;
    }

    return true;
}


void agregarCarrito()
{
    string codigo;
    int cantidad;

    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;

    int posicion = buscarProductoCarrito(codigo);

    if (posicion == -1)
    {
        cout << "El producto no existe." << endl;
        return;
    }

    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    if (validarCantidad(posicion, cantidad))
    {
        int indice = -1;

        for (int i = 0; i < numCarrito; i++)
        {
            if (productosCarrito[i] == codigo)
            {
                indice = i;
                break;
            }
        }

        if (indice != -1)
        {
            cantidadesCarrito[indice] += cantidad;
            cout << "Cantidad actualizada." << endl;
        }
        else if (numCarrito < 50)
        {
            productosCarrito[numCarrito] = codigo;
            cantidadesCarrito[numCarrito] = cantidad;
            numCarrito++;

            cout << "Producto agregado al carrito." << endl;
        }
        else
        {
            cout << "El carrito esta lleno." << endl;
        }
    }
}


float calcularSubtotal()
{
    float subtotal = 0;

    for (int i = 0; i < numCarrito; i++)
    {
        int posicion = buscarProductoCarrito(productosCarrito[i]);

        if (posicion != -1)
        {
            subtotal += inventario[posicion].precio *
                        cantidadesCarrito[i];
        }
    }

    return subtotal;
}

float calcularIVA(float subtotal)
{
    float iva;

    iva = subtotal * 0.13;

    return iva;
}

float calcularTotal(float subtotal, float iva)
{
    float total;

    total = subtotal + iva;

    return total;
}

