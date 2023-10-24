#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo* siguiente;
} NODO, NODOint;

typedef unsigned int Edad;

void agragarNuevoALista(NODO* lista, int dato);

int main(){
    int *arreglo_1 = malloc(sizeof(int)*4);
    arreglo_1 = realloc(arreglo_1, sizeof(int)*8);
    for(int i = 0; i < 8; ++i){
        printf("%d\n", i );
    }
    Edad edad_alberto = 10;
    printf("\n");
    NODOint lista;
    lista.dato = 10;
    lista.siguiente = malloc(sizeof(struct nodo));
    lista.siguiente->dato = 20;
    printf("%d\n", lista.dato);
    printf("%d\n", lista.siguiente->dato);
    NODO* lista_2 = malloc(sizeof(NODO));
    (*lista_2).dato = 10;
    printf("%d\n", lista_2->dato);
    agragarNuevoALista(lista.siguiente, 30);
    printf("%d\n", lista.siguiente->siguiente->datos);
    NODO* mi_dato = buscarEnLista(lista_1, 10);
    if(mi_dato != null){
        printf("Encontrado\n");
        mi_datos->dato = 100;
    }
    return 0;
}

NODO* buscarEnLista(NODO* lista, int dato){
    NODO* actual = lista;
    while (actual != null)
    {
        if(actual->dato == dato){
            return actual;
        }
        actual = actual->siguiente;
    }
    return null;
}

void quitarDeLista(NODO* lista){
    if(lista->siguiente == null){
        return;
    }
    if(lista->siguiente->siguiente != null) {
        NODO* aux = lista->siguiente;
        lista->siguiente = lista->siguiente->siguiente;
        free(aux);
    }else{
        free(lista->siguiente);
        lista.siguiete = null;
    }
}

void agragarNuevoALista(NODO* lista, int dato){
    NODO* nuevo = malloc(sizeof(NODO));
    nuevo->dato = dato;
    lista->siguiente = nuevo;
}