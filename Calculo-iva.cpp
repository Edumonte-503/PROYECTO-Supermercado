

#include <iostream>
#include <string>
#include <iomanip>
#include "Inventario.h"
#include "Carrito.h"

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

void mostrarCarrito()
{
    if (numCarrito == 0)
    {
        cout << "El carrito esta vacio." << endl;
        return;
    }

    cout << "\n===== CARRITO DE COMPRAS =====" << endl;

    for (int i = 0; i < numCarrito; i++)
    {
        int posicion = buscarProductoCarrito(productosCarrito[i]);

        if (posicion != -1)
        {
            cout << "\nProducto: " << inventario[posicion].nombre << endl;
            cout << "Codigo: " << inventario[posicion].codigo << endl;
            cout << "Cantidad: " << cantidadesCarrito[i] << endl;
            cout << "Precio unitario: $"
                 << inventario[posicion].precio << endl;

            cout << "Total del producto: $"
                 << inventario[posicion].precio * cantidadesCarrito[i]
                 << endl;
        }
        else
        {
            cout << "\nProducto no disponible: "
                 << productosCarrito[i] << endl;
        }
    }

    float subtotal = calcularSubtotal();
    float iva = calcularIVA(subtotal);
    float total = calcularTotal(subtotal, iva);

    cout << "\n============================" << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "IVA (13%): $" << iva << endl;
    cout << "TOTAL A PAGAR: $" << total << endl;
    cout << "============================" << endl;
}

void finalizarCompra()
{
    if (numCarrito == 0)
    {
        cout << "El carrito esta vacio." << endl;
        return;
    }

   
    for (int i = 0; i < numCarrito; i++)
    {
        int posicion = buscarProductoCarrito(productosCarrito[i]);

        if (posicion == -1)
        {
            cout << "El producto " << productosCarrito[i]
                 << " ya no existe en el inventario." << endl;
            cout << "No se puede finalizar la compra." << endl;
            return;
        }

        if (inventario[posicion].cantidad < cantidadesCarrito[i])
        {
            cout << "No hay suficiente inventario de "
                 << inventario[posicion].nombre << endl;
            cout << "No se puede finalizar la compra." << endl;
            return;
        }
    }

   
    mostrarCarrito();

    char confirmar;

    cout << "\nDesea confirmar la compra? (S/N): ";
    cin >> confirmar;

    if (confirmar == 'S' || confirmar == 's')
    {
       
        for (int i = 0; i < numCarrito; i++)
        {
            ActualizarInventario(productosCarrito[i],
                                cantidadesCarrito[i]);
        }

        cout << "\nCompra realizada exitosamente." << endl;
        cout << "Gracias por su compra." << endl;

       
        numCarrito = 0;
    }
    else
    {
        cout << "Compra no confirmada." << endl;
    }
}

