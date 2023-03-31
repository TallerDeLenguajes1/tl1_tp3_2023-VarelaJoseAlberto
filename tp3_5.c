
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_NOMBRES 5
#define MAX_LONGITUD_NOMBRE 12

int main(int argc, char const *argv[]) {
    int max_nombre;  // Cantidad de nombres a ingresar
    printf("Ingrese la cantidad de nombres a ingresar: ");
    scanf("%d", &max_nombre);

    // Definir vector de punteros a char para los nombres
    char *nombres[max_nombre];

    // Pedir al usuario que ingrese los nombres y cargarlos en el vector
    char buff[MAX_LONGITUD_NOMBRE];

    for (int i = 0; i < max_nombre; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        fflush(stdin);  // vacio el buff ya que con tiene el enter cuando ingrese la cantidad de nombres
        gets(buff);

        nombres[i] = malloc((strlen(buff) + 1) * sizeof(char));  // Reservar memoria para el nombre y copiarlo en el vector
        strcpy(nombres[i], buff);
    }

    // Listar los nombres por pantalla
    printf("\nNombres ingresados:\n");
    for (int i = 0; i < max_nombre; i++) {
        printf("%d. ", i + 1);
        puts(nombres[i]);
        printf("\n");
    }

    // Liberar la memoria reservada para cada nombre
    for (int i = 0; i < max_nombre; i++) {
        free(nombres[i]);
    }

    return 0;
}