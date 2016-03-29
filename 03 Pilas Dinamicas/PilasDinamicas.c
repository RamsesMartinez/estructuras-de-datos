 /**
* Archivo que contiene las funciones 
*/
/*void createStack(ptrNodoPila ptrPila){
    ptrPila = NULL;
}
*/
#include "PilasDinamicas.h"

/** Insertar un nuevo nodo */
void push(ptrNodoPila *ptrCima, int entry){
    ptrNodoPila ptrNuevo; /** Apuntador al nuevo nodo */
    ptrNuevo = malloc(sizeof(NodoPila));

    /** Inserta el nuevo nodo encima de la pila */
    if(ptrNuevo != NULL){
        ptrNuevo -> entry = entry;
        ptrNuevo -> ptrSiguiente = *ptrCima;
        *ptrCima = ptrNuevo;
    }else{
        printf("%d No se inserto. Memoria insuficiente. \n",entry);
    }
} 

/** Eliminar un nodo de la cima de la pila */
StackEntry pop(ptrNodoPila *ptrCima){
    ptrNodoPila ptrTemp; /** Apuntador a un nodo temporal */
    StackEntry valorElim; /* Valor del nodo */
    
    ptrTemp = *ptrCima;
    valorElim = ( *ptrCima )-> entry;
    *ptrCima = ( *ptrCima ) -> ptrSiguiente;
    free(ptrTemp);
    return valorElim;
}

/**Imprimir la pila */
void printStack(ptrNodoPila ptrActual){
    if (ptrActual == NULL){
        printf("\n\t--------");
        printf("\n\t| NULL |");
        printf("\n\t--------");
        printf("\n\t| PILA |");
        printf("\n\t--------\n");
    }else{
        printf("\n\t--------");
        printf("\n\t| NULL |");
        /**Mientras no sea el final de la pila*/
        while(ptrActual != NULL){
            printf("\n\t--------");
            printf("\n\t|  %d   |", ptrActual -> entry);
            ptrActual = ptrActual -> ptrSiguiente;
        }
        printf("\n\t--------");
        printf("\n\t| PILA |");
        printf("\n\t--------\n");
    }
}

/** Elimina toda la pila */
void delStack(ptrNodoPila *ptrActual){
    while(!stackEmpty(*ptrActual)){
        StackEntry aux = pop(ptrActual);
    }
}

/** Devuelve true si la pila esta vacia, de lo contrario false */
bool  stackEmpty(ptrNodoPila ptrCima){
    return ptrCima == NULL;
}
 
int menu(){
    int opc;
    printf("\nElija una opcion");
    printf("\n1. Insertar");
    printf("\n2. Eliminar");
    printf("\n3. Vaciar");
    printf("\n4. Cima");
    printf("\n5. Tamanio actual");
    printf("\n6. Salir");  

    printf("\n\nOpcion:\t");    
    scanf("%d",&opc);

    return opc;
}
