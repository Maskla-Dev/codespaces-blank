//Queue
typedef struct{
    int *arr;
    int TOPE;
    int MAX;
}COLA;

void queue_push(COLA* cola, int dato);
int queue_pop(COLA* cola);
int obtenerUltimoCola(COLA *cola);

typedef struct{
    int valor;
    bool bandera_correcto;
}OPERACION_POP;

void main(){
    //...
    operacion = pop(pila);
    if(operacion->bandera_correcto){
        //Bloque operacion exitosa
        printf("Valor de la pila %d\n", operacion->valor);
    }else{
        //Bloque operacion no exitosa
        printf("Nuestra pila vacia!\n");
    }
    
}

OPERACION_POP queue_pop(COLA* cola){
    OPERACION_POP resultado;
    if(cola != NULL){
        if(pila->TOPE != 0 && cola->arr != NULL){
            resultado->bandera_correcto = TRUE;
            resultado->valor = cola->arr[0];
            for(int i = 0; i < cola->TOPE - 1; ++i){
                cola->arr[i] = cola->arr[i + 1];
            }
            cola->TOPE -= 1;
            //return cola->arr[cola->TOPE];
            return resultado;
        }
    }
    resultado->bandera_correcto = FALSE;
    return resultado;
}

void queue_push(PILA* pila, int dato){
    if(pila == NULL)
        return;
    if(pila->TOPE == pila->MAX){
        return;
    }
    pila->arr[pila->TOPE++] = dato;
    // pila->TOPE += 1;
}

int obtenerUltimoCola(COLA *cola){
    OPERACION_POP resultado;
    if(pila != NULL){
        if(pila->TOPE != 0 && pila->arr != NULL){
            resultado->bandera_correcto = TRUE;
            resultado->valor = pila->arr[0];
            //return pila->arr[pila->TOPE];
            return resultado;
        }
    }
    resultado->bandera_correcto = FALSE;
    return resultado;
}