typedef struct NODO{
    int valor;
    struct NODO* siguiente;
}NODO, INICIO_PILA;

void push(INICIO_PILA *pila, int valor);
NODO *pop(INICIO_PILA *pila);
int ultimo(INICIO_PILA *pila);

void push(INICIO_PILA *pila, int valor){
    NODO *actual = pila;
    if(pila != NULL){
        NODO *nuevo = (NODO*)malloc(sizeof(NODO));
        nuevo->valor = valor;
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

NODO *pop(INICIO_PILA *pila){
    NODO *actual = pila;
    NODO *aux = actual->siguiente;
    if(aux != NULL){
        while(aux->siguiente != NULL){
            actual = aux;
            aux = aux->siguiente;
        }
        actual->siguiente = NULL;
        return aux;
    }
    return actual;
}

int ultimo(INICIO_PILA *pila){
    NODO *actual = pila;
    NODO *aux = actual->siguiente;
    if(aux != NULL){
        while(aux->siguiente != NULL){
            actual = aux;
            aux = aux->siguiente;
        }
        return aux->valor;
    }
    return actual->valor;
}