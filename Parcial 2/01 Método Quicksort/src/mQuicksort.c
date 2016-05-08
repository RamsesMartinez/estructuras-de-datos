/**
* Name: mQuicksort.c
* Author: Ramses Martinez
* Version 1.1.0     08/05/2016
* Decription: Programa para ordena un conjunto de numeros utilizando el metodo Quicksort
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
int opc,tam;
char cont = 's';
int* lista;

while(cont == 's' || cont == 'S'){
    switch(opc = menu()){
        /** Crea una lsita de enteros */
        case 1:
            crearLista(&lista,&tam);
        break;
        /** Realiza el metodo Quicksort */
        case 2:
            quicksort(&lista, 0, tam-1);
            printf("Quicksort completado!\n");
        break;
        /** Muestra la lista en el momento actual */
        case 3:
            mostrarLista(&lista,tam);
        break;
        /** finaliza el programa */
        case 4:
            printf("Hasta luego! :)\n");
            cont = 'n';
        break;
        default:
            printf("Opcion invalida\n");
        break;
    }
}

return 0;
}


