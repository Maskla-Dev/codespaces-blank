//Stack
typedef struct{
    int *arr;
    int TOPE;
    int MAX;
}PILA;

void push(PILA* pila, int dato);
int pop(PILA* pila);
int obtenerUltimo(PILA *pila);

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

OPERACION_POP pop(PILA* pila){
    OPERACION_POP resultado;
    if(pila != NULL){
        if(pila->TOPE != 0 && pila->arr != NULL){
            resultado->bandera_correcto = TRUE;
            resultado->valor = pila->arr[--pila->TOPE];
            /*pila->TOPE -= 1;
            return pila->arr[pila->TOPE];*/
            return resultado;
        }
    }
    resultado->bandera_correcto = FALSE;
    return resultado;
}

void push(PILA* pila, int dato){
    if(pila == NULL)
        return;
    if(pila->TOPE == pila->MAX){
        return;
    }
    pila->arr[pila->TOPE++] = dato;
    // pila->TOPE += 1;
}

int obtenerUltimo(PILA *pila){
    OPERACION_POP resultado;
    if(pila != NULL){
        if(pila->TOPE != 0 && pila->arr != NULL){
            resultado->bandera_correcto = TRUE;
            resultado->valor = pila->arr[pila->TOPE - 1];
            /*pila->TOPE -= 1;
            return pila->arr[pila->TOPE];*/
            return resultado;
        }
    }
    resultado->bandera_correcto = FALSE;
    return resultado;
}