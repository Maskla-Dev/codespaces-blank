/*
    La busqueda indexada es una tecnica de busqueda que se utiliza cuando la cantidad de datos es muy grande. El mecanismo es similar a la forma en la
    que se busca un tema en un libro. Primero se busca el tema en el indice del libro, si se encuentra el tema en el indice, se obtiene el numero de pagina
    en donde comenzar a buscar la informacion de interes.
    La busqueda indexada consiste en crear un indice de busqueda, el cual es una lista ordenada de los datos que se van a buscar.
    El indice de busqueda se crea una sola vez, cuando se crea la lista de datos.
    Cuando se requiere buscar un dato, primero se busca en el indice de busqueda, si se encuentra el dato en el indice, se obtiene el rango de 
    busqueda en la lista de datos. Una vez obtenido se puede utilizar la busqueda binaria o busqueda secuencial para buscar el dato en la lista de datos.
    De esta manera se reduce el tiempo de busqueda.
*/
#include <stdio.h>
#include <string.h>

struct Personal{
    char *identificador;
    char nombre[20];
    char apellido[20];
    int edad;
    float salario;
};

// El indice requiere un identificador, puede ser un caracter, un numero o una cadena de texto; esto dependera del tipo de
// problema a resolver
struct Indice{
    char letra;
    int cantidad_elementos;
};

struct Rango{
    unsigned int inicio;
    unsigned int fin;
};

struct Rango obtenerRango(struct Indice indice[26], char letra);
int buscar(struct Personal lista[], unsigned int inicio, unsigned int fin, char *identificador);
void usarDatosEmpleado(struct Personal empleado);
struct Rango obtenerRangoSinStructura(int indice[26], char letra);

void main(){
    //Primero se define el indice de busqueda
    struct Indice indice[26] = {
        {.letra = 'A', .cantidad_elementos = 100},
        {.letra = 'B', .cantidad_elementos = 200},
        {.letra = 'C', .cantidad_elementos = 100},
        {.letra = 'D', .cantidad_elementos = 200},
        {.letra = 'E', .cantidad_elementos = 100},
        {.letra = 'F', .cantidad_elementos = 200},
        {.letra = 'G', .cantidad_elementos = 100},
        {.letra = 'H', .cantidad_elementos = 200},
        {.letra = 'I', .cantidad_elementos = 100},
        {.letra = 'J', .cantidad_elementos = 200},
        {.letra = 'K', .cantidad_elementos = 100},
        {.letra = 'L', .cantidad_elementos = 200},
        {.letra = 'M', .cantidad_elementos = 100},
        {.letra = 'N', .cantidad_elementos = 200},
        {.letra = 'O', .cantidad_elementos = 100},
        {.letra = 'P', .cantidad_elementos = 200},
        {.letra = 'Q', .cantidad_elementos = 100},
        {.letra = 'R', .cantidad_elementos = 200},
        {.letra = 'S', .cantidad_elementos = 100},
        {.letra = 'T', .cantidad_elementos = 200},
        {.letra = 'U', .cantidad_elementos = 100},
        {.letra = 'V', .cantidad_elementos = 200},
        {.letra = 'W', .cantidad_elementos = 100},
        {.letra = 'X', .cantidad_elementos = 200},
        {.letra = 'Y', .cantidad_elementos = 100},
        {.letra = 'Z', .cantidad_elementos = 200},
    };
    // Se define la lista de datos
    struct Personal empleados[3900];
    // A partir de este punto, se debe de obtener un dato a buscar, en el mundo real puede ocurrir de diversas formar, por ejemplo, se puede obtener
    // el dato a buscar desde un archivo, desde un lector de tarjetas, desde los datos introducidos por el usuario, etc.
    //Para esta ocasion se va a utilizar un dato fijo
    char *identificador_a_buscar = "A0001";
    empleados[0].identificador = identificador_a_buscar;
    strcpy(empleados[0].nombre, "Jose");
    strcpy(empleados[0].apellido, "Lopez");
    
    // Una vez obtenido el dato, hay que determinar el rango de busqueda de la lista de datos
    struct Rango rango = obtenerRango(indice, identificador_a_buscar[0] /*Una cadena de texto es un arreglo, para este ejemplo solo interesa la primer posicion, esto cambia segun el problema*/);
    // ¿Que pasaria si el identificador del indice no se encuentra?
    // Dado nuestro algoritmo de busqueda del indice, si el identificador no se encuentra, el rango de busqueda sera 0
    //es decir rango.fin - rango.inicio = 0, por lo tanto, no se realizara la busqueda en la lista de datos
    if(rango.fin - rango.inicio == 0){
        printf("El empleado no se encuentra en la lista\n");
        return; // si no expecifica un valor en la sentencia return, no se devuelve algun valor pero si termina la ejecucion de la funcion.
    }

    // Una vez obtenido el rango de busqueda, se puede utilizar la busqueda binaria o busqueda secuencial para buscar el dato en la lista de datos
    unsigned int posicion = buscar(empleados, rango.inicio, rango.fin, identificador_a_buscar);
    if(posicion != -1){
        //Una vez obtenido el indice, es posible hacer cualquier operacion con el dato, ya sea modificarlo, eliminarlo o enviarlo a otra funcion
        printf("El empleado se encuentra en la posicion %d\n", posicion);
        usarDatosEmpleado(empleados[posicion]);
        printf("\n");
    } else{
        printf("El empleado no se encuentra en la lista\n");
    }

    //Es posible omitir usar una estructura indice e indicar la cantidad de datos directamente de la siguiente manera
    int indice_enteros[26] = {
        100, // A
        200, // B
        100, // C
        200, // D
        100, // E
        200, // F
        100, // G
        200, // H
        100, // I
        200, // J
        100, // K
        200, // L
        100, // M
        200, // N
        100, // O
        200, // P
        100, // Q
        200, // R
        100, // S
        200, // T
        100, // U
        200, // V
        100, // W
        200, // X
        100, // Y
        200, // Z
    };
    // En este caso, la funcion obtenerRango debe de ser modificada para que reciba un arreglo de enteros en lugar de una estructura
    rango = obtenerRangoSinStructura(indice_enteros, identificador_a_buscar[0] /*Una cadena de texto es un arreglo, para este ejemplo solo interesa la primer posicion, esto cambia segun el problema*/);
    usarDatosEmpleado(empleados[buscar(empleados, rango.inicio, rango.fin, identificador_a_buscar)]);
}

