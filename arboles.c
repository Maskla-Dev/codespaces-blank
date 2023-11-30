#include <stdio.h>
#include <stdlib.h>
#incldue <stdbool.h>

typedef struct{
    char *nombre;
    float promedio;
}Alumno;

typedef struct Arbol{
    NodoArbol *raiz;
    size_t n;
}Arbol;

typedef struct NodoBinario{
    int valor;
    struct NodoBinario *izq;
    struct NodoBinario *der;
}

typedef struct Nodo{
    int valor;
    struct Nodo **nodos_hijos;
}NodoArbol;

typedef unsigned long long int size_t;

Arbol *crearArbol(size_t numero_hijos);
NodoArbol *crearNodo(int valor, size_t numero_hijos);
bool agregarAlArbol(Arbol* arbol, int valor, int *objetivo);
NodoArbol *buscar(NodoArbol* nodo, int valor, size_t n);
bool insertarEn(NodoArbol *padre, NodoArbol* hijo, size_t n);
//int *arreglo;
//arreglo[0];

void main(){
    struct Nodo primernodo, segundonodo;
    primernodo->nodo = &segundonodo;
}

NodoArbol *crearNodo(int valor, size_t numero_hijos){
    NodoArbol *nodo;
    if(numero_hijos > 1){
        nodo = (NodoArbol*)malloc(sizeof(NodoArbol));
        nodo->valor = valor;
        nodo->nodos_hijos = (NodoArbol**)malloc(sizeof(NodoArbol*) * numero_hijos);
        return nodo;
    }
    return NULL;
}

Arbol *crearArbol(size_t numero_hijos){
    Arbol* arbol;
    /*
    long int i = 0;
    int j = (int)i;
    i = (long int)j;
    float k = (float)j;
    j = (int)k;
    double p = (double)k;
    */
    //(void*)
    if(numero_hijos > 1){
        arbol = (Arbol*)malloc(sizeof(Arbol));
        arbol->n = numero_hijos;
        return arbol;
    }
    return NULL;
}

bool agregarAlArbol(Arbol* arbol, int valor, int *objetivo){
    if(arbol == NULL){
        return FALSE;
    }
    NodoArbol *nuevonodo = crearNodo(valor, arbol->numero_hijos);*objetivo
    if(objetivo == NULL){
        if(arbol->raiz == NULL){
            arbol->raiz = nuevonodo;
            return true;
        }
    }else{
        NodoArbol *nodoobjetivo = buscar(arbol->raiz, *objetivo, arbol->n);
        if(nodoobjetivo != NULL){
            if(insertarEn(nodoobjetivo, nuevonodo, arbol->n)){
                return TRUE;
            }
        }
    }
    eliminarNodo(nuevonodo);
    return FALSE;
}

NodoArbol *buscar(NodoArbol* nodo, int valor, size_t n){
    if(nodo != NULL){
        if(nodo->valor == valor){
            return nodo;
        }
        NodoArbol *hijo;
        for(int i = 0; i < n; ++i){
            hijo = buscar(nodo->nodos_hijos[i], valor);
            if(hijo != NULL)
                return hijo;
        }
    }
    return NULL;
}

bool insertarEn(NodoArbol *padre, NodoArbol* hijo, size_t n){
    if(padre != NULL && hijo != NULL){
        for(int i = 0; i < n; ++i){
            if(padre->nodos_hijos[i] == NULL){
                padre->nodos_hijos[i] == hijo;
                return TRUE;
            }
        }
    }
    return FALSE;
}