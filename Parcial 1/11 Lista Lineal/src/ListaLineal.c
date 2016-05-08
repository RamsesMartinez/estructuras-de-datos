/**
* Name: ListaLineal.c
* Author: Ramses Martinez
* Version 1.0.0     08/05/2016
* Description: Archivo que contiene las funciones para el funcionamiento del TAD Lista Lineal
*/
#include "ListaLineal.h"

/** Creates a new list */
void createList(int **L){
    int i;
    *L = NULL;
    *L = (int*) malloc(sizeof(int)*(*size));
}

/** Sets the size of the list */
void setSize(int **L, int size){
    /** Sets the new size of the list while preserving data */
    *L = (int*) realloc(*L, (size)*sizeof(int));
}

/** Prints the list */
void printList(int **L, int size){
    int  i;
    if(size == 0){
        printf("\n\t--------");
        printf("\n\t  NULL ");
        printf("\n\t--------");
        printf("\n\t  LISTA ");
        printf("\n\t--------\n");
    }else{
        printf("\n\t--------");
        printf("\n\t  NULL ");
        for(i = 0; i < size; i++){
            printf("\n\t--------");
            printf("\n\t   %d   ", (*L)[i]);
        }
        printf("\n\t--------");
        printf("\n\t  LISTA ");
        printf("\n\t--------\n");
    }

}

/** Inserts an element in any position */
bool insert(int **L, int data, int pos, int top, int size){
    int i;
    if(isEmpty(&(*L), top){

    }
}

/** Checks if the list is empty */
bool isEmpty(int** L, int top){
    if(top == -1)
        return true;
    else
        return false;
}

/** Returns the option chosen by the user */
int menu(){
    int opc;
    printf("\nElija una opcion");
    printf("\n1. Crear Nueva Lista");
    printf("\n2. Agregar Dato");
    printf("\n3. Buscar Dato");
    printf("\n4. Buscar Posicion");
    printf("\n5. Borrar Dato");
    printf("\n6. Salir");  
    printf("\n\nOpcion:\t");    
    scanf("%d",&opc);
    return opc;
}
