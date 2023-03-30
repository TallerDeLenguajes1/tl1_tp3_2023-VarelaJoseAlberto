#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 20

int main() {
    char** arreglo;
    char* nombres;
    int i, j, cant = 0;
    puts("Ingrese la cantidad de nombres");
    scanf("%d", &cant);
    arreglo = (char**)malloc(cant * sizeof(char**));
    nombres = (char*)malloc(20 * sizeof(char*));
    for (i = 0; i < cant; i++) {
        puts("Ingrese un nombre");
        fflush(stdin);
        gets(nombres);
        arreglo[i] = (char*)malloc(strlen(nombres) + 1);
        strcpy(arreglo[i], nombres);
    }
    for (i = 0; i < cant; i++) {
        printf("El nombre es %s \n", arreglo[i]);
    }
    free(arreglo);
    free(nombres);
    return 0;
}