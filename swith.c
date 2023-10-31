#include <stdio.h>

enum Casos{
    SALIR,
    ELIMNAR,
    AGREGAR,
    NO_SE
}

void main(){
    int opcion = 0;
    //Queremos ejecutar cierto codigo a partir de cierta condicion
    if(opcion == 4){
        printf("Estamos saliendo\n");
    }
    if(opcion == 3){
        printf("Estamos motrando\n");
    }
    if(opcion == 2){
        printf("Estamos eliminando\n");
    }
    if(opcion == 1){
        printf("Estamos agregando\n");
    }
    if(opcion == 0){
        printf("No se que estamos haciendo\n");
    }


    if(opcion == 4){
        printf("Estamos saliendo\n");
    }
    else if(opcion == 3){
        
    }
    else if(opcion == 2){

    }
    else if(opcion == 1){

    }
    else if(opcion == 0){

    }else{

    }

    switch(opcion){
        case ELIMINAR:
            printf("Estamos eliminando");
            break;
        case 1:
            printf("Estamos agregando");
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        default:

            break;
    }


}