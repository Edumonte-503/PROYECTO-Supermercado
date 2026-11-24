#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Inventario.h"
#include "Carrito.h"
#include "Factura.h"

using namespace std;

extern string productosCarrito[50];
extern int cantidadesCarrito[50];
extern int numCarrito;

// Variables para controlar el pago
float montoPagado = 0;
float cambioEntregado = 0;
bool pagoExitoso = false;

// Realizar el pago de la compra
void realizarPago(float total)
{
    float dinero;
    pagoExitoso = false;
    montoPagado = 0;
    cambioEntregado = 0;

    cout << "\n===== PAGO =====" << endl;
    cout << fixed << setprecision(2);
    cout << "Total a pagar (IVA incluido): $" << total << endl;

    while (true)
    {
        cout << "Ingrese el dinero del cliente (0 para cancelar): $";
        cin >> dinero;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Error: ingrese un monto numerico valido." << endl;
        }
        else if (dinero == 0)
        {
            cout << "Pago cancelado." << endl;
            return;
        }
        else if (dinero < total)
        {
            cout << "Dinero insuficiente." << endl;
            cout << "Faltan $" << total - dinero << endl;
        }
        else
        {
            montoPagado = dinero;
            cambioEntregado = dinero - total;
            pagoExitoso = true;

            cout << "\nPago aceptado." << endl;
            cout << "Cambio a entregar: $" << cambioEntregado << endl;

            return;
        }
    }
}
// Actualizar el inventario despues de realizar el pago
void actualizarInventario()
{
    if (!pagoExitoso)
    {
        return;
    }

    bool inventarioCorrecto = true;

    for (int i = 0; i < numCarrito; i++)
    {
        bool actualizado = ActualizarInventario(
            productosCarrito[i],
            cantidadesCarrito[i]
        );

        if (!actualizado)
        {
            inventarioCorrecto = false;

            cout << "Error al actualizar el producto: "
                 << productosCarrito[i] << endl;
        }
    }

    if (inventarioCorrecto)
    {
        cout << "Inventario actualizado correctamente." << endl;
    }
}
// Mostrar la factura de la compra
void imprimirFactura()
{
    if (!pagoExitoso)
    {
        return;
    }

    float subtotalGeneral = calcularSubtotal();
    float iva = calcularIVA(subtotalGeneral);
    float total = calcularTotal(subtotalGeneral, iva);

    cout << fixed << setprecision(2);

    cout << "==============================================" << endl;
    cout << "              FACTURA DE VENTA                " << endl;
    cout << "==============================================" << endl;

    cout << left
         << setw(10) << "Codigo"
         << setw(18) << "Producto"
         << setw(6) << "Cant."
         << setw(9) << "Precio"
         << "Subtotal" << endl;

    cout << "----------------------------------------------" << endl;

    for (int i = 0; i < numCarrito; i++)
    {
        int posicion = -1;

        // Buscar el producto en el inventario por su codigo
        for (int j = 0; j < NumProductos; j++)
        {
            if (inventario[j].codigo == productosCarrito[i])
            {
                posicion = j;
                break;
            }
        }

        if (posicion != -1)
        {
            float subtotalProducto =
                inventario[posicion].precio * cantidadesCarrito[i];

            cout << left
                 << setw(10) << inventario[posicion].codigo
                 << setw(18) << inventario[posicion].nombre
                 << setw(6) << cantidadesCarrito[i]
                 << "$" << setw(8) << inventario[posicion].precio
                 << "$" << subtotalProducto << endl;
        }
    }

    cout << "----------------------------------------------" << endl;
    cout << "Subtotal:       $" << subtotalGeneral << endl;
    cout << "IVA (13%):     $" << iva << endl;
    cout << "TOTAL:          $" << total << endl;
    cout << "PAGADO:         $" << montoPagado << endl;
    cout << "CAMBIO:         $" << cambioEntregado << endl;
    cout << "==============================================" << endl;
    cout << "          Gracias por su compra.              " << endl;
    cout << "==============================================" << endl;
}
// Procesar la compra completa
void procesarCompra()
{
    if (numCarrito == 0)
    {
        cout << "El carrito esta vacio." << endl;
        return;
    }

    // Verificar que los productos y cantidades sigan disponibles
    for (int i = 0; i < numCarrito; i++)
    {
        int posicion = -1;

        for (int j = 0; j < NumProductos; j++)
        {
            if (inventario[j].codigo == productosCarrito[i])
            {
                posicion = j;
                break;
            }
        }

        if (posicion == -1)
        {
            cout << "Producto no encontrado: "
                 << productosCarrito[i] << endl;
            cout << "No se puede procesar la compra." << endl;
            return;
        }

        if (cantidadesCarrito[i] <= 0 ||
            inventario[posicion].cantidad < cantidadesCarrito[i])
        {
            cout << "No hay suficiente inventario de "
                 << inventario[posicion].nombre << endl;
            cout << "No se puede procesar la compra." << endl;
            return;
        }
    }

    // Calcular subtotal, IVA y total
    float subtotal = calcularSubtotal();
    float iva = calcularIVA(subtotal);
    float total = calcularTotal(subtotal, iva);

    cout << "===== RESUMEN DE COMPRA =====" << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "IVA (13%): $" << iva << endl;
    cout << "Total a pagar: $" << total << endl;

    // Solicitar el pago
    realizarPago(total);

    // Continuar solamente si el pago fue exitoso
    if (pagoExitoso)
    {
        actualizarInventario();
        imprimirFactura();

        // Vaciar el carrito
        numCarrito = 0;

        cout << "Compra finalizada correctamente." << endl;
    }
    else
    {
        cout << "Compra cancelada." << endl;
    }
}
