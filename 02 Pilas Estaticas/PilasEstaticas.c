/*
* Archivo que contiene las funciones de la pila
*/

#include "PilasEstaticas.h"

/** Crear pila*/
void createStack(Stack *s){
    s -> top = -1;
}

/** Insertar elemento */
bool push(StackEntry item, Stack *pila){
    if (stackFull(pila))
    	return false;
    else{
    	pila -> top++;
    	pila -> entry[pila -> top] = item;
    }
    return true;
}

/** Pila vacia */
bool stackEmpty(Stack *s){
    return s -> top < 0;
}

/** Pila llena */
bool stackFull(Stack *s){
    return s -> top > MAXSTACK;
}

/** Eliminar dato y retornarlo */
StackEntry pop(Stack *s){
	int aux;
    if (stackEmpty(s))
        printf("La Pila esta vacia\n");
    else{
    	aux = s -> entry[s -> top];
        s -> entry[s -> top]=0;
        s -> top--;
    }
    return aux;
}

/** Menu de opciones */
int menu(){
	int opc;
	printf("\nElija una opcion");
	printf("\n1. Insertar");
    printf("\n2. Eliminar");
    printf("\n3. Vaciar");
    printf("\n4. Cima");
    printf("\n5. Tamanio actual");
    printf("\n6. Imprimir");
    printf("\n7. Salir"); 

    printf("\n\nOpcion:\t");    
    scanf("%d",&opc);

    return opc;
}

void imprimir(Stack *s){
	int i;
	for (i = 0; i <= s -> top; i++){
		printf("\n_____");
		printf("\n| %d |",s->entry[i]);
	}
	printf("\n_____");
}
