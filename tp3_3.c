
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 5
#define MAX_LONGITUD_NOMBRE 50

int main(int argc, char const *argv[]) {
    char *nombres[MAX_NOMBRES];

    // Pedir al usuario que ingrese los nombres y cargarlos en el vector
    char buff[MAX_LONGITUD_NOMBRE];
    for (int i = 0; i < MAX_NOMBRES; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(buff);

        // Reservar memoria para el nombre y copiarlo en el vector
        nombres[i] = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombres[i], buff);
    }

    // Listar los nombres por pantalla
    printf("\nNombres ingresados:\n");
    for (int i = 0; i < MAX_NOMBRES; i++) {
        printf("%d. ", i + 1);
        puts(nombres[i]);
        printf("\n");
    }

    // Liberar la memoria reservada para cada nombre
    for (int i = 0; i < MAX_NOMBRES; i++) {
        free(nombres[i]);
    }

    return 0;
}
