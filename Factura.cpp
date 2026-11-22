#include <iostream>
#include <string>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
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

int productosCarrito[50];
int cantidadesCarrito[50];
int numCarrito = 0;

float calcularSubtotal()
{
    float subtotal = 0;
    for (int i = 0; i < numCarrito; i++)
    {
        int posicion = productosCarrito[i];
        subtotal = subtotal + (inventario[posicion].precio * cantidadesCarrito[i]);
    }
    return subtotal;
}
// Variables para que imprimirFactura() 
float montoPagado = 0;
float cambioEntregado = 0;
bool pagoExitoso = false;

//Pide el dinero, verifica que alcance y calcula el cambio
void realizarPago(float total)
{
    float dinero;
    pagoExitoso = false;

    cout << "=====PAGO=====" << endl;
    cout << fixed << setprecision(2);
    cout << "Total a pagar: $" << total << endl;

    cout << "Ingrese el dinero del cliente: $";
    cin >> dinero;

    while (true)
    {
        cout << "Ingrese el dinero del cliente: $";
        cin >> dinero;

        if (dinero < total)
        {
            cout << "Dinero insuficiente. Faltan $" << (total - dinero) << endl;
        }
        else
        {
            montoPagado = dinero;
            cambioEntregado = dinero - total; // cambio = dinero entregado - total
            pagoExitoso = true;
            cout << "Pago aceptado. Cambio: $" << cambioEntregado << endl;
            return;
        }
    }
        
}
