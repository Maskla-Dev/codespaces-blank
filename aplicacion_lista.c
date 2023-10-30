/*
    Lista de compras de supermercado
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char* nombre;
    float precio;
    int cantidad;
    struct nodo* siguiente;
}NODO;

void agregarProducto(NODO** lista, char* nombre, float precio, int cantidad);

void main(){
    int opcion = 0;
    NODO* lista = NULL;
    do{
        printf("1. Agregar producto\n");
        printf("2. Eliminar producto\n");
        printf("3. Mostrar lista\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            // Agregar producto
            case 1:
                printf("Nombre del producto: ");
                char* nombre = malloc(sizeof(char)*20);
                scanf("%s", nombre);
                printf("Precio del producto: ");
                float precio;
                scanf("%f", &precio);
                printf("Cantidad del producto: ");
                int cantidad;
                scanf("%d", &cantidad);
                agregarProducto(&lista, nombre, precio, cantidad);
                printf("Producto agregado\n");
                break;
            // Eliminar producto
            case 2:
                printf("Nombre del producto: ");
                char* nombre = malloc(sizeof(char)*20);
                scanf("%s", nombre);

                break;
            // Mostrar lista
            case 3:
                break;
            default:
                break;
        }
    }while(opcion != 4);
    printf("Adios\n");
}

void eliminarProducto(NODO** lista, char* nombre){
    NODO* aux = *lista;
    //Primer caso lista vacia
    if(aux == NULL){
        return;
    }
    // Segundo caso, lista con un solo elemento
    if(strcmp(aux->nombre, nombre) == 0){
        *lista = NULL;
        free(aux);
    }else{
        while(aux->siguiente != NULL){
            if(aux->siguiente->nombre == nombre){
                NODO* aux2 = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                free(aux2);
                return;
            }
            aux = aux->siguiente;
        }
    }
}

void agregarProducto(NODO** lista, char* nombre, float precio, int cantidad){
    NODO* nuevo = malloc(sizeof(NODO));
    nuevo->nombre = nombre;
    nuevo->precio = precio;
    nuevo->cantidad = cantidad;
    nuevo->siguiente = NULL;
    if(*lista == NULL){
        *lista = nuevo;
    }else{
        NODO* aux = *lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}