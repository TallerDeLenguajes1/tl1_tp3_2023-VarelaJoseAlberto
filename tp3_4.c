#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto {
    int ProductoID;        // Numerado en ciclo iterativo
    int Cantidad;          // entre 1 y 10
    char *TipoProducto;    // Algun valor del arreglo TiposProductos
    float PrecioUnitario;  // entre 10 - 100
};

struct Cliente {
    int ClienteID;                // Numerado en el ciclo iterativo
    char *NombreCliente;          // Ingresado por usuario
    int CantidadProductosAPedir;  // “CantidadProductosAPedir” (aleatorio entre 1 y 5)
    struct Producto *Productos;   // El tamaño de este arreglo depende de la variable
};

// iv) Implemente una función que calcule el costo total de un producto. Esta función debe
// recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
// el PrecioUnitario.
float costoTotal(struct Producto producto);

int main() {
    int cantidadClientes;

    // i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de clientes.
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    // Reservo memoria dinamica para los clientes
    struct Cliente *clientes = (struct Cliente *)malloc(cantidadClientes * sizeof(struct Cliente));

    srand(time(NULL));  // Inicialo la semilla para poder generar numeros aleatorios

    // ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
    // Genero datos aleatorios para cada cliente y sus productos
    for (int i = 0; i < cantidadClientes; i++) {
        // Genero nombre aleatorio por consola para el cliente
        char *nombreCliente = (char *)malloc(12 * sizeof(char));
        printf("Ingrese el nombre del cliente con un maximo 12 caracteres %d: ", i + 1);
        scanf("%s", nombreCliente);

        // Genero una cantidad aleatoria de productos para los cliente
        int cantidadProductos = rand() % 5 + 1;

        // Reservo memoria dinamica para los productos de los cliente
        struct Producto *productos = (struct Producto *)malloc(cantidadProductos * sizeof(struct Producto));

        // iii) A medida que se dé de alta cada cliente, Generar aleatoriamente
        // la cantidad de productos asociados al cliente y sus características.

        // Genero los datos aleatorios para cada producto de los cliente
        for (int j = 0; j < cantidadProductos; j++) {
            // Genero la ID del producto
            productos[j].ProductoID = j + 1;
            // Genero la cantidad del producto
            productos[j].Cantidad = rand() % 10 + 1;
            // Genero el tipo de producto
            productos[j].TipoProducto = TiposProductos[rand() % 5];
            // Genero un precio unitario aleatorio entre 10 y 100
            productos[j].PrecioUnitario = (rand() % 91 + 10) / 1.0;
        }

        // Asigno los datos aleatorio generados al cliente que
        // correspondiente(es decir cuando hago el primer recorrido ya le asigno los datos)
        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = nombreCliente;
        clientes[i].CantidadProductosAPedir = cantidadProductos;
        clientes[i].Productos = productos;
    }

    // v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente
    // (sumatoria del costo de todos los productos)

    // Muestro por pantalla todo los datos de los n clientes cargado
    for (int i = 0; i < cantidadClientes; i++) {
        printf("Cliente %d: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);
        float totalAPagar = 0.0;
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            struct Producto producto = clientes[i].Productos[j];
            printf("\tProducto %d:\n", producto.ProductoID);
            printf("\t\tCantidad: %d\n", producto.Cantidad);
            printf("\t\tTipo: %s\n", producto.TipoProducto);
            printf("\t\tPrecio unitario: %.2f\n", producto.PrecioUnitario);
            float costo = costoTotal(producto);
            printf("\t\tCosto: %.2f\n", costo);
            totalAPagar += costo;
        }
        printf("\tTotal a pagar: %.2f\n", totalAPagar);
    }
    return 0;
}
float costoTotal(struct Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}