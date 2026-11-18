
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
            if (productosCarrito[i] == posicion)
            {
                indice = i;
            }
        }

        if (indice != -1)
        {
            if (validarCantidad(posicion,
                cantidadesCarrito[indice] + cantidad))
            {
                cantidadesCarrito[indice] += cantidad;
                cout << "Cantidad actualizada." << endl;
            }
        }
        else if (numCarrito < 50)
        {
            productosCarrito[numCarrito] = posicion;
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
        int posicion = productosCarrito[i];

        subtotal = subtotal +
                   (inventario[posicion].precio *
                   cantidadesCarrito[i]);
    }

    return subtotal;
}
