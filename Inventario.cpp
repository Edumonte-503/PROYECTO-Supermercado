#include <iostream>
#include <string>
#include <iomanip> //Sirve para dar formato a la salida de datos, como el número de decimales que se muestran en los precios
#include <windows.h>
#include "Inventario.h"

using namespace std;


int NumProductos = 8;

producto inventario[MAX_PRODUCTOS] = {// Inventario inicial con 8 productos
                                      {20, "Arroz", "A01", 1.50},
                                      {15, "Frijoles", "F02", 1.25},
                                      {25, "Leche", "L03", 1.75},
                                      {12, "Huevos", "H04", 3.50},
                                      {30, "Azúcar", "AZ05", 1.20},
                                      {18, "Aceite", "AC06", 3.25},
                                      {40, "Pan", "P07", 0.75},
                                      {10, "Café", "C08", 4.50}};

void mostrarInventario()
{ // Función para mostrar el inventario completo     //setw() se utiliza para alinear los datos en columnas
    cout << setw(18) << "Código" << setw(18) << "Nombre" << setw(18) << "Cantidad" << setw(18) << "Precio" << endl;
    for (int i = 0; i < NumProductos; i++)
    {
        cout << setw(16) << inventario[i].codigo << setw(18 + (inventario[i].nombre == "Azúcar" || inventario[i].nombre == "Café")) << inventario[i].nombre << setw(16) << inventario[i].cantidad << setw(16) << "$" << fixed << setprecision(2) << inventario[i].precio << endl;
    }
}
void BuscarProductoCodigo()
{
    string codigo;
    bool encontrado = false; // Sirve para indicar si se encontró el producto o no, se inicializa en false porque aún no se ha buscado el producto
    cout << "=====BÚSQUEDA DE PRODUCTO POR CÓDIGO=====" << endl;
    cout << "Ingrese el código del producto: ";
    cin >> codigo;

    for (int i = 0; i < NumProductos; i++) // se recorre el inventario para buscar el producto por código
    {
        if (inventario[i].codigo == codigo) // si el código ingresado coincide con el código del producto en el inventario
        {
            cout << "Producto encontrado:" << endl;
            cout << "Código: " << inventario[i].codigo << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            cout << "Precio: $" << fixed << setprecision(2) << inventario[i].precio << endl; // fixed y setprecision(2) se utilizan para mostrar el precio con 2 decimales
            encontrado = true;
            break;
        }
    }

    if (encontrado == false) // si no se encuentra el producto, se muestra un mensaje indicando que no se encontró
    {
        cout << "Producto no encontrado" << endl;
    }
}
void BuscarProductoNombre()
{
    string nombre;
    bool encontrado = false; // Sirve para indicar si se encontró el producto o no, se inicializa en false porque aún no se ha buscado el producto
    cout << "=====BÚSQUEDA DE PRODUCTO POR NOMBRE=====" << endl;
    cout << "Ingrese el nombre: ";
    cin >> nombre;

    for (int i = 0; i < NumProductos; i++) // se recorre el inventario para buscar el producto por nombre
    {
        if (inventario[i].nombre == nombre) // si el nombre ingresado coincide con el nombre del producto en el inventario
        {
            cout << "Producto encontrado:" << endl;
            cout << "Código: " << inventario[i].codigo << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            cout << "Precio: $" << fixed << setprecision(2) << inventario[i].precio << endl; // fixed y setprecision(2) se utilizan para mostrar el precio con 2 decimales
            encontrado = true;
            break;
        }
    }

    if (encontrado == false) // si no se encuentra el producto, se muestra un mensaje indicando que no se encontró
    {
        cout << "Producto no encontrado" << endl;
    }
}

