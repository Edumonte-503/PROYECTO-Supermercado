
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
using namespace std;

struct producto
{
    int cantidad;
    string nombre, codigo;
    float precio;
};

const int MAX_PRODUCTOS = 50;

extern int NumProductos;
extern producto inventario[MAX_PRODUCTOS];

void mostrarInventario();
void BuscarProductoCodigo();
void BuscarProductoNombre();
void AgregarProducto();
void EliminarProducto();
void ModificarProducto();
bool ActualizarInventario(string codigo, int cantidad);
void MenuGerente();

#endif
