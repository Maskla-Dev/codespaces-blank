#include <stdio.h>

// Variables globales, los prototypes de las funciones y las constantes se guardan en la region global
int obtenerPromedio(int *materias);
int suma(int *a, int b);
int a;

void main(){
    // Cada variable tiene un espacio en memoria, y cada espacio en memoria tiene una dirección de memoria
    // La direccion de memoria obtenida a traves del programa es una direccion virtual, no es la real y la proporciona el sistema operativo
    // El sistema operativo gestiona la memoria para cada programa y cada programa tiene su propio espacio de memoria que se describen
    // en tablas
    // La memoria se divide en 4 partes:
    // 1. Codigo: Es la parte del programa que se va a ejecutar
    // 2. Global: Son las variables globales y estaticas
    // 3. Heap: Es la memoria dinamica, es decir, la memoria que se solicita en tiempo de ejecucion
    // 4. Stack: Es la memoria que se utiliza para las funciones, es decir, las variables locales y los parametros de las funciones
    // Cada variable que cuenta con identificador o nombre entra en la region stack
    int variable; // Variable local, se guarda en la region stack
    
    // Las variables que no tienen identificador se guardan en la region heap
    // Variables sin identificador son necesarias cuando al utilizar memoria dinamica, es decir, cuando no se sabe
    // con certeza si la variable va a ser utilizada o no, por lo tanto, solo se crea cuando se necesita

    // La función malloc sirve para solicitar memoria dinamica, si se hiciera una traducción de malloc sería:
    // "Quiero guardar en la región heap un dato de tamaño X"
    
    // Cuando malloc completa la tarea satisfactoriamente devuelve la dirección de memoria (virtual) donde se guardó el dato
    // Malloc falla cuando hay errores criticos en el sistema operativo, por ejemplo, cuando no hay memoria disponible
    // Cuando malloc falla devuelve NULL, de manera profesional, es necesario asumir la posibilidad de que las cosas fallen y 
    // proveer la capacidad del programa de manejar esas fallas lo mejor posible
    printf("%d\n", malloc(sizeof(int)));
    // Dado que malloc solo devuelve la direción de memoria, si esta se utiliza y no se guarda, se pierde la referencia
    // y por lo tanto la posibilidad de volver a utilizar esa información contenida
    // Para evitar esto, es necesario guardar la dirección de memoria en una variable, las variables que guardan direcciones
    // de memoria se llaman punteros y se declaran con el operador *, si se hiciera una traducción de la declaración de un puntero
    // seria: "Quiero guardar en la región stack una dirección de memoria cuyo contenido es un dato de tipo X"
    int* variable_en_heap1 = malloc(sizeof(int));   // Si traducimos esta linea seria: "Quiero guardar datos en la región heap que ocupen el tamaño de un int 
                                                    // y quiero guardar la referencia de ese dato en la región stack"
    // Las variables de tipo puntero solo pueden guardar direcciones de memoria, por lo tanto, para acceder a la información a la que apunta, es necesario
    // utilizar el operador *, si se hiciera una traducción de la siguiente linea seria: "Quiero acceder al dato que se encuentra en la dirección de memoria
    // identificada por la variable variable_en_heap1"
    printf("%d\n", *variable_en_heap1);
    *variable_en_heap1 = 10;    // En esta linea con el operador * se accede al contenido del dato,
                                // una vez accedido al dato se puede hacer lo que se quiera con el, por ejemplo, una asignaci?on
    printf("%d\n", *variable_en_heap1);
    int *variable_en_heap2 = malloc(sizeof(variable));
    int *variable_en_heap3 = variable_en_heap1; // En esta linea se copia la dirección de memoria de la variable_en_heap1 en la variable_en_heap3 (ambas son punteros)
    printf("%d\n", *variable_en_heap3); // Verificación que ambas apuntan al mismo dato
    // Toda variable con identificador tambien tiene una dirección de memoria asociada, para acceder a esa dirección de memoria se utiliza el operador &
    // En cuanto a punteros, se pueden anidar punteros, es decir, un puntero puede apuntar a otro puntero, y este a otro y asi sucesivamente
    int **puntero_de_punteros = &variable_en_heap1; // En esta linea se apunta a la dirección de memoria de un dato tipo puntero,
                                                    // La traducción de esta linea seria: "Quiero guardar en la región stack una dirección de memoria (primer *) 
                                                    // cuyo contenido es un dato de tipo puntero (segundo *)"
    printf("%d\n", *(*puntero_de_punteros)); // En esta linea se accede al contenido del dato al que apunta el puntero_de_punteros, que es un puntero,
                                            // y luego se accede al contenido del dato al que apunta el puntero al que apunta el puntero_de_punteros
                                            // La traducción de esta linea seria: "Quiero acceder al dato que se encuentra en la dirección de memoria
                                            // identificada por la variable puntero_de_punteros, luego quiero acceder al dato que se encuentra en la dirección
                                            // de memoria identificada por el dato al que apunta el puntero_de_punteros"
    int ***puntero_de_punteros_de_punteros = &puntero_de_punteros; // Como se ha mencionado, existen punteros de punteros de punteros de punteros...
    // Dado que las direcciones de memoria son numeros, se pueden hacer operaciones con ellas, por ejemplo, sumar o restar o incluso multiplicar,
    // no hay restricción de ello siempre y cuando no se intente acceder a una dirección de memoria que no pertenece al programa, en ese caso el sistema operativo
    // mata el programa
    /* El PROGRAMA FALLARA SI DESCOMENTA, EJEMPLO DE ACCESO A DIRECCIONES DE MEMORIA QUE NO PERTENECEN AL PROGRAMA
        variable_en_heap1 = 0;
        *variable_en_heap1 = 100; // Se intenta acceder a la dirección de memoria 0, que no pertenece al programa
        printf("%d\n", *variable_en_heap1); // Si no existiera el sistema operativo, el valor original de variable_en_heap1 seguiria siendo 10 y el valor 100 pertenece a la
                                            // dirección de memoria 0
    */

    // malloc intentara encontrar un espacio en memoria que cumpla con el tamaño solicitado y la acomodara de manera contigua
    // aprovechando este hecho, es como se definen los arreglos dinamicos, es decir, arreglos cuyo tamaño se define en tiempo de ejecución
    int* arreglo_dinamico = malloc(sizeof(int)*3); // Arreglo dinamico de 3 elementos
    // Con la aritmética de punteros se puede acceder a los elementos del arreglo recorriendo el valor del puntero segun se necesite a traves del arreglo
    *(arreglo_dinamico + 0) = 1;
    // La linea anterior es lo mismo que la siguiente linea
    arreglo_dinamico[0] = 1;
    *(arreglo_dinamico + 1) = 2;
    // La linea anterior es lo mismo que la siguiente linea
    arreglo_dinamico[1] = 2;
    // Se simplifica la notación de acceso de arreglos dinamicos utilizando corchetes
    arreglo_dinamico[2] = 3;
    // Cuidado con el acceso a arreglos dinamicos, si se intenta acceder a un elemento que no existe, el sistema operativo mata el programa
    // *(arreglo_dinamico + 3) = 1; // El sistema operativo solo nos dio un bloque de 3 posiciones de memoria, por lo tanto, solo podemos acceder a las posiciones 0, 1 y 2
}

// Los stack frames son una manera de organizar la memoria de la region stack, cada vez que se llama a una función, se crea un stack frame
// y se guarda en la region stack, el stack frame contiene la información de la función, por ejemplo, los parametros, las variables locales
// a esto se le conoce como el contexto de la función, el stack frame se crea en la parte superior de la region stack y se destruye cuando
// la función termina de ejecutarse, es decir, cuando se llega a la llave de cierre de la función
int obtenerPromedio(int *materias){
    // Las variables c, d y materias son pertenecientes a este contexto, fuera de este contexto no existen, sin embargo, las
    // variables globales si pueden ser accedidas desde este contexto
    int c;
    int d = suma(c, d);
}

int suma(int *a, int b){
    // Las variables a, b y c son pertenecientes a este contexto, nota que para cada contexto,
    // variables con mismo identificador son diferentes. La condicion de utilzar variables con mismo
    // identificador es que no se encuentren en el mismo contexto
    int c;
    return *a + b;
}