void AgregarProducto() // Función para agregar un producto al inventario
{
    if (NumProductos >= MAX_PRODUCTOS) // Si el número de productos en el inventario es mayor o igual al número máximo de productos, se muestra un mensaje indicando que no se puede agregar más productos
    {
        cout << "No se puede agregar más productos. Inventario lleno." << endl;
        return;
    }
    producto NuevoProducto;
    cout << "=====AGREGAR PRODUCTO=====" << endl;
    cout << "Ingrese el código del producto: ";
    cin >> NuevoProducto.codigo;
    for (int i = 0; i < NumProductos; i++) // Se recorre el inventario para verificar si el código ingresado ya existe
    {
        if (inventario[i].codigo == NuevoProducto.codigo) // Si el código ingresado coincide con el código de algún producto en el inventario, se muestra un mensaje indicando que el código ya existe y se retorna de la función
        {
            cout << "El código ingresado ya existe. No se puede agregar el producto." << endl;
            return;
        }
    }
    cout << "Ingrese el nombre del producto: ";
    cin >> NuevoProducto.nombre;
    cout << "Ingrese la cantidad del producto: ";
    cin >> NuevoProducto.cantidad;
    cout << "Ingrese el precio del producto: ";
    cin >> NuevoProducto.precio;
    if (NuevoProducto.precio < 0) // Si el precio ingresado es menor a 0, se muestra un mensaje indicando que el precio no puede ser negativo y se retorna de la función
    {
        cout << "El precio no puede ser negativo. No se puede agregar el producto" << endl;
        return;
    }

    inventario[NumProductos] = NuevoProducto;
    NumProductos++;
    cout << "Producto agregado" << endl;
}
void EliminarProducto() // Función para eliminar un producto del inventario
{
    string codigo;
    bool encontrado = false;
    cout << "=====ELIMINAR PRODUCTO=====" << endl;
    cout << "Ingrese el código del producto: ";
    cin >> codigo;

    for (int i = 0; i < NumProductos; i++)
    {
        if (inventario[i].codigo == codigo)
        {
            for (int j = i; j < NumProductos - 1; j++) // Se recorre el inventario desde la posición del producto a eliminar hasta el final del inventario
            {
                inventario[j] = inventario[j + 1]; // Se desplaza cada producto una posición hacia atrás, sobrescribiendo el producto a eliminar
            }
            NumProductos--; // Se decrementa el número de productos en el inventario
            cout << "Producto eliminado" << endl;
            encontrado = true;
            break;
        }
    }

    if (encontrado == false)
    {
        cout << "Producto no encontrado" << endl;
    }
}
void ModificarProducto() // Función para modificar un producto del inventario
{
    string codigo;
    bool encontrado = false;
    cout << "=====MODIFICAR PRODUCTO=====" << endl;
    cout << "Ingrese el código del producto: ";
    cin >> codigo;
    int opcion;
    for (int i = 0; i < NumProductos; i++) // Se recorre el inventario para buscar el producto por código
    {
        if (inventario[i].codigo == codigo) // Si el código ingresado coincide con el código del producto en el inventario
        {
            cout << "Producto encontrado:" << inventario[i].nombre << endl;
            cout << "Modificar nombre --> 1" << endl;
            cout << "Modificar cantidad --> 2" << endl;
            cout << "Modificar precio --> 3" << endl;
            cout << "Cancelar modificación --> 4" << endl;

            cin >> opcion;

            switch (opcion) // Se utiliza un switch para modificar el producto según la opción ingresada
            {
            case 1:
                cout << "Ingrese el nuevo nombre del producto: ";
                cin >> inventario[i].nombre;
                break;
            case 2:
                cout << "Ingrese la nueva cantidad del producto: ";
                if (inventario[i].cantidad < 0) 
                {
                    cout << "La cantidad no puede ser negativa. No se puede modificar el producto" << endl;
                    return;
                }
                cin >> inventario[i].cantidad;
                break;
            case 3:
            float nuevoPrecio;  
                cout << "Ingrese el nuevo precio del producto: ";
                cin >> nuevoPrecio;
                inventario[i].precio = nuevoPrecio;
                break;
            case 4:
                cout << "Modificación cancelada" << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
            }
        }
    }

    if (encontrado == false) // Si no se encuentra el producto, se muestra un mensaje indicando que no se encontró
    {
        cout << "Producto no encontrado" << endl;
    }
}
bool ActualizarInventario(string codigo, int cantidad) // Función para actualizar el inventario después de una venta
{
    for (int i = 0; i < NumProductos; i++) 
    {
        if (inventario[i].codigo == codigo) 
        {
            if (cantidad > 0 && inventario[i].cantidad >= cantidad) // Se verifica que la cantidad a vender sea mayor a 0 y que haya suficiente inventario
            {
                inventario[i].cantidad -= cantidad; // Se actualiza la cantidad del producto en el inventario
                return true;
            } 
            return false; 
        }
    }
    return false;
}
void MenuGerente() // Función para mostrar el menú de gerente
{
    string contrasena;
    int opcion;
    cout << "=====MENÚ DE GERENTE=====" << endl;
    cout << "Ingrese la contraseña de gerente: ";
    cin >> contrasena;

    if (contrasena == "uca123")
    {
        do
        {
            cout << "=====MENÚ DE GERENTE=====" << endl;
            cout << "Agregar producto --> 1" << endl;
            cout << "Eliminar producto --> 2" << endl;
            cout << "Modificar producto --> 3" << endl;
            cout << "Mostrar inventario --> 4" << endl;
            cout << "Salir --> 5" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                AgregarProducto();
                break;
            case 2:
                EliminarProducto();
                break;
            case 3:
                ModificarProducto();
                break;
            case 4:
                mostrarInventario();
                break;
            case 5:
                cout << "Saliendo del menú de gerente" << endl;
                break;
            default:
                cout << "Opción inválida. Intentar nuevamente" << endl;
                break;
            }
        } while (opcion != 5);
    }
    else
    {
        cout << "Contraseña inválida. Acceso denegado" << endl;
    }
}
int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // Configuración de la consola para mostrar caracteres UTF-8, como tilde y ñ

    int opcion;
    do
    {
        cout << "===Sistema de inventario===" << endl; // Menu principal del sistema de inventario
        cout << "Mostrar inventario--> 1" << endl;
        cout << "Buscar producto nombre--> 2" << endl;
        cout << "Buscar producto codigo--> 3" << endl;
        cout << "Menú de gerente--> 4" << endl;
        cout << "Salir--> 5" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            mostrarInventario();
            break;
        case 2:
            BuscarProductoNombre();
            break;
        case 3:
            BuscarProductoCodigo();
            break;
        case 4:
            MenuGerente();
            break;
        case 5:
            cout << "Saliendo del sistema de inventario" << endl;
            break;
        default:
            cout << "Opción inválida. Intentar otra vez" << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}