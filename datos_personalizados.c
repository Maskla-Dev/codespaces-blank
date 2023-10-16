/*
    El lenguaje de programacion C permite definir tipos de datos personalizados para que el programador pueda
    crear código más legible y fácil de mantener. Estos tipos de datos personalizados son las enumeraciones y
    las estructuras.
*/

#include <stdio.h>
#include <string.h>
// Las enumeraciones son un tipo de dato que permite definir un conjunto de constantes con nombre.
// Las enumeraciones son listas, donde cada elemento de la lista tiene un valor entero asociado. Por defecto
// el primer elemento de la lista tiene el valor 0, el segundo el valor 1 y así sucesivamente. El programador
// puede asignar valores a cada elemento de la lista.

// Como buena practica de programacion, las constantes se definen en mayusculas, por lo tanto, cada elementos
// de la lista de la enumeracion se define en mayusculas.
enum EstadoEmpleado{
    ACTIVO, // 0
    BAJA, // 1
    VACACIONES, // 2
    INCAPACITADO, // 3
    DESPEDIDO = 99, // 99, se puede romper la secuencia de valores al asignar una constante
    JUBILADO // 100
};

//Las estructuras son tipos de datos personalizados, agrupan varios tipos de datos en una sola variable
//Se definen con la palabra reservada struct seguida del nombre de la estructura y entre llaves los tipos de datos que agrupa
//Se puede definir una variable de tipo estructura de la siguiente manera:
struct Personal{
    // Tipo de dato e identificador de campo
    char nombre[20];
    char apellido[20];
    int edad;
    float salario;
    // Se puede definir una variable de tipo enumeracion dentro de una estructura, de la siguiente manera:
    enum EstadoEmpleado estado;
};

void imprimirInformacionEmpleado(struct Personal empleado);
char* obtenerEstadoEmpleado(enum EstadoEmpleado estado);

void main(){
    // No es necesario escribir la palabra reservada enum para declarar una variable de tipo enumeracion
    printf("Valor para Activo: %d\n", ACTIVO);
    printf("Valor para Baja: %d\n", BAJA);
    printf("Valor para Vacaciones: %d\n", VACACIONES);
    printf("Valor para Incapacitado: %d\n", INCAPACITADO);
    printf("Valor para Despedido: %d\n", DESPEDIDO);
    printf("Valor para Jubilado: %d\n", JUBILADO);
    printf("\n");

    // Se puede definir una variable de tipo estructura de la siguiente manera:
    struct Personal empleado1;
    // Se puede asignar valores a los campos de la estructura de la siguiente manera:
    empleado1.edad = 30;
    empleado1.salario = 1000.50;
    empleado1.estado = ACTIVO;
    // Si se utiliza esta forma, para cadenas de texto es necesario utilizar la funcion strcpy de la libreria string.h
    strcpy(empleado1.nombre, "Jose");
    // strcpy es una funcion que permite copiar una cadena de texto a otra cadena de texto, recibe dos parametros, el primero es la cadena de texto destino (contenedor de la copia)
    // y el segundo es la cadena de texto origen (texto a copiar)
    strcpy(empleado1.apellido, "Lopez");

    // Se puede asignar valores a los campos de la estructura de la siguiente manera:
    struct Personal empleado2 = {"Juan", "Perez", 25, 2000.50, ACTIVO};
    // Se puede asignar valores a los campos de la estructura de la siguiente manera:
    struct Personal empleado3 = {.nombre = "Pedro", .apellido = "Gomez", .edad = 35, .salario = 3000.50, .estado = BAJA};

    // Cada vez que se quiere acceder al valor de un campo de la estructura se debe usar el operador punto (.), seguido del nombre del campo
    printf("Nombre: %s\n", empleado1.nombre);
    printf("Apellido: %s\n", empleado1.apellido);
    printf("Edad: %d\n", empleado1.edad);
    printf("Salario: %.2f\n", empleado1.salario);
    // Las enumeraciones son representaciones numericas, por lo que, si se quiere obtener texto, es necesario apoyarse de una funcion que 
    // convierta el valor numerico a texto (la debe de construir el programador)
    printf("Estado: %d\n", empleado1.estado);
    printf("\n");
    // Recuerda el dicho DRY (Don't Repeat Yourself), por lo que, si se quiere imprimir los datos de varios empleados, es mejor usar una funcion
    // para no repetir codigo
    imprimirInformacionEmpleado(empleado1);
    imprimirInformacionEmpleado(empleado2);
    imprimirInformacionEmpleado(empleado3);
    
    // Recuerda que la asignacion a tipos de dato enum, se puede hacer de manera directa sin pasar por el identificador,
    // Por lo que se puede asignar un valor numerico que no este listado es posible
    struct Personal empleado4 = {"Maria", "Gonzalez", 40, 4000.50, 80}; // 80 no esta listado en la enumeracion pero es posible asignarlo
    imprimirInformacionEmpleado(empleado4);
}

void imprimirInformacionEmpleado(struct Personal empleado){
    printf("Nombre: %s\n", empleado.nombre);
    printf("Apellido: %s\n", empleado.apellido);
    printf("Edad: %d\n", empleado.edad);
    printf("Salario: %.2f\n", empleado.salario);
    printf("Estado: %s\n", obtenerEstadoEmpleado(empleado.estado));
    printf("\n");
}

// char* es un apuntador, de manera general tambien representa una cadena de texto
char* obtenerEstadoEmpleado(enum EstadoEmpleado estado){
    switch(estado){
        case ACTIVO:
            return "Activo";
        case BAJA:
            return "Baja";
        case VACACIONES:
            return "Vacaciones";
        case INCAPACITADO:
            return "Incapacitado";
        case DESPEDIDO:
            return "Despedido";
        case JUBILADO:
            return "Jubilado";
        default:
            return "Estado no definido";
    }
}