struct Rango obtenerRango(struct Indice indice[26], char letra){
    struct Rango rango;
    unsigned int inicio = 0;
    unsigned int fin = 0;
    //Recorre el indice de busqueda hasta encontrar el identificador
    for(int i = 0; i < 26; i++){
        // Si el identificador se encuentra en el indice, se actualiza el limite superior del rango, se sale del ciclo por que no interesa seguir buscando
        if(indice[i].letra == letra){
            fin = indice[i].cantidad_elementos;
            break; // break es una instruccion que permite salir de un ciclo sin importar si se cumple o no la condicion del ciclo
        }
        // Cada iteracion, se actualiza el limite inferior del rango
        inicio += indice[i].cantidad_elementos;
    }
    rango.inicio = inicio;
    rango.fin = fin;
    return rango;
}

int buscar(struct Personal lista[], unsigned int inicio, unsigned int fin, char *identificador){
    // Utilizando la busqueda secuencial para buscar el dato en la lista de datos
    int posicion = -1;
    for(int i = inicio; i < fin; i++){
        if(strcmp(lista[i].identificador, identificador) == 0){
            posicion = i;
            break;
        }
    }
    // Si el dato se encuentra, la variable posicion tendra el valor de la posicion del dato en la lista de datos, caso contrario se devuelve -1
    return posicion;
}

void usarDatosEmpleado(struct Personal empleado){
    printf("Nombre: %s\n", empleado.nombre);
    printf("Apellido: %s\n", empleado.apellido);
    printf("Edad: %d\n", empleado.edad);
    printf("Salario: %.2f\n", empleado.salario);
}

struct Rango obtenerRangoSinStructura(int indice[26], char letra){
    struct Rango rango;
    unsigned int inicio = 0;
    unsigned int fin = 0;
    for(int i = 0; i < 26; i++){
        // Se aprovecha el codigo ASCII para obtener el identificador del indice, por ejemplo, la letra A tiene el valor de 65 en codigo ASCII
        if((letra % 65) == i){
            fin = indice[i];
            break;
        }
        inicio += indice[i];
    }
    rango.inicio = inicio;
    rango.fin = fin;
    return rango;
}