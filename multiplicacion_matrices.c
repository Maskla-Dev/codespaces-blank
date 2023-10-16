#include <stdio.h>

void main(){
    int matrizA[3][3] = {
        {4, -2, 4},
        {2, 12, 18},
        {4, 5, 9},
    };


    int matrizB[3][3] = {
        {8, 1, 3},
        {2, 1, 0},
        {4, 6, 3}
    };

    int matrizC[3][3];

    int fila = 0, columna = 0, k = 0, suma = 0, P = 3;
    for(fila = 0; fila < 3; ++fila){
        for(columna = 0; columna < 3; ++columna){
            for(k = 0; k < P; ++k){
                suma = suma + matrizA[fila][k] * matrizB[k][columna];
            }
            matrizC[fila][columna] = suma;
            suma = 0;
        }
    }

    for(fila = 0; fila < 3; ++fila){
        for(columna = 0; columna < 3; ++columna){
            printf("%d ", matrizC[fila][columna]);
        }
        printf("\n");
    }
}