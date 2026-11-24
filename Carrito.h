
#ifndef CARRITO_H
#define CARRITO_H

#include <string>
using namespace std;

int buscarProductoCarrito(string codigo);
bool validarProducto(string codigo);
bool validarCantidad(int posicion, int cantidad);
void agregarCarrito();
float calcularSubtotal();
float calcularIVA(float subtotal);
float calcularTotal(float subtotal, float iva);
void mostrarCarrito();
void finalizarCompra();

#endif
