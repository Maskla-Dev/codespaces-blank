#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Grafo como nodos*/
typedef struct NODO_LISTA{
    struct NODO_GRAFO *valor;
    struct NODO_LISTA *siguiente;
}NODO_LISTA;

typedef struct LISTA{
    struct NODO_LISTA *inicio_lista;
}LISTA;

typedef struct NODO_GRAFO{
    int valor;
    LISTA *lista_referencias;
}NODO_GRAFO;

/*
Grafo como matriz
*/

void caminoA(bool **tabla, int comienzo, int objetivo);
void insertarReferencia(bool **tabla, int objetivo, int nodo);
void eliminarReferencia(bool **tabla, int objetivo, int nodo);

void main(){
    //Representacion en tabla
    bool **tabla_grafo = malloc(sizeof(bool*)*7);
    for(size_t i = 0; i < 7; ++i){
        tabla_grafo[i] = malloc(sizeof(bool)*7);
    }
    insertarReferencia(tabla_grafo, 0, 1);
    insertarReferencia(tabla_grafo, 1, 2);
    insertarReferencia(tabla_grafo, 1, 3);
    insertarReferencia(tabla_grafo, 2, 5);
    insertarReferencia(tabla_grafo, 3, 4);
    insertarReferencia(tabla_grafo, 3, 5);
    insertarReferencia(tabla_grafo, 4, 5);
    insertarReferencia(tabla_grafo, 5, 6);
    insertarReferencia(tabla_grafo, 6, 2);

    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < 7; ++j){
            printf("%s\t", tabla_grafo[i][j] ? "TRUE" : "FALSE");
        }
        printf("\n");
    }
    caminoA(tabla_grafo, 0, 3);
}
 /*
// (tabla[i][j] < 10) ? 1 : 10;
int operadorTernario(bool a_evalue){
    if(a_evaluar){
        return 1;
    }
    else{
        return 10;
    }
}

char *operadoTernario(bool a_evaluar){
    if(tabla[0][1]){
        return "TRUE";
    }
    else{
        return "FALSE"
    }
}
*/
void caminoA(bool **tabla, int comienzo, int objetivo){
    printf("De %d a %d\n", comienzo, objetivo);
    int nodo_actual = comienzo;
    for(int i = 0; i < 7; ++i){
        if(tabla[nodo_actual][i]){
            printf("NODO %d camino a %d\n", nodo_actual, i);
            nodo_actual = i;
            if(nodo_actual == objetivo){
                printf("Nodo encontrado!\n");
                break;
            }
        }
    }
    printf("Nodo no encontrado\n");
    /*while(nodo_actual != objetivo){
        printf("Nodo no encontrado\n");
        return;
    }*/
}

void insertarReferencia(bool **tabla, int objetivo, int nodo){
    tabla[objetivo][nodo] = true;
}

void eliminarReferencia(bool **tabla, int objetivo, int nodo){
    tabla[objetivo][nodo] = false;
}