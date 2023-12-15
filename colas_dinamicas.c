typedef struct NODO{
    int valor;
    struct NODO* siguiente;
}NODO;

typedef struct COLA{
    NODO* inicio_cola;
}COLA;

void pushQueue(COLA *cola, int valor);
NODO *popQueue(COLA *cola);
int primeroQueue(COLA *cola);

void pushQueue(COLA *cola, int valor){
    NODO *actual = cola->inicio_cola;
    //Comprobar antes validez de referencias
    NODO *nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->valor = valor;
    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
}

NODO *popQueue(COLA *cola){
    //Comprobar validez de referencias
    NODO *actual = cola->inicio_cola;
    cola->inicio_cola = actual->siguiente
    actual->siguiente = NULL;
    return actual;
}

int primeroQueue(COLA *cola){
    //Comprobar validez de referencias
    return cola->inicio_cola->valor;
}
