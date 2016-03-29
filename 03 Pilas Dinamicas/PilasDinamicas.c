 /**
* Archivo que contiene las funciones 
*/
/*void createStack(ptrNodoPila ptrPila){
    ptrPila = NULL;
}
*/
#include "PilasDinamicas.h"

/** Insertar un nuevo nodo */
void push(ptrNodoPila *ptrCima, int info){
    ptrNodoPila ptrNuevo; /** Apuntador al nuevo nodo */
    ptrNuevo = malloc(sizeof(NodoPila));

    /** Inserta el nuevo nodo encima de la pila */
    if(ptrNuevo != NULL){
        ptrNuevo -> dato = info;
        ptrNuevo -> ptrSiguiente = *ptrCima;
        *ptrCima = ptrNuevo;
    }else
        printf("%d No se inserto. Memoria insuficiente. \n",info);
}

/** Eliminar un nodo de la cima de la pila */
StackEntry pop(ptrNodoPila *ptrCima){
    ptrNodoPila ptrTemp; /** Apuntador a un nodo temporal */
    StackEntry valorElim; /* Valor del nodo */
    
    ptrTemp = *ptrCima;
    valorElim = ( *ptrCima )->dato;
    *ptrCima = ( *ptrCima ) -> ptrSiguiente;
    free(ptrTemp);
    return valorElim;
}

/**Imprimir la pila */
void printStack(ptrNodoPila ptrActual){
    /** Si la pila esta vacia. */
    if(ptrActual == NULL)
        printf("La pila esta vacia.\n\n");
    else{
        printf("La pila es: \n");

        /** Mientras no sea el final de la pila */
        while(ptrActual != NULL){
            printf("%d -> ",ptrActual -> dato);
            ptrActual = ptrActual -> ptrSiguiente;
        }
        printf("NULL\n\n");
    }
}

/**Devuelve true si la pila no esta vacia, de lo contrario retorna false */
bool delStack(ptrNodoPila ptrActual){
	return;
}

/** Devuelve true si la pila esta vacia, delo contrario false */
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
