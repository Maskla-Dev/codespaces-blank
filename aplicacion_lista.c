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
void eliminarProducto(NODO** lista, char* nombre);
void mostrarListaProductos(NODO** lista);
void imprimirProducto(NODO* producto);

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
                eliminarProducto(&lista, nombre);
                break;
            // Mostrar lista
            case 3:
                printf("Lista de productos...\n");
                mostrarProductos(&lista);
                break;
            default:
                printf("Opcion no valida...\n");
                break;
        }
    }while(opcion != 4);
    printf("Adios\n");
}

void mostrarListaProductos(NODO** lista){
    NODO* aux = *lista;
    if(aux == NULL){
        printf("No hay productos que mostrar\n");
        return;
    }
    if(aux->siguiente == NULL){
        imprimirProducto(aux);
        return;
    }
    while(aux->siguiente != NULL){
        imprimirProducto(aux);
        aux = aux->siguiente;
    }
}

void imprimirProducto(NODO* producto){
    printf("Nombre: %s\tPrecio: %0.2f\tCantidad: %d\n", producto->nombre, producto->precio, producto->cantidad);
}

void eliminarProducto(NODO** lista, char* nombre){
    NODO* aux = *lista;
    NODO* aux1 = NULL;
    //Primer caso lista vacia
    if(aux == NULL){
        return;
    }
    // Segundo caso, lista con un solo elemento
    if(strcmp(aux->nombre, nombre) == 0){
        if(aux->siguiente == NULL){
            *lista = NULL;
            free(aux);
            aux = NULL;
        }
        else{
            *list = aux->siguiente;
            free(aux);
            aux = NULL;
        }
    }else{
        aux1=aux;
        aux=aux->siguiuente;

        while(aux->siguiente != NULL){
            if(strcmp(aux->nombre, nombre) == 0){
                break;
            }
            aux = aux->siguiente;
            aux1 = aux1->siguiente;
        }
        if(aux->siguiente == NULL){
            aux1->siguiente = NULL;
            free(aux);
            aux = NULL;
        }else{
            aux1->siguiente = aux->siguiente;
            free(aux);
            aux = NULL;
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