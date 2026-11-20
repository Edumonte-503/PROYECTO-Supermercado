#ifndef Inventario_h
#define Inventario_h

#include <string>
using namespace std;

struct producto // Estructura para almacenar los datos de cada producto
{
    int cantidad;
    string nombre, codigo;
    float precio;
};
const int MAX_PRODUCTOS = 50; 

extern int NumProductos; // Número máximo de productos en el inventario, const sinifica que no se puede cambiar el valor de la variable
extern producto inventario[MAX_PRODUCTOS]; // Inventario inicial con 8 productos

void mostrarInventario(); // Función para mostrar el inventario completo
void BuscarProductoCodigo(); // Función para buscar un producto por código
void BuscarProductoNombre(); // Función para buscar un producto por nombre
bool ActualizarInventario(string codigo, int cantidad); // Función para actualizar el inventario después de una venta
void MenuGerente(); // Función para mostrar el menú de gerente
void AgregarProducto(); // Función para agregar un producto al inventario
void EliminarProducto(); // Función para eliminar un producto del inventario
void ModificarProducto(); // Función para modificar un producto del inventario
#endif
