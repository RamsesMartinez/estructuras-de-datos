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
    *L = (int*) malloc(sizeof(int));
}

/** Sets the size of the list */
void setSize(int **L, int size){
    /** Sets the new size of the list while preserving data */
    *L = NULL;
    *L = (int*) malloc(size*sizeof(int));
}

/** Prints the list */
void printList(int **L, int top){
    int  i;
    if(top < 0){
        printf("\n\t----------");
        printf("\n1.\t  NULL ");
        printf("\n\t----------");
        printf("\n\t  LISTA ");
        printf("\n\t----------\n");
    }else{
        for(i = top; i >= 0; i--){
            printf("\n\t----------");
            printf("\n\t%d.   %d   ", i+1, (*L)[i]);
        }
        printf("\n\t----------");
        printf("\n\t  LISTA ");
        printf("\n\t----------\n");
    }

}

/** Inserts an element in any position */
bool insert(int **L, int data, int pos, int *top, int size){
    int i;
    //If the list isn't full -> thera are at least one more space
    if(!isFull(size, *top)){
        // If is the first item in the list
        if(isEmpty(*top)){
            (*L)[0] = data;
            (*top)++;
            return true;
        }
        // If the position is less than or equal to top 
        else if(pos-1 <= *top && pos-1 >= 0 ){
            for(i = (*top)+1; i >= pos; i--){
                (*L)[i] = (*L)[i-1];
            }
            (*L)[pos-1] = data;
            (*top)++;
            return true;
        }
        // If the position is greater than the top
        else if (pos-1 > *top && pos-1 <= size){
            (*L)[*top+1] = data;
            (*top)++;
            return true;
        }
    }
    //If the list is full
    return false;
}

/** Inserts the element at the beginning of the list */
bool inStart(int **L, int data, int *top, int size){
    int i;
    //If the list isn't full -> thera are at least one more space
    if(!isFull(size, *top)){
        //If is the first item in the list
        if(isEmpty(*top)){
            (*L)[0] = data;
            (*top)++;
            return true;
        }
        // If the data isn't the first element
        else{
            for(i = (*top)+1; i >= 0; i--){
                (*L)[i] = (*L)[i-1];
            }
            (*L)[0] = data;
            (*top)++;
            return true;
        }

    }
    return false;
}

/** Inserts the element at the beginning of the list */
bool inEnd(int **L, int data, int *top, int size){
    //If the list isn't full -> thera are at least one more space
    if(!isFull(size, *top)){
        (*L)[(*top)+1] = data;
        (*top)++;
        return true;
    }
    return false;
}

/** Checks if the list is full */
bool isFull(int size, int top){
    if(top+1 == size)
        return true;
    else
        return false;
}

/** Checks if the list is empty */
bool isEmpty(int top){
    if(top == -1)
        return true;
    else
        return false;
}

/** If the data exists in the list returns its postion*/
int searchPosition(int** L, int data, int top){
    int i;
    for(i = 0;  i <= top; i++){
        if((*L)[i] == data){
            return i+1;
        }
    }
    return 0;
}

/** Returns its data given position*/
int searchData(int **L, int pos){
    return (*L)[pos-1];
}

/** Removes a data given position */
int removeData(int **L, int pos, int *top){
    int aux = (*L)[pos-1];
    int i;
    for(i = pos-1; i <= *top; i++){
        (*L)[i] = (*L)[i+1];
    }
    (*top)--;
    return aux;

}

/** Returns the option chosen by the user */
int menu(){
    int opc;
    printf("\nElija una opcion");
    printf("\n1. Crear nueva lista");
    printf("\n2. Agregar dato");
    printf("\n3. Insertar dato al inicio");
    printf("\n4. Insertar dato al final");
    printf("\n5. Buscar dato");
    printf("\n6. Buscar con posicion");
    printf("\n7. Borrar dato");
    printf("\n8. Salir");  
    printf("\n\nOpcion:\t");    
    scanf("%d",&opc);
    return opc;
}
