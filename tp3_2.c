#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12

int main(int argc, char const *argv[]) {
    int production[FILAS][COLUMNAS];

    srand(time(NULL));
    // Generar valores aleatorios y cargar matriz
    // a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            production[i][j] = rand() % 40001 + 10000;
        }
    }
    // b. Muestre por pantalla los valores cargados
    printf("Valores cargados:\n");
    for (int i = 0; i < FILAS; i++) {
        printf("| anio %d ", i + 1);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("| %d ", production[i][j]);
        }
        printf("|\n");
    }

    // c. Saque el promedio de ganancia por año y muestrelos por pantalla
    int promedio[FILAS];
    for (int i = 0; i < FILAS; i++) {
        int sum = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            sum += production[i][j];
        }
        promedio[i] = sum / COLUMNAS;
    }

    // Mostrar promedio de ganancia por año
    printf("\nPromedio de ganancia por anio:\n");
    for (int i = 0; i < FILAS; i++) {
        printf("Anio %d: %d\n", i + 1, promedio[i]);
    }

    // d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    int max = production[0][0], min = production[0][0], max_anio = 0, max_mes = 0, min_anio = 0, min_mes = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (production[i][j] > max) {
                max = production[i][j];
                max_anio = i;
                max_mes = j;
            }
            if (production[i][j] < min) {
                min = production[i][j];
                min_anio = i;
                min_mes = j;
            }
        }
    }

    // Mostrar valor maximo y minimo con su posición
    printf("\nValor maximo: %d (Anio %d, Mes %d)\n", max, max_anio + 1, max_mes + 1);
    printf("Valor minimo: %d (Anio %d, Mes %d)\n", min, min_anio + 1, min_mes + 1);

    return 0;
}
