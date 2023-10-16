/*
    El tipo de dato booleano es un tipo de dato que puede tener dos valores: verdadero o falso.
    En C no existe un tipo de dato booleano, por lo tanto, se utiliza el tipo de dato entero para representar un valor booleano.
    El valor 0 representa el valor falso y cualquier otro valor representa el valor verdadero.
 */

#include<string.h>
#include<stdio.h>
#include<stdbool.h>

void main(){
    if(0){
        // Nunca se ejecuta, ya que el valor 0 representa el valor falso, por lo tanto, la condicion es falsa
        printf("False\n");
    }
    if(1){
        // Siempre se ejecuta, ya que cualquier valor diferente de 0 representa el valor verdadero, por lo tanto, la condicion es verdadera
        printf("True\n");
    }
    // Ocurre lo mismo con la sentencia while

    /* NO DESCOMENTAR ESTE BLOQUE, YA QUE EL PROGRAMA NUNCA TERMINARA
        while(0){
            // Nunca se ejecuta, ya que el valor 0 representa el valor falso, por lo tanto, la condicion es falsa
            printf("False\n");
        }
        while(1){
            // Siempre se ejecuta, ya que cualquier valor diferente de 0 representa el valor verdadero, por lo tanto, la condicion es verdadera
            printf("True\n");
        }
    */

    // Utilizar 0 como falso y 1 como verdadero puede no ser muy intuitivo y complicar la legibilidad del codigo, 
    // Para mejorar eso se puede utilizar la libreria stdbool.h, que permite utilizar los valores true y false para representar valores booleanos
    // Para utilizar la libreria stdbool.h, se debe de utilizar el tipo de dato bool, que es un tipo de dato que puede tener dos valores: true o false
    bool verdadero = true;
    bool falso = false;
    if(falso){
        // Nunca se ejecuta, ya que el valor false representa el valor falso, por lo tanto, la condicion es falsa
        printf("False\n");
    }
    if(verdadero){
        // Siempre se ejecuta, ya que el valor true representa el valor verdadero, por lo tanto, la condicion es verdadera
        printf("True\n");
    }
    // Hay librerias que ofrecen utilidades para facilitar comparaciones entre elementos, por ejemplo la libreria string.h ofrece la funcion strcmp
    // Sin embargo, es importante verificar en la documentacion el comportamiento de la funcion, ya que no todas las funciones de comparacion devuelven
    // un valor booleano, por ejemplo, la funcion strcmp devuelve 3 valores posibles: 0, 1 o -1, donde 0 significa que las cadenas de texto son iguales,
    // 1 significa que la cadena de texto 1 es mayor que la cadena de texto 2 y -1 significa que la cadena de texto 1 es menor que la cadena de texto 2
    // Para este ejemplo, se va a utilizar la funcion strcmp para comparar dos cadenas de texto
    char *cadena1 = "Hola";
    char *cadena2 = "Hola";
    if(strcmp(cadena1, cadena2) == 0){
        // Siempre se ejecuta, ya que la funcion strcmp devuelve 0 si las cadenas de texto son iguales
        printf("Las cadenas de texto %s y %s son iguales\n", cadena1, cadena2);
    }
    // Para este ejemplo, se va a utilizar la funcion strcmp para comparar dos cadenas de texto
    char *cadena4 = "Hola mundo";
    if(strcmp(cadena4, cadena1) > 0){
        // Siempre se ejecuta, ya que la funcion strcmp devuelve 1 si la cadena de texto 1 es mayor que la cadena de texto 2
        printf("La cadena de texto %s es mayor que la cadena de texto %s\n", cadena4, cadena1);
    }
    // Para este ejemplo, se va a utilizar la funcion strcmp para comparar dos cadenas de texto
    if(strcmp(cadena1, cadena4) < 0){
        // Siempre se ejecuta, ya que la funcion strcmp devuelve -1 si la cadena de texto 1 es menor que la cadena de texto 2
        printf("La cadena de texto %s es menor que la cadena de texto %s\n", cadena1, cadena4);
    }
}