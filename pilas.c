#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo* siguiente;
}NODO;

void push(NODO** inicio_pila, int dato);
void pop(NODO** inicio_pila);

void main(){
    //Pila FIFO
    NODO *inicio_pila = NULL;
    push(&inicio_pila, 10);
    NODO* primero = pop(&inicio_pila);
    printf("%d\n", primero->dato);
    free(primero);
}

void push(NODO** inicio_pila, int dato){
    NODO* nuevo = malloc(sizeof(NODO));
    nuevo->dato = dato;

    NODO* aux = *inicio_pila;
    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }
    aux.siguiente = nuevo;
}

NODO* pop(NODO* inicio_pila){
    NODO* dato_retirar, lista_temporal;
    if(inicio_pila == NULL){
        return;
    }
    if(inicio_pila.siguiente == NULL){
        dato_retirar = inicio_pila;
        inicio_pila = NULL;
        return dato_retirar;
    }
    lista_temporal = inicio_pila->siguiente;
    dato_retirar = inicio_pila;
    inicio_pila = lista_temporal;
    return dato_retirar;
}