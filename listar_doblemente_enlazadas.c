#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo *siguiente;
    struct Nodo *anterior;
}Nodo;

void insertar(Nodo* nodo1, Nodo* nodo2){
    if (nodo1 == NULL || nodo2 == NULL ){
        return;
    }
    if(nodo1->anterior == NULL){
        //Es cuando se inserta en el primer lugar
        nodo2->anterior = NULL;
        nodo2->siguiente = nodo1;
        nodo1->anterior = nodo2;
    }
    else if(nodo1->siguiente == NULL){
        nodo1->siguiente = nodo2;
        nodo2->anterior = nodo1;
        nodo2->siguiente = NULL;
    }else{
        //Insercion antes del nodo objetivo
        nodo1->anterior->siguiente = nodo2;
        nodo2->anterior = nodo1->anterior;
        nodo2->siguiente = nodo1;
        nodo1->anterior = nodo2;
        //Insercion despues del nodo objetivo 
        nodo1->siguiente->anterior = nodo2;
        nodo2->siguiente = nodo1->siguiente;
        nodo2->anterior = nodo1;
        nodo1->siguiente = nodo2;
    }
}