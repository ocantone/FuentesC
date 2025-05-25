#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char columna;
    int fila;
    char dato[256];

    // Pedir columna y fila
    printf("Ingrese la columna (letra, por ejemplo B): ");
    scanf(" %c", &columna);
    printf("Ingrese la fila (número, por ejemplo 2): ");
    scanf("%d", &fila);
    getchar(); // Limpiar salto de línea pendiente

    // Pedir el dato
    printf("Ingrese el dato: ");
    fgets(dato, sizeof(dato), stdin);
    dato[strcspn(dato, "\n")] = 0;

    // Convertir columna de letra ('A', 'B', etc.) a índice (0, 1, etc.)
    int col_idx = toupper(columna) - 'A';
    int fila_idx = fila - 1;

    // Abrir archivo para escribir
    FILE *archivo = fopen("cexcel.csv", "w");
    if (!archivo) {
        perror("No se pudo crear el archivo");
        return 1;
    }

    // Escribir filas y columnas hasta la celda requerida
    for (int i = 0; i <= fila_idx; i++) {
        for (int j = 0; j <= col_idx; j++) {
            if (j > 0)
                fprintf(archivo, ",");
            if (i == fila_idx && j == col_idx)
                fprintf(archivo, "%s", dato);
            // Si no es la celda objetivo, deja vacío (no imprime nada)
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);

    printf("Dato guardado en cexcel.csv, celda %c%d.\n", toupper(columna), fila);

    return 0;
